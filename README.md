#  Card Game Framework

## Build Instructions

Used  `CLion IDE ` but you can compile using   `g++ <file_name.cpp> -g `

```
g++ src/Player.cpp src/CardCollection.cpp src/Card.cpp src/Hand.cpp src/Pile.cpp src/Deck.cpp src/IValidatePlay.cpp src/validateStrategies/Singles.cpp src/validateStrategies/Pairs.cpp src/validateStrategies/Triples.cpp src/validateStrategies/Poker.cpp src/pokerStrategies/Straight.cpp src/pokerStrategies/Flush.cpp src/pokerStrategies/FullHouse.cpp src/pokerStrategies/FourOfAKind.cpp src/pokerStrategies/RoyalFlush.cpp src/pokerStrategies/StraightFlush.cpp src/PartsFactory.cpp src/Game.cpp src/main.cpp -g
```

## Framework Design

![Card Game Framework UML](/docs/game_class_diagram.png?raw=true "Card Game Framework")
![BigTwo UML](/docs/bigTwo_class_diagram.png?raw=true "BigTwo")

### Design patterns used