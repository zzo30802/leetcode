/*
Title: 70. Climbing Stairs

Description:

For Example:

Opinion:

*/
#include <iostream>
#include <string>
#include <vector>

class Solution {
 public:
  //*****使用dp*****
  int climbStairs(int n) {
    if (n <= 1) return 1;
    std::vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
      dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp.back();
  }
  //*****因dp比較花費空間，顧可藉由下列方法優化*****
  // 整個算法只使用兩個int型別儲存計算值
  // int climbStairs(int n) {
  //   int a = 1, b = 1;
  //   while (n--) {
  //     b += a;
  //     a = b - a;
  //   }
  //   return a;
  // }
};

void swapFunc(int &m, int &n) {
  int temp;
  temp = m;
  m = n;
  n = temp;
}

int main() {
  int n = 4;
  std::cout << Solution().climbStairs(n) << std::endl;
  return 0;
}