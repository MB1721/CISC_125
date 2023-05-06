// Recursive Star Diamond Pattern
// Mason Bennett
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <typeinfo>

/**
 * @brief Creates a star pattern using '*' character.
 * 
 * @param star_width The number of stars in the middle row of the diamond.
 * @param star_count The number of stars to be printed on the current line.
 * @param subtract_stars The number of stars subtracted per subquent row after
 * `star_width` is reached.
 * @return Returns the number of stars printed.
 */
int starPattern(int star_width, int star_count = 1, int subtract_stars = 0);

int main() {
  // number of stars in the middle row of the diamonds
  int num_stars;
  bool valid_input = true;
  const int MAX_STARS = 19;
  
  // evaluate user input
  do {
    try {
      std::cout << "Enter an odd number from 1 - " + std::to_string(MAX_STARS) + ": ";
      std::cin >> num_stars;
      // user enters wrong input type
      if (std::cin.fail()) { 
        throw "User entered the wrong input type.";
      }
      // user inputs an even number
      else if (num_stars % 2 == 0) {
        throw "User entered an even number.";

      }
      // user inputs innapropriate number of stars
      else if (num_stars > MAX_STARS || num_stars < 1) {
        throw "User did not enter a number between 1 and " + std::to_string(MAX_STARS);
      } else {valid_input = true;}
    }
    catch(const char *error) {
      valid_input = false;
      // clear input stream
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      // display error
      std::cout << "Error: " << error << "\n\n";
    }
    catch(...) {
      valid_input = false;
      // clear input stream
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      // display error
      std::cout << "An error occurred." << "\n\n";
    }
  } while (valid_input == false);
  
  std::cout << std::endl;
  // Print diamond pattern to console.
  // Set `num stars` to total number of stars printed.
  num_stars = starPattern(num_stars);
  std::cout << "\nThis pattern has " << num_stars << " stars" << std::endl;
}

int starPattern(int star_width, int star_count, int subtract_stars) {
  // Initializes string for star row.
  std::string stars = "";
  
  // Executes if number of stars is less than target width.  
  if (star_width > star_count && star_width > subtract_stars) {
    // Add stars to string.
    // Number of stars in the string/current row is equal to star count.
    for (int i = 0; i < star_count; i++)
      stars += '*';
    // print stars
    std::cout << std::setw( star_width - ((star_width - star_count) / 2) ) << stars << std::endl;
    // Add two more stars to the next row.
    return star_count + starPattern(star_width, star_count + 2);
  }
  // Executes once `star_count` matches `star_width`.
  // Print stars in a decreasing sequence until only one star is printed
  // in the last row.
  else if (star_width == star_count && star_width > subtract_stars) {
    // `stars_down` represents the `star_count` for decremental rows.
    int stars_down = star_count - subtract_stars;
    // construct star string
    for (int i = 0; i < stars_down; i++)
      stars += '*';
    // print stars
    std::cout << std::setw( star_width - ((star_width - stars_down) / 2) ) << stars << std::endl;
    // Subtract 2 more stars from the next row.
    return stars_down + starPattern(star_width, star_count, subtract_stars + 2);
  }
  // Executes once final star is printed.
  // Counts 0 stars printed for this row. 
  else 
    return 0;
  
}