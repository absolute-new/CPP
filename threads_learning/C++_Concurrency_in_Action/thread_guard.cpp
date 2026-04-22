#include <iostream>
#include <thread>

int main() {

  class thread_guard {
  private:
    std::thread &t_;

  public:
    explicit thread_guard(std::thread &t) : t_(t) {}
    ~thread_guard() {
      if (t_.joinable()) {
        t_.join();
      }
    }

    thread_guard(const thread_guard &) = delete;
    thread_guard(thread_guard &&) = delete;
    thread_guard &operator=(const thread_guard &) = delete;
    thread_guard &operator=(thread_guard &&) = delete;
  };

  return 0;
}