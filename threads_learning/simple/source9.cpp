#include <iostream>
#include <mutex>
#include <thread>

/*
        recursive mutex
*/

std::recursive_mutex rm;

void Foo(int a) {
  rm.lock();

  std::cout << a << " ";
  std::this_thread::sleep_for(std::chrono::milliseconds(300));

  if (a <= 1) {
    std::cout << std::endl;
    rm.unlock();
    return;
  }
  --a;
  Foo(a);
  rm.unlock();
}

int main() {

  std::thread t1(Foo, 10);
  std::thread t2(Foo, 10);

  t1.join();
  t2.join();

  return 0;
}