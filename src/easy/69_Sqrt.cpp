/*
Title: 69. Sqrt(x)

Description:
求x的平方根

For Example:
Input: x = 4
Output: 2

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842...,
and since the decimal part is truncated, 2 is returned.

My opinion:

*/

#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 1) return x;
    int left = 0, right = x;
    while (left < right) {
      int mid = left + (right - left) / 2;  // 求中值
      // std::cout << "mid : " << mid << std::endl;
      if (x / mid >= mid)
        left = mid + 1;
      else
        right = mid;
    }
    return right - 1;
  }

  //*****Newton’s method是一種非線性方成求根的方法*****
  // https://ccjou.wordpress.com/2013/07/08/%E7%89%9B%E9%A0%93%E6%B3%95%E2%94%80%E2%94%80%E9%9D%9E%E7%B7%9A%E6%80%A7%E6%96%B9%E7%A8%8B%E7%9A%84%E6%B1%82%E6%A0%B9%E6%96%B9%E6%B3%95/
  // int mySqrt(int x) {
  //   long res = x;
  //   while (res * res > x) {
  //     // std::cout << res << std::endl;
  //     // std::cout << x << std::endl;
  //     // std::cout << res + x / res << std::endl;
  //     res = (res + x / res) / 2;
  //     // std::cout << res << std::endl;
  //   }
  //   return res;
  // }
};

int main() {
  int x = 25;
  std::cout << Solution().mySqrt(x) << std::endl;
}