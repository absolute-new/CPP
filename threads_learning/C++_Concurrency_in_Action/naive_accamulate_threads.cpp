#include <iostream>
#include <numeric> //std::accumulate
#include <thread>
#include <vector>

template <typename It, typename T> struct accumulate_block {
  void operator()(It first, It last, T &result) {
    result = std::accumulate(first, last, result);
  }
};

template <typename It, typename T>
T parallel_accumulate(It first, It last, T &&init) {
  unsigned long const length = std::distance(first, last);
  if (!length) {
    return init;
  }

  unsigned long const min_per_thread = 25;
  unsigned long const max_threads =
      (length + min_per_thread - 1) / min_per_thread;

  unsigned long const hardware_threads = std::thread::hardware_concurrency();
  unsigned long const num_threads =
      std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

  unsigned long const block_size = length / num_threads;

  std::vector<T> result(num_threads);
  std::vector<std::thread> threads(num_threads - 1);

  //  Test output
  std::cout << "Elements: " << length << std::endl;
  std::cout << "Hardware: " << hardware_threads << std::endl;
  std::cout << "All threads: " << num_threads << std::endl;
  std::cout << "Block size: " << block_size << std::endl;

  It block_start = first;
  for (unsigned long i = 0; i < (num_threads - 1); ++i) {
    It block_end = block_start;
    std::advance(block_end, block_size);
    threads[i] = std::thread(accumulate_block<It, T>(), block_start, block_end,
                             std::ref(result[i]));
    block_start = block_end;
  }
  accumulate_block<It, T>()(block_start, last, result[num_threads - 1]);

  for (auto &t : threads) {
    t.join();
  }

  return std::accumulate(result.begin(), result.end(), static_cast<T>(init));
}

int main() {
  // Test 1
  std::vector<int> test1 = {1, 2, 3, 4, 5};
  int sum1 = parallel_accumulate(test1.begin(), test1.end(), 0);
  std::cout << "Sum 1-5: " << sum1 << "\t(need 15)" << std::endl << std::endl;

  // Test 2
  std::vector<int> test2(1000);
  for (int i = 0; i < 1000; ++i)
    test2[i] = i + 1;
  int sum2 = parallel_accumulate(test2.begin(), test2.end(), 0);
  std::cout << "Sum 1-1000: " << sum2 << "\t(need 500500)" << std::endl;

  return 0;
}