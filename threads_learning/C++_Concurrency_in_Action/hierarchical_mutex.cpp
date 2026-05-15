#include <exception>
#include <iostream>
#include <mutex>

class hierarchicalMutex {
private:
  std::mutex internalMutex;
  unsigned long const hierarchyValue;
  unsigned long previousHierarcyValue;
  static thread_local unsigned long thisThreadHierarchyValue;

  void check_for_hierarchy_violation() {
    if (thisThreadHierarchyValue <= hierarchyValue) {
      throw std::logic_error("mutex hierarchy violation");
    }
  }
  void update_hierarchy_value() {
    previousHierarcyValue = thisThreadHierarchyValue;
    thisThreadHierarchyValue = hierarchyValue;
  }

public:
  explicit hierarchicalMutex(unsigned long value)
      : hierarchyValue(value), previousHierarcyValue(0) {}

  void lock() {
    check_for_hierarchy_violation();
    internalMutex.lock();
    update_hierarchy_value();
  }

  void unlock() {
    thisThreadHierarchyValue = previousHierarcyValue;
    internalMutex.unlock();
  }

  bool try_lock() {
    check_for_hierarchy_violation();
    if (!internalMutex.try_lock()) {
      return false;
    }
    update_hierarchy_value();
    return true;
  }
};

thread_local unsigned long hierarchicalMutex::thisThreadHierarchyValue = ~0UL;

int main() { return 0; }