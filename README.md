#  Card Game Framework

## Build Instructions

Used  `CLion IDE ` but you can compile using `g++ <file_names.cpp> -g `

```
g++ src/Player.cpp src/CardCollection.cpp src/Card.cpp src/Hand.cpp src/Pile.cpp src/Deck.cpp src/IValidatePlay.cpp src/validateStrategies/BigTwo_Singles.cpp src/validateStrategies/BigTwo_Pairs.cpp src/validateStrategies/BigTwo_Triples.cpp src/validateStrategies/Poker.cpp src/pokerStrategies/Straight.cpp src/pokerStrategies/Flush.cpp src/pokerStrategies/FullHouse.cpp src/pokerStrategies/FourOfAKind.cpp src/pokerStrategies/RoyalFlush.cpp src/pokerStrategies/StraightFlush.cpp src/PartsFactory.cpp src/Game.cpp src/Utility.cpp src/TestGame.cpp src/TestMain.cpp -g
```

## Framework Design

### BigTwo class diagram
![BigTwo UML](/docs/bigTwo_class_diagram.png?raw=true "BigTwo")

### CrazyEight class diagram
![CrazyEight UML](/docs/jesse_a1_class_diagram.png?raw=true "CrazyEight")

### Card Game Framework UML
![Card Game Framework UML](/docs/game_class_diagram.png?raw=true "Card Game Framework")

### Design Princples used

1.  Programming to an interface

    Our design features 8 abstract base classes:

    > Game, PartsFactory, Player, Pile, Card, CardCollection, IValidatePlay and IPokerValidatePlay.

    By programming to an abstract base class we can use polymorphism to simplify our code for assignment 3. For
    example, we can derive a computer player and a human player from our abstract base class player.
    Since both CPUPlayer and HumanPlayer is a type of player we can call the isHuman() function to
    determine whether the current turn is a human or computer player.

    ```
    player.isHuman()
    ```

    We can override game specific implementations like makeSelection to reflect each games indepedent behaviors.
    Which allow us to abstract away the details through encapsulation so that we can make use of similar steps
    with little change. For example, the steps to make a selection, check if its valid and playing it on a pile
    is similiar for most games. Since we programmed to an interface, all we need to do is change the appropriate methods
    in the derived concrete classes. Thanks to polymorphism, we can reuse the same steps for different games.

    ```
    isValid = player.makeSelection(getMaxCardsPerPlay());
    isPlayable = player.isPlayable(player.getSelection(), _pile->getTopHand());

    if(isPlayable){
        player.play(*_pile);
        isWinner(player);
    }else{
        std::cout << std::endl << "Invalid Move - try again" << std::endl << std::endl;
        player.clearSelection();
    }
    ```

2.  Composition over inheritance

    We favored composition over inheritance in our framework design. Inheritance was used strictly for
    relationships where one thing is-a type of another thing. For everything else, where relations are has-a, we
    used object composition. In our design Player contains Hand and Score while Game contains the Pile, Players and Deck.
    Similar to inheritance, composition gives the ability to use behaviors from other classes. For example, since Player
    contains Hand, Player can now use the Hand object to call functions that it would not otherwise have such as findLargest card.

### Design patterns used

1.  Abstract Factory

    In our game framework, we use abstract factory to create common game parts. Common parts
    that can be created via the factory are Cards, Players and Piles. Following the structure in
    the Gang of Four book, the classes used in our framework include:

    ![Abstract Factory Structure](/docs/AbstractFactoryStructure.png?raw=true "Abstract Factory Structure")

    * Abstract Factory ~= PartsFactory
    * Concrete Factory A ~= BigTwoParts
    * Concrete Factory B ~= CrazyEightParts

    * Product A ~= Card
    * Product A1 ~= BigTwoCard
    * Product A2 ~= CrazyEightCard
    * Product B ~= Player
    * Product B1 ~= BigTwoPlayer
    * Product B2 ~= CrazyEightPlayer
    * Product C ~= Pile
    * Product C1 ~= BigTwoPile
    * Product C2 ~= CrazyEightPile

    * Client ~= Game

    Using abstract factory, we can abstract away the implementation details of creating our concrete products.
    The factory subclasses such as BigTwoParts and CrazyEightsParts define their own implementation on
    how the products are created. Since the parts share a common supertype called PartsFactory, we can use
    polymorphism in our client code to simplify our code.  For example, in our BigTwoGame we can write the following
    client code

    ```
    PartsFactory* gameParts = new BigTwoParts();
    Player* player = gameParts.makePlayer();
    Pile* pile = gameParts.makePile();
    Card* card = gameParts.makeCard();
    ```

    Similarily, in our CrazyEightGame we can write

    ```
    PartsFactory* gameParts = new CrazyEightParts();
    Player* player = gameParts.makePlayer();
    Pile* pile = gameParts.makePile();
    Card* card = gameParts.makeCard();
    ```

    Because we used an abstract factory, it is easy to add new game parts and use it in our client code.
    To add new game parts,  all we need to do is derive a subclass from abstract PartsFactory and implement the concrete factory
    classes to define how it will create our objects. Then in the client code we can use it as per the code examples above.
    One slight drawback to using abstract factory is if a change to the interface is needed then
    every subclass must be updated to reflect the change.

2.  Singleton

    For assignment 3, we can leverage the singleton pattern to implement our concrete factories to ensure that
    only one instance of a concrete factory is created per product family. For example, when creating a game such as
    Big Two we only require one instance of the concrete `BigTwoParts` factory since we are only concerned with
    creating BigTwo family of products to setup our game.  Therefore, by using a singleton we can ensure that we have
    only one instance of a concrete factory to ensure only products in that family are created.

3.  Template Method

    Card games share a general set of steps for setting up a game. Depending on the game, there may be slight differences
    in the algorithm of each step.  With the template method pattern, we can define general steps common to all card games
    and then defer to subclasses to implement any steps that slightly differ.  Our framework uses the abstract `Game` class
    to define a set of abstract primitive operations that allows its subclasses to redefine its operation by overriding
    the algorithm to reflect its individual difference. For example, the participants in our framework include 'Game' as
    the abstract class and `BigTwo` game as the concrete class. The concrete class can be any game such as CrazyEights
    or Solitaire.  Since the concrete game is a subclass of the abstract 'Game' class we can redefine abstract methods
    define in the abstract 'Game' class to override behavior to reflect the game we are implementing.  Finally, the 'Game'
    defines a template method called `createGame()` that contains the steps of each abstract primitive operation along with
    other generic methods common to all games.

    ```
    // Game.cpp
    void Game::createGame() {
        setRules();
        createPlayers();
        shuffleDeck();
        dealCards();
    }

    // Game.h
    virtual void setRules() = 0;
    virtual void createPlayers() = 0;
    void shuffleDeck();
    virtual void dealCards() = 0;
    ```

    Since shuffling a deck is the same for all card games we leave shuffleDeck() as a simple function implemented
    by the abstract `Game` class.  Other steps such as createPlayers(), setRules() and dealCards() can all differ
    depending on the game, thus they are defined as virtual.

4.  Strategy for validating a play

    In general, card games must evaluate whether one hand is greater than or less than another hand. It must, also
    be able to determine whether the selected hand from a players hand can be played onto a pile such as a play pile.
    Depending on the game and the selected hand, the algorithm for evaluating whether one hand can be played against
    another changes from one game to another.  To solve this issue, we use the `strategy pattern` to define a family
    of interchangable algorithms.

    Apart from poker hands, hands can be singles, pairs, triples and straights. Unlike poker hands, these hands differ
    depending on the game we are playing. For example, in BigTwo when a user plays a single hand on a play pile the play
    is valid only if the selected hand is greater than the play pile's top hand or last hand placed. While in CrazyEights
    a single hand is valid only if the suit matches the play piles top most hand. By using strategy, we can define
    different algoirthms for different games with little change.  Little change is required, since all we need to do
    is subclass from a strategy interface and implemented the abstract operations. The actual steps of using the algorithm
    is separated from the implementation thus making it loosely coupled. For example, we can define a `BigTwoSingles`
    strategy and a `CrazyEightsSingles` strategy thus when our game changes we can simple change the algorithm by
    setting a different strategy.

    The participants in our framework for strategy is Player as the context, IValidatePlay as the strategy, and singles,
    pairs, triples and poker as the concrete strategies. By using strategy we have simplified our code and eliminated
    bloated conditional statements.

5.  Strategy for validating a play that has a poker hand

    We use another strategy to determine whether a poker hand is valid and is playable. The first strategy
    delegates to this strategy when it determines it is a poker hand.  Another strategy is required for Poker because
    unlike singles, pairs or triples a poker hand has different variations that must be accounted for in the
    evaluation.  For example, you can have a straight flush, royal flush, four of a kind, full house, flush and straight.
    The combinations are ranked against each other, such that a full house is bigger than a flush and a flush bigger than
    a straight. Also the same kind of hand can be compared against itself so that a full house with a higher triple
    is bigger than a full house with a smaller triple.

    One benefit of using strategy is that we can hide complex implementation details from the client.
    Poker hands are used in many different card games such as Texas Hold'em and Big Two. In our framework, we have 6
    concrete strategy classes to validate whether a poker hand is valid or playable.
    The strategies are `StraightFlush`, `Royal Flush`, `FourOfAKind`, `FullHouse`, `Flush` and `Straight`.  Since we have the
    set of poker algorithms implemented, games such as BigTwo and Texas Hold'em can simply use our framework as a blackbox
    without needing to know the details of how it is done.

    Other participants include the Strategy interface called `IPokerValidatePlay` which defines an isPokerPlayable function.
    The function takes a selected hand and compares against the top most hand of the play pile.  The 6 concrete strategies
    are derived from this interface.

    From a pessimist point of view, one drawback of this strategy is that the client needs to know how to select the strategy
    at runtime. But from a optimist point of view, changing behavior at runtime can be a great benefit.  In our framework,
    we detect the size of the players selection hand to determine whether it can potentially be a poker hand. If the
    size is 5 then we set our strategy to use the `Poker` strategy algorithm.  The Poker algorithm then delegates its
    validation to another family of strategies called the `IPokerValidatePlay` which has another set related algorithms
    that differ from the previous family as discussed in section 4. This new strategy determine whether than hand is one of
    `StraightFlush`, `Royal Flush`, `FourOfAKind`, `FullHouse`, `Flush` and `Straight`. If it is neither then it is invalid.

    Everything is encapsulated, such that all the client needs to do is the following.

    ```
    isValid = player.makeSelection(getMaxCardsPerPlay());
    isPlayable = player.isPlayable(player.getSelection(), _pile->get(_pileSelection));
    ```

    The above code is clean, it allows us to eliminate bloated conditional statements. The makeSelection method contains the following.

    ```
        switch(_selection->size()){
            case 1:
                std::cout << "singles strategy" << std::endl;
                setPlayable(singlesStrategy);
                break;
            case 2:
                std::cout << "pairs strategy" << std::endl;
                setPlayable(pairsStrategy);
                break;
            case 3:
                std::cout << "triples strategy" << std::endl;
                setPlayable(triplesStrategy);
                break;
            case 5:
                std::cout << "poker strategy" << std::endl;
                setPlayable(pokerStrategy);
                break;
            default:
                std::cout << "selection is invalid" << std::endl;
                setPlayable(singlesStrategy);
                return false;
        }
    	return isValid(*_selection);
    ```

    It does not care whether it is a poker hand or single hand.  It does not need to know since the strategy handles all
    runtime specific changes according to the hand size and delegates to the appropriate strategy or to another family of strategies -
    in the case of a poker hand.

### Framework usage demo

The classes and interfaces for a third game was implemented to test our framework in TestGame.cpp

[TestGame.cpp](/src/TestGame.cpp)