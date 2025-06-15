#include <iostream>
#include <unordered_map>

std::unordered_map<int, int> getFrequencyMap(int array[], int arraySize);

int main() {

  // int arraySize{};

  // std::cout << "Enter Array Size: ";
  // std::cin >> arraySize;
  // std::cout << '\n';

  int array[20] = {1, 1,  1,  1,  2,  55, 55, 7, 6, 5,
                   5, 10, 10, 10, 10, 9,  9,  8, 8, 8};
  // for (int i{}; i < arraySize; ++i) {
  //   std::cout << "Enter element at position " << i << ": ";
  //   std::cin >> array[i];
  //   // std::cout << '\n';
  // }

  std::unordered_map<int, int> frequencies = getFrequencyMap(array, 20);
}

std::unordered_map<int, int> getFrequencyMap(int array[], int arraySize) {
  std::unordered_map<int, int> frequencies;

  for (int i{}; i < arraySize; ++i) {
    frequencies[array[i]] += 1;
  }

  for (auto it : frequencies) {
    std::cout << it.first << ":\t" << it.second << '\n';
  }

  return frequencies;
}
