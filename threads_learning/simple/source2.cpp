#include <chrono>
#include <iostream>
#include <string>
#include <thread>

void fakeWork(int a, int b, std::string msg) {
  std::cout << msg << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  std::cout << "sum = " << a + b << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(10000));
}

int main() {

  std::thread th(fakeWork, 5, 6, "Hello World!");

  for (int i = 0; true; ++i) {
    std::cout << "MAIN WORK" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  th.join();

  return 0;
}