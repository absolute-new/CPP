
#include "simple_timer.h"
#include <iostream>
#include <mutex>
#include <thread>

/*
        Deadlock
*/

std::mutex mtx1;
std::mutex mtx2;

void print_ch1() {

  //   mtx1.lock();

  mtx2.lock();

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  mtx1.lock();

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      std::cout << '#';
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  //   mtx2.unlock();

  mtx1.unlock();

  mtx2.unlock();
}

void print_ch2() {

  mtx1.lock();

  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  mtx2.lock();

  for (size_t i = 0; i < 5; ++i) {
    for (size_t j = 0; j < 10; ++j) {
      std::cout << '*';
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  mtx2.unlock();

  mtx1.unlock();
}

int main() {

  simpleTimer timer;

  std::thread t1(print_ch1);
  std::thread t2(print_ch2);

  t1.join();
  t2.join();

  return 0;
}