#include <mutex>

class unique_lock {
private:
  std::mutex *m;
  bool owns;

public:
  explicit unique_lock(std::mutex &m_) : m(&m_), owns(true) { m->lock(); }
  unique_lock(std::mutex &m_, std::defer_lock_t) : m(&m_), owns(false) {}
  unique_lock(std::mutex &m_, std::adopt_lock_t) : m(&m_), owns(true) {}
  ~unique_lock() {
    if (owns) {
      m->unlock();
    }
  }

  unique_lock(const unique_lock &) = delete;
  unique_lock &operator=(const unique_lock &) = delete;

  unique_lock(unique_lock &&other) noexcept : m(other.m), owns(other.owns) {
    other.m = nullptr;
    other.owns = false;
  }
  unique_lock &operator=(unique_lock &&other) noexcept {
    if (this != &other) {
      if (owns) {
        m->unlock();
      }
      m = other.m;
      owns = other.owns;

      other.m = nullptr;
      other.owns = false;
    }
  }

  void lock() {
    m->lock();
    owns = true;
  }
  void unlock() {
    m->unlock();
    owns = false;
  }
  bool owns_lock() const { return owns; }
  explicit operator bool() const { return owns; }
};