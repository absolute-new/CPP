#include "simple_timer.h"
#include <iostream>
#include <mutex>
#include <thread>

/*
    mutex
*/

// std::mutex mtx;

void print_ch(char ch) {

  static std::mutex mtx;

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));

  mtx.lock();

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      std::cout << ch;
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  mtx.unlock();

  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main() {

  simpleTimer timer;

  std::thread t1(print_ch, '#');
  std::thread t2(print_ch, '*');
  std::thread t3(print_ch, '@');

  //   print_ch('#');
  //   print_ch('*');
  //   print_ch('@');

  t1.join();
  t2.join();
  t3.join();

  return 0;
}