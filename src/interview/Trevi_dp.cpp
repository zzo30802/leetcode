#include <cstdio>
#include <iostream>
#include <vector>
/*
這是在特雷維遇到的考試題目，要求使用dp的方式解題。

input : [ 2, 1, 5, 9]
output: [45,90,18,10]
*/

std::vector<int> SliceInteger(const std::vector<int> &A) {
  int vec_size = A.size();
  std::vector<int> left;
  left.resize(vec_size, 1);
  std::vector<int> right;
  right.resize(vec_size, 1);

  int index = 0;
  // int left_index = 0, right_index = A.size() - 1;
  for (int i = 1; i < A.size(); i++) {
    // left
    left[i] = left[i - 1] * A[i - 1];
    // right
    right[vec_size - 1 - i] = right[vec_size - i] * A[vec_size - i];
  }
  std::cout << "left : ";
  for (const auto &i : left) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "right : ";
  for (const auto &i : right) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::vector<int> ret_vec;
  ret_vec.reserve(vec_size);
  for (int i = 0; i < vec_size; i++) {
    ret_vec.emplace_back(left[i] * right[i]);
  }
  return ret_vec;
}

int main() {
  std::vector<int> nums{2, 1, 5, 9};  // 45,90,18,10

  std::vector<int> ret = SliceInteger(nums);
  std::cout << "result :";
  for (const auto &num : ret) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}