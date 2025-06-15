#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

std::unordered_map<int, int> getFrequencyMap(int array[], int arraySize);
void printHighestFrequency(std::unordered_map<int, int> frequencies);

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
  printHighestFrequency(frequencies);
}

std::unordered_map<int, int> getFrequencyMap(int array[], int arraySize) {
  std::unordered_map<int, int> frequencies;

  for (int i{}; i < arraySize; ++i) {
    frequencies[array[i]] += 1;
  }

  for (auto it : frequencies) {
    std::cout << it.first << ":\t" << it.second << '\n';
  }

  std::cout << '\n';

  return frequencies;
}

void printHighestFrequency(std::unordered_map<int, int> frequencies) {
  std::vector<std::pair<int, int>> highestNumAndFreq;
  std::vector<std::pair<int, int>> lowestNumAndFreq;

  int lowestFreq{frequencies.begin()->second};
  int highestFreq{};
  lowestNumAndFreq.emplace_back(frequencies.begin()->first,
                                frequencies.begin()->second);

  for (auto it : frequencies) {
    int key = it.first;
    int freq = it.second;
    if (freq > highestFreq) {
      highestNumAndFreq.clear();
      highestNumAndFreq.emplace_back(key, freq);
      highestFreq = freq;
    } else if (freq == highestFreq) {
      highestNumAndFreq.emplace_back(key, freq);
    }

    if (freq < lowestFreq) {
      lowestNumAndFreq.clear();
      lowestNumAndFreq.emplace_back(key, freq);
      lowestFreq = freq;
    } else if (freq == lowestFreq) {
      lowestNumAndFreq.emplace_back(key, freq);
    }
  }

  for (auto it : highestNumAndFreq) {
    std::cout << it.first << ":\t" << it.second << '\n';
  }

  std::cout << '\n';

  for (auto it : lowestNumAndFreq) {
    std::cout << it.first << ":\t" << it.second << '\n';
  }
}
