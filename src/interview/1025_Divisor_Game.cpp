/*
Easy

https://leetcode.com/problems/divisor-game/
https://blog.csdn.net/myRealization/article/details/107580588
Title: 1025. Divisor Game

Description:
Alice和Bob玩因數遊戲，由Alice開始隨意選擇一個數n，接下來換對方選擇一個n的因數x，須滿足以下兩條件
0 < x < n
n % x == 0
直到無法再取出因數為止，設計一個function輸出為Alice是否為贏。

For Example:

Opinion:
dp儲存了Alice每個數字開局的結果。
利用dp的方式來儲存每個結果，並利用for迴圈遍例，
if()的條件為：
只要i % j == ，表示j為i的因數，根據遊戲規則，黑板上下一個數字是i-j，
所以利用dp[i - j]去檢查結果是true/false，一旦檢查到false就表示這個i-j的數會使Bob拿到1，這樣Alice就輸了
所以表示dp[i-j]是個對於Alice來說必輸的狀態，故dp[i]=true(ex: dp[3], dp[5], dp[7])
*/
#include <iostream>
#include <vector>
class Solution {
 public:
  //*****Simple Method*****
  // bool divisorGame(int n) {
  //   return n % 2 == 0;
  // }

  bool divisorGame(int n) {
    std::vector<bool> dp(n + 1);
    // dp儲存了Alice每個數字開局的結果
    dp[0] = true;
    dp[1] = false;
    for (int i = 2; i <= n; + i++) {
      for (int j = 1; j < i; j++) {
        // 一旦i%j==0，且dp[i-j]為false(表示Alice輸)
        if (i % j == 0 && !dp[i - j]) {
          std::cout << i << std::endl;
          dp[i] = true;
          break;
        }
      }
    }
    std::cout << "dp.size() : " << dp.size() << std::endl;
    return dp[n];
    // return false;
  }

 private:
  std::vector<int> FindDivisors(int n) {
    std::vector<int> new_vec;
    for (int i = n / 2; i > 1; i--) {
      if (n % i == 0) {
        new_vec.emplace_back(i);
        // std::cout << i << " ";
      }
    }
    return new_vec;
  }

  int FindMaxDivisor(const int &n) {
    for (int i = n / 2; i > 1; i--) {
      if (n % i == 0) return i;
    }
  }
};

int main() {
  int num = 30;
  bool ret = Solution().divisorGame(num);
  if (ret) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
}