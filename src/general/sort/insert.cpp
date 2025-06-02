#include <iostream>
#include <iterator>
#include <vector>

#include "insert.hpp"

namespace sort {
namespace insert {

static void alg(std::vector<int>& seq);
static void printVector(std::string_view text, const std::vector<int>& seq);

void solve() {
  std::vector<int> seq = {12, -1, 0, 16, 2, 15, 5, 64, -50, 3, -25};
  printVector("Input: ", seq);

  alg(seq);

  printVector("Sorted: ", seq);
}

void alg(std::vector<int>& seq) {
  for (int j = 1; j < seq.size(); ++j) {
    int key = seq[j];

    int i = j - 1;
    while (i >= 0 && seq[i] < key) {
      seq[i + 1] = seq[i];
      i = i - 1;
    }

    seq[i + 1] = key;
  }
}

void printVector(std::string_view text, const std::vector<int>& vec) {
  std::cout << text << std::endl;
  //   for (const auto& i : vec) {
  //     std::cout << i << " ";
  //   }
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

bool test() { return false; }

}  // namespace insert
}  // namespace sort
