/*
Title: 88. Merge Sorted Array

Description:

For Example:

Opinion:
因為nums1有足夠的空間使nums的元素加入

*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int&& vec_len = m + n - 1;
    int&& nums1_size = m - 1;
    int&& nums2_size = n - 1;
    // int& nums_len = (nums1_size > nums2_size) ? nums1_size : nums2_size;

    // 從後面找到前面
    while (nums1_size >= 0 && nums2_size >= 0) {  // 其中之1為false則退出
      // nums1 > nums2
      if (nums1[nums1_size] >= nums2[nums2_size]) {
        nums1[vec_len--] = nums1[nums1_size--];
      } else {  // nums1 < nums2
        nums1[vec_len--] = nums2[nums2_size--];
      }
    }
    // 有可能nums1比nums2還要少
    while (nums2_size >= 0) {
      nums1[vec_len--] = nums2[nums2_size--];
    }
  }
};

int main() {
  std::vector<int> v1{1, 2, 3, 0, 0, 0};
  std::vector<int> v2{2, 5, 6};
  Solution().merge(v1, 3, v2, 3);
  for (const auto& n : v1) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
  return 0;
}