/*
Title: 66. Plus One

Description:
Given a non-empty array of decimal digits representing a non-negative integer,
increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

For example:

My opinion:

*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    // int vec_size = digits.size();
    // 遍歷
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] == 9)
        digits[i] = 0;  // 如果發現9則換成0(9+1=10 進位)
      else {
        digits[i] += 1;
        return digits;
      }
    }
    // 檢設vector第一個元素為0，表示進位，因此在vector.begin()插入1
    if (digits.front() == 0) digits.insert(digits.begin(), 1);
    return digits;
  }
};
int main() {
  std::vector<int> digits{4, 3, 2, 1};
  Solution().plusOne(digits);
  for (const auto& num : digits) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}