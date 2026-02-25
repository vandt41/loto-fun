#include <algorithm>
#include <array>
#include <iostream>
#include <ostream>
#include <random>
#include <string>
#include <vector>
#define MAX_NUM_PER_ROW 5
#define MAX_SQUARE 9

class Sheets {
private:
  // Data hidden from the outside (Encapsulation)
  std::array<std::array<int, 9>, 18> sheet;

public:
  std::string color;

  // 2. The Constructor (Runs automatically when object is created)
  Sheets(std::string c) { color = c; }
  // 3. A Method
  std::array<std::array<int, 9>, 18> create() {
    std::vector<int> pool(90);
    std::iota(pool.begin(), pool.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(pool.begin(), pool.end(), g);

    std::array<int, 9> column_counts = {0};

    for (int i = 0; i < 18; i++) {
      sheet[i].fill(0);
      int counter = 0;

      // Create a list of all columns 0-8
      std::vector<int> available_columns = {0, 1, 2, 3, 4, 5, 6, 7, 8};
      std::shuffle(available_columns.begin(), available_columns.end(), g);

      for (int j : available_columns) {
        if (counter >= MAX_NUM_PER_ROW)
          break;

        int col_limit = (j == 0) ? 9 : (j == 8 ? 11 : 10);

        // Check if this column still has room globally
        if (column_counts[j] < col_limit) {
          int min = (j == 0) ? 1 : j * 10;
          int max = (j == 8) ? 90 : (j * 10) + 9;

          // Find a matching number in the pool
          for (auto it = pool.begin(); it != pool.end(); ++it) {
            if (*it >= min && *it <= max) {
              sheet[i][j] = *it;
              pool.erase(it);
              column_counts[j]++;
              counter++;
              break;
            }
          }
        }
      }
    }
    return sheet;
  }

  void show() {
    for (int i = 0; i < 18; i++) {

      if (i != 0 && i % 9 == 0) {
        std::cout << "Sheet 2\t\t\t\t" << color << "\n";

      } else if (i == 0) {
        std::cout << "Sheet 1\t\t\t\t" << color << "\n";

      } else if (i % 3 == 0) {
        for (int j = 0; j < 9; j++) {
          printf("----");
        }
        printf("\n");
      }
      for (int j = 0; j < 9; j++) {
        if (sheet[i][j] == 0) {
          printf("%4s", "#"); // %4s means string padded to 4 spaces
        } else {
          printf("%4d", sheet[i][j]); // %4d means decimal padded to 4 spaces
        }
      }
      std::cout << std::endl;
    }
  }
  void gotNumber(int num) {}
};
class Players {
private:
  int money;

public:
  std::string name;
  Players(std::string n) { name = n; }
  std::vector<std::array<std::array<int, 9>, 9>> sheetList;
};

int main() {
  Players player1("Khang");
  Sheets sheet("Yellow");
  sheet.create();
  sheet.show();
  return 0;
}
