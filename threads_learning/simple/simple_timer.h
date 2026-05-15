#include <chrono>
#include <iostream>

class simpleTimer {
public:
  simpleTimer() { start = std::chrono::high_resolution_clock::now(); };
  ~simpleTimer() {
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "Duration: " << duration.count() << " s" << std::endl;
  }

private:
  std::chrono::_V2::system_clock::time_point start, end;
};