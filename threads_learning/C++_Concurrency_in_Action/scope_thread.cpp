#include <iostream>
#include <thread>

int main() {

  class scope_thread {
  private:
    std::thread t;

  public:
    explicit scope_thread(std::thread t_) : t(std::move(t_)) {
      if (!t.joinable()) {
        throw std::logic_error("No thread");
      }
    }
    ~scope_thread() { t.join(); }

    scope_thread(const scope_thread &) = delete;
    scope_thread &operator=(const scope_thread &) = delete;
  };

  return 0;
}