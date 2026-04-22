#include <iostream>
#include <mutex>

class lock_guard {
private:
  std::mutex &mtx;

public:
  lock_guard(std::mutex &mtx_) : mtx(mtx_) { mtx.lock(); }

  lock_guard(std::mutex &mtx_, std::adopt_lock_t) : mtx(mtx_) {}

  ~lock_guard() { mtx.unlock(); }

  lock_guard(const lock_guard &) = delete;
  lock_guard &operator=(const lock_guard &) = delete;
};

int main() { return 0; }