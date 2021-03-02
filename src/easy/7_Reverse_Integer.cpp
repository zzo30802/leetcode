#include "common.h"

/*
https://leetcode.com/problems/reverse-integer/
https://github.com/haoel/leetcode/blob/master/algorithms/cpp/reverseInteger/reverseInteger.cpp
Given a signed 32-bit integer x,
return x with its digits reversed.
If reversing x causes the value to
go outside the signed 32-bit integer
range [-231, 231 - 1], then return 0.

Assume the environment does not allow you
to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
*/
/*
假設輸入為123
傳入function後，先找到3再2再1
*/
class Solution {
 public:
  int reverse(int x) {
    int ans = 0;
    while (x != 0) {
      int &&r = x % 10;  // 最後一個數字
      // if (ans > INT_MAX/10 || ans < INT_MIN/10) return 0;
      ans = ans * 10 + r;  // 每次loop都會把上一次找到最後的數字往前進位(*10)
      x /= 10;
    }
    return ans > INT_MAX ? 0 : ans;
  }
};

int main(int argc, char *argv[]) {
  const int &&num = std::atoi(argv[1]);
  // cout << INT_MAX / 10 << endl;
  // cout << INT_MIN / 10 << endl;
  std::shared_ptr<Solution> &&obj = std::make_shared<Solution>();
  int &&ret = obj->reverse(num);
  std::cout << "ret : " << ret << std::endl;
}
