#  Card Game Framework

## Build Instructions

Used  `CLion IDE ` but you can compile using `g++ <file_names.cpp> -g `

```
g++ src/Player.cpp src/CardCollection.cpp src/Card.cpp src/Hand.cpp src/Pile.cpp src/Deck.cpp src/IValidatePlay.cpp src/validateStrategies/BigTwo_Singles.cpp src/validateStrategies/BigTwo_Pairs.cpp src/validateStrategies/BigTwo_Triples.cpp src/validateStrategies/Poker.cpp src/pokerStrategies/Straight.cpp src/pokerStrategies/Flush.cpp src/pokerStrategies/FullHouse.cpp src/pokerStrategies/FourOfAKind.cpp src/pokerStrategies/RoyalFlush.cpp src/pokerStrategies/StraightFlush.cpp src/PartsFactory.cpp src/Game.cpp src/Utility.cpp src/TestGame.cpp src/TestMain.cpp -g
```

## Framework Design

### BigTwo class diagram
![BigTwo UML](/docs/bigTwo_class_diagram.png?raw=true "BigTwo")

### Card Game Framework UML"
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
    contains Hand it can now use the Hand object to call functions that it would not otherwise have such as findLargest card.

### Design patterns used

1.  Abstract Factory

2.  Template Method

3.  Strategy for validating a play

4.  Strategy for validating a play that has a poker hand

5.  Singleton