#  Card Game Framework

## Build Instructions

Used  `CLion IDE ` but you can compile using `g++ <file_names.cpp> -g `

```
g++ src/Player.cpp src/CardCollection.cpp src/Card.cpp src/Hand.cpp src/Pile.cpp src/Deck.cpp src/IValidatePlay.cpp src/validateStrategies/BigTwo_Singles.cpp src/validateStrategies/BigTwo_Pairs.cpp src/validateStrategies/BigTwo_Triples.cpp src/validateStrategies/Poker.cpp src/pokerStrategies/Straight.cpp src/pokerStrategies/Flush.cpp src/pokerStrategies/FullHouse.cpp src/pokerStrategies/FourOfAKind.cpp src/pokerStrategies/RoyalFlush.cpp src/pokerStrategies/StraightFlush.cpp src/PartsFactory.cpp src/Game.cpp src/Utility.cpp src/TestGame.cpp src/TestMain.cpp -g
```

## Framework Design

### BigTwo class diagram
![BigTwo UML](/docs/bigTwo_class_diagram.png?raw=true "BigTwo")

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
    classes to define how it will create our objects. Then in the client code we can simply use it like in the above
    examples. One slight drawback to using abstract factory is if a change to the interface is needed then
    every subclass must be updated to reflect the change.

2.  Template Method

3.  Strategy for validating a play

4.  Strategy for validating a play that has a poker hand

5.  Singleton