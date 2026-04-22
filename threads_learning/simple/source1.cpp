#include <chrono>
#include <iostream>
#include <thread>

void fakeWork() {
  for (int i = 0; i < 10; ++i) {
    std::cout << std::this_thread::get_id() << "\tfakeWork" << "\t" << i
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}

int main() {

  std::thread th(fakeWork);

  for (int i = 0; i < 10; ++i) {
    std::cout << std::this_thread::get_id() << "\tmain" << "\t" << i
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  th.join();

  for (int i = 0; i < 10; ++i) {
    std::cout << std::this_thread::get_id() << "\tmain2" << "\t" << i
              << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }

  return 0;
}