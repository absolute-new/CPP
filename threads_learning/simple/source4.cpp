#include <chrono>
#include <iostream>
#include <thread>

/*
    Returning the results of a function from a thread
    lambda func
*/

int sum(int a, int b) {
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  std::cout << "START SUM FUNC" << std::endl;

  std::cout << "sum - ID thread: " << std::this_thread::get_id() << std::endl;

  std::this_thread::sleep_for(std::chrono::milliseconds(6000));
  std::cout << "END SUN FUNC" << std::endl;

  return a + b;
}

int main() {

  int result = 0;

  std::thread t([&result]() { result = sum(2, 5); });

  for (size_t i = 0; i < 15; ++i) {
    std::cout << "main - ID thread: " << std::this_thread::get_id()
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  t.join();

  std::cout << "RESULT = " << result << std::endl;

  return 0;
}