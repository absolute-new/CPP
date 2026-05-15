#include <chrono>
#include <iostream>
#include <thread>

/*
    Running a class method in a separate thread
*/

class MyClass {
public:
  void DoWork() {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "DoWork START" << std::endl;

    std::cout << "DoWork ID thread:   " << std::this_thread::get_id()
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "DoWork END" << std::endl;
  }

  int sum(int a, int b) {
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "sum START" << std::endl;

    std::cout << "sum  ID thread:   " << std::this_thread::get_id()
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "sum END" << std::endl;

    return a + b;
  }
};

int main() {

  int result = 0;

  MyClass my;

  // std::thread t([&]() { result = my.sum(3, 5); });
  std::thread t(&MyClass::DoWork, my);

  for (size_t i = 0; i < 20; ++i) {
    std::cout << "main ID thread:   " << std::this_thread::get_id()
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  t.join();
  std::cout << "RESULT = " << result << std::endl;

  return 0;
}