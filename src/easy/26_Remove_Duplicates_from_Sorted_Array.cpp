
/*
Title: Remove Duplicates from Sorted Array

Description: 
Given a sorted array  nums , remove the duplicates in-place such that each element appear only  once  and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.


For Example:
Given _nums_ = [1,1,2],
Your function should return length = 2, with the first two elements of _nums_ being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Given _nums_ = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of _nums_ being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.

About my opinion:
和 "83. Remove Duplicates from Sorted List" 題型類似，但這題比較簡單，
因為數組可以直接訪問，但linked list不行。
因為是sorted array(經過排序的)，所以重複的元素一定會相鄰。

參考:
https://ithelp.ithome.com.tw/articles/10229969
*/
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.empty())
      return 0;
    int& n = nums[0];  // 紀錄第一個元素的值當起點
    std::vector<int>::iterator it;
    for (it = nums.begin() + 1; it < nums.end();) {  // index從1開始比較，否則會自己跟自己比
      if (*it == n) {
        // int dis = std::distance(it, nums.begin());
        it = nums.erase(it);  // 刪除後，it會指向下個元素
      } else {                // 一直刪除一樣的元素，直到沒有發現一樣的元素，指針就會往下更新
        n = *it;              //update
        it++;
      }
    }
    return nums.size();
  }
};
int main() {
}