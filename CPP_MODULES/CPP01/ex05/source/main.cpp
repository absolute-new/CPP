#include "Harl.hpp"

int main(void) {
  Harl harl;
  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "SOME"};

  for (int i = 0; i < 5; ++i) {
    harl.complain(levels[i]);
  }

  return (0);
}