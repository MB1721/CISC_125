#ifndef box
#define box

#include <array>
#include <iostream>
#include <string>
#include <vector>
#include "dice.h"

struct Tile {
  public:
    Tile(int input_num);
    std::string getStatus();
    void close() {is_up = false;}
    friend class Box;
  private:
    int num;
    bool is_up;
};

class Box {
  public:
    Box();
    std::string getBoxStatus();
    int getTotal();
    bool closeTiles(Dice dice);
    void endGame(Dice dice);
    void restartSelection(Dice dice);
  private:
    std::vector<Tile> box_tiles; 
};

#endif
