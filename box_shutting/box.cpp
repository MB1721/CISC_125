#include "box.h"

// tile methods
Tile::Tile(int input_num) {
  num = input_num;
  is_up = true;
}

std::string Tile::getStatus() {
  std::string state = "";
  is_up ? state += std::to_string(num) : state += "*";

  return state;
}

// box methods
Box::Box() {
  // create 9 tiles
  for (int tile = 0; tile < 9; tile++) {
    Tile t(tile + 1);
    box_tiles.push_back(t); // push tile into box_tiles vector
  }
}

bool Box::closeTiles(Dice dice) {
  // user input
  int chosen_tiles[3], invalid_tiles[3], input_tile = 0, total_tile_val = 0; 
  // sucessfully closed tiles
  bool valid_selection, success = false;
  std::vector<Tile> can_close_tiles, cannot_close_tiles;
  
  do {
    std::cout << "Pick up to 3 tiles to close. Enter 0 to skip a tile." << std::endl;
    // user inputs tiles
    int num_inputs = 0;
    do {
      std::cout << "Tile #" << std::to_string(num_inputs + 1) << ": ";
      std::cin >> input_tile;
      chosen_tiles[num_inputs] = input_tile;
      num_inputs++;
    } while(num_inputs < 3);

    // evaluate if user inputs valid tile range
    for (int tile = 0; tile < 3; tile++) {
      if (chosen_tiles[tile] < 0 || chosen_tiles[tile] > 9) {
        valid_selection = false;
        break;
      } else {valid_selection = true;}
    }
    // store invalid tiles
    for (int tile = 0; tile < 3; tile++) {
      if (chosen_tiles[tile] < 0 || chosen_tiles[tile] > 9)
        invalid_tiles[tile] = chosen_tiles[tile];
    }
    if (valid_selection == false) {
      std::cout << "Tile(s): ";
      for (int tile : invalid_tiles)
        if (tile != 0)  {std::cout << tile << " ";}
      std::cout << "are invalid. Try again.\n" << std::endl;
      std::cout << Box::getBoxStatus();
      // reset user inputs
      for (int i = 0; i < 3; i++)
        invalid_tiles[i] = 0;
    }
  } while(valid_selection == false);

  int chosen_tile_total = 0;
  for (int tile : chosen_tiles)
    chosen_tile_total += tile;

  if (chosen_tile_total == 0) {
    success = false;
    goto returnResult;
  }
  
  std::cout << "\nClosing tiles: ";
  for (int tile : chosen_tiles) {
    if (tile > 0) 
      std::cout << tile << " ";
  }
  std::cout << "\n\n";

  // match chosen tiles to tiles left in box
  for (int &tile : chosen_tiles) {
    for (Tile &tile_to_close : box_tiles) {
      if (tile == tile_to_close.num) {
        if (tile_to_close.is_up) {
          success = true;
          can_close_tiles.push_back(tile_to_close);
        } else {
          success = false;
          cannot_close_tiles.push_back(tile_to_close);
        }
      } else {continue;}
    }
  }

for (Tile tile : can_close_tiles) {
  total_tile_val += tile.num;
}
  
  // if player chooses an already closed tile restart selection
  if (success == false) {
    std::cout << "Tile(s) "; 
    for (Tile &tile : cannot_close_tiles) {
      std::cout << tile.num << " ";
    }
    std::cout << "already closed. Try again." << std::endl;
    Box::restartSelection(dice);
  } else if (total_tile_val > dice.total()) {
    std::cout << "Tile selection exceeds dice total. Try again." << std::endl;
    Box::restartSelection(dice);
  } else if (total_tile_val < dice.total()) {
    std::cout << "Tile selection subceeds dice total. Try again." << std::endl;
    Box::restartSelection(dice);
  } else {
    for (Tile tile : can_close_tiles) {
      for (Tile &tile_to_close : this->box_tiles) {
        if (tile.num == tile_to_close.num) {
          tile_to_close.close();
          std::cout << "Closed tile " << tile.num << "." << std::endl;
        }
      }
    }
  }

  returnResult:
  return success;
}

void Box::endGame(Dice dice) {
  std::cout << "\nGAME OVER. Final result." << std::endl;
  std::cout << "-------------------------------\n" << std::endl;
  std::cout << this->getBoxStatus();
  std::cout << "Dice: " << dice.str() << std::endl;
  std::cout << "Score: " << this->getTotal() << std::endl;
}

std::string Box::getBoxStatus() {
  std::string box_state = "Box: ";

  for (Tile t : box_tiles) {
    box_state += t.getStatus() + " ";
  }
  return box_state + "\n";
}

int Box::getTotal() {
  int total = 0;

  for (Tile t : box_tiles) {
    t.is_up ? total += t.num : false;
  }

  return total;  
}

void Box::restartSelection (Dice dice) {
  std::cout << this->getBoxStatus();
  std::cout << "Dice: " << dice.str() << std::endl; 
  Box::closeTiles(dice); 
}
