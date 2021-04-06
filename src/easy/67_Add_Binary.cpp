/*
Title: 67. Add Binary

Description:
Given two binary strings a and b, return their sum as a binary string.

For Example:
Input: a = "11", b = "1"
Output: "100"

Input: a = "1010", b = "1011"
Output: "10101"


My opinion:
因為都是二進位，故只要

*/
#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  std::string addBinary(std::string a, std::string b) {
    std::string res = "";
    int m = a.size() - 1, n = b.size() - 1, carry = 0;
    while (m >= 0 || n >= 0) {
      /*
      1. m >= 0, n >= 0先判斷是否還有字串還沒遍例，如果有就取字串最後一個字ASCII減掉'0'
      如果最後一個字是1的話減去'0'會等於1，反之為0。
      2. sum計算總和，%餘數為目前位置的值，/商數為carry值留到下個迴圈使用。
      */
      int p = m >= 0 ? a[m--] - '0' : 0;
      int q = n >= 0 ? b[n--] - '0' : 0;
      int sum = p + q + carry;
      res = std::to_string(sum % 2) + res;
      std::cout << res << std::endl;
      carry = sum / 2;
    }
    return carry == 1 ? "1" + res : res;
  }

  // practice
  // std::string addBinary(std::string a, std::string b) {
  //   std::string res = "";
  //   int m = a.size() - 1, n = b.size() - 1, carry = 0;
  //   while (m >= 0 || n >= 0) {  // 直到字串遍例完為止
  //     int p = m >= 0 ? a[m--] - '0' : 0;
  //     int q = n >= 0 ? b[n--] - '0' : 0;
  //     int sum = p + q + carry;
  //     res = std::to_string(sum % 2) + res;
  //     carry = sum / 2;  //留到下次的進位
  //   }
  //   return carry == 1 ? "1" + res : res;
  // }
};

int main() {
  std::string a{"11"};
  std::string b{"1"};
  // int aa = 10;
  // int bb = 20;
  // int tt = bb > aa ? a[0] - '0' : 0;
  // std::cout << "tt : " << tt << std::endl;
  // std::cout << (int)(a[0]) << std::endl;
  // std::cout << (int)('0') << std::endl;
  std::cout << Solution().addBinary(a, b) << std::endl;
}