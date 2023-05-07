# Shut the Box
Welcome to the Shut the Box game! This game is meant to showcase how structured data types (classes and structs) can be utilized in c++. The two classes used in this project are Box and Dice; the struct used is called Tile. Our classes are split into individual header and implementation files, with box.h containing both Box and Struct, and dice.h defining the dice class.

## Game Overview
This game emulates Shut the Box. Also known as Canoga, this is a board game which can be played with up to four players. The objective of the game is to close eight standing tiles. Each turn a player is to roll two six-sided dice. The total of the two dice is the total subtracted from the standing tiles.

## Sample Round
Numbers *1, 2, 3, 4, 5, 6, 7, 8* are displayed using a set of tiles. The player then rolls the two dice to get *6* and *2*.

```
Box: 1 2 3 4 5 6 7 8 9 
Dice: 6-2
```
The roll total of the dice is **8**. The player must then close one to three tiles whose numbers total to **8**: 
\[1, 7\], \[4, 3, 1\], \[5, 3\], \[8\], etc.

```
Pick up to 3 tiles to close. Enter 0 to skip a tile.
Tile #1: 1
Tile #2: 7
Tile #3: 0
Closing tiles: 1 7 0 
```
Resulting in:

```
Closed tile 1.
Closed tile 7.
Closed tile 0.

Box: 1 * 3 * 5 6 7 8 9 
```

If the roll total exceeds the tile total, the player must enter 0 for all tile options.

```
Pick up to 3 tiles to close. Enter 0 to skip a tile.
Tile #1: 0
Tile #2: 0
Tile #3: 0
```
The game will end here and the player total will calculate based on the remaining tiles.

# Future Implementation

Currently the game allows players to enter the same tile twice to equal the roll total. Future implementation would see to this error so that each tile may only be entered once per game.