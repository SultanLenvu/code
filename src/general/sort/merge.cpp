#include <iostream>
#include <iterator>

#include "merge.hpp"

namespace sort {
namespace merge {

static void alg_rec(std::vector<int>& seq, int p, int r);
static void merge(std::vector<int>& seq, int p, int q, int r);
static void printVector(std::string_view text, const std::vector<int>& seq);

void solve(std::vector<int>& seq) {
  // printVector("Input: ", seq);

  alg_rec(seq, 0, seq.size() - 1);

  // printVector("Sorted: ", seq);
}

void alg_rec(std::vector<int>& seq, int p, int r) {
  if (p < r) {
    int q = (p + r) / 2;
    alg_rec(seq, p, q);
    alg_rec(seq, q + 1, r);
    merge(seq, p, q, r);
  }
}

void merge(std::vector<int>& seq, int p, int q, int r) {
  std::vector<int> subseq1(seq.begin() + p, seq.begin() + q + 1);
  std::vector<int> subseq2(seq.begin() + q + 1, seq.begin() + r + 1);

  int i = 0, j = 0;
  while (i < subseq1.size() && j < subseq2.size()) {
    if (subseq1[i] <= subseq2[j]) {
      seq[p++] = subseq1[i++];
    } else {
      seq[p++] = subseq2[j++];
    }
  }

  while (i < subseq1.size()) {
    seq[p++] = subseq1[i++];
  }

  while (j < subseq2.size()) {
    seq[p++] = subseq2[j++];
  }
}

void printVector(std::string_view text, const std::vector<int>& vec) {
  std::cout << text << std::endl;
  for (const auto& i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

bool test() { return false; }

}  // namespace merge
}  // namespace sort
