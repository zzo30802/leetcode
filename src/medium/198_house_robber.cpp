// DP問題
/*
Title: 198. House Robber

Description:
有一個小偷想要偷東西，找到了一列房子，每個房子裡的有不ㄧ樣的財物價值可以偷，
但因為防盜系統的關係，你不能偷相鄰兩間房子的物品，請找出最大你能偷的財物價值。

For Example:
Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Input: [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Opinion:


https://desolve.medium.com/%E5%BE%9Eleetcode%E5%AD%B8%E6%BC%94%E7%AE%97%E6%B3%95-28-dynamic-programming-6-8e5a81a8437d
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  int rob(std::vector<int>& nums) {
    // check input
    if (nums.size() == 0)
      return 0;
    else if (nums.size() == 1)
      return nums[0];
    int* dp = new int[nums.size()];
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      // 因為相鄰的房子不能在同個晚上偷竊
      // 選擇偷第i間(同時偷第i間與第i-2間)
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
  }

  // 節省空間的方法
  int rob(std::vector<int>& nums) {
    // check input
    if (nums.size() == 0)
      return 0;
    else if (nums.size() == 1)
      return nums[0];
    int* dp = new int[nums.size()];
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
  }
};

int main() {
  std::vector<int> nums{2, 7, 9, 3, 1};
  std::cout << Solution().rob(nums) << std::endl;
  return 0;
}