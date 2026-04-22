/*
    Returning the results of a function from a thread
*/

#include <chrono>
#include <iostream>
#include <thread>

void DoWork(int &a) {
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
  std::cout << "DoWork Started" << std::endl;
  std::cout << "DoWork thread ID: " << std::this_thread::get_id() << std::endl;
  a *= 2;

  std::this_thread::sleep_for(std::chrono::milliseconds(10000));
  std::cout << "DoWork End" << std::endl;
}

int main() {

  int num = 10;
  std::thread t(DoWork, std::ref(num));

  for (size_t i = 0; i < 10; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "main thread ID: " << std::this_thread::get_id() << std::endl;
  }

  t.join();
  std::cout << "result DoWork: " << num << std::endl;

  return 0;
}