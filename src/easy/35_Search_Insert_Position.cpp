/*
Title: 35. Search Insert Position

Description:
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.

For Example:
Input: [1,3,5,6], 5
Output: 2

Input: [1,3,5,6], 2
Output: 1

Input: [1,3,5,6], 7
Output: 4

Input: [1,3,5,6], 0
Output: 0

My opinion:
方法一: 遍例vector，當找到目前數字>=target就回傳，如果都沒match到則回傳vector總長度
方法二: 採用二分搜尋法
因為輸入的vector是經過排序的，因此一開始就可以檢查vector.back()最後一個元素是否超過target

*/

#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  //*****方法一*****
  // int searchInsert(std::vector<int>& nums, int target) {
  //   for (int i = 0; i < nums.size(); i++) {
  //     if (nums[i] >= target) return i;
  //   }
  //   return nums.size();
  // }
  //*****方法二*****
  int searchInsert(std::vector<int>& nums, int target) {
    if (nums.back() < target) return nums.size();
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = left + (left + right) / 2;
      if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid;
    }
    return right;
  }
};

int main() {
  std::vector<int> nums{1, 3, 5, 6};
  int target = 7;
  std::cout << Solution().searchInsert(nums, target) << std::endl;
}