#include <iostream>
#include <vector>
#include "box.h"
#include "dice.h"

int main() {
  Box b;
  bool end_game;
  std::cout << "Let's play Shut The Box\n" << std::endl;
  Dice d(2);
  // game loop
  do {
    // display box tiles
    std::cout << "\n" << b.getBoxStatus();
    
    // roll one or two dice
    if (b.getTotal() <= 6)
      d = Dice(1);
    d.roll();
    std::cout << "Dice: " << d.str() << std::endl;
    
    // prompt player to close tiles
    end_game = b.closeTiles(d) == false ? true : false;
  } while (d.total() <= b.getTotal() && end_game == false);

  // end game
  if (d.total() > b.getTotal())
    std::cout << "Dice roll exceeds box tile range." << std::endl;     
  b.endGame(d);
  
  return 0;
}
