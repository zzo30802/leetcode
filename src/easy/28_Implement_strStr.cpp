/*
Topic: 28. Implement strStr()

Description:
  Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

For Example:
  Input: haystack = "hello", needle = "ll"
  Output: 2

  Input: haystack = "aaaaa", needle = "bba"
  Output: -1

  Input: haystack = "", needle = ""
  Output: 0

My Opinion:
KMP > Hash > BM > Sunday > Brute-force
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// KMP > Hash > BM > Sunday > Brute-force
class Solution {
 public:
  //*****方法一*****
  // 利用substr來做字串比對
  // int strStr(string haystack, string needle) {
  //   if (haystack.size() < needle.size())
  //     return -1;
  //   for (int i = 0; i < haystack.size(); i++) {
  //     std::string &&str = haystack.substr(i, needle.length());
  //     if (str == needle)
  //       return i;
  //   }
  //   return -1;
  // }

  //*****方法二***** (蠻複雜的)
  //KMP演算法 - 建立pattern的dp陣列，其中記錄了重複字串出現位置
  //https://www.mdeditor.tw/pl/pM0S/zh-tw
  int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size())
      return -1;
    else if (haystack.size() == 0 && needle.size() == 0)
      return 0;
    const int &haystack_length = haystack.size();
    const int &needle_length = needle.size();
    // 建立dp
    std::vector<int> dp;
    dp.resize(needle.size(), 0);  // 分配與needle一樣字串長度的空間
    for (int i = 1; i < needle_length; i++) {
      int j = dp[i - 1];
      while (needle[j] != needle[i]) {  // 找一樣的元素就會跳出迴圈
        std::cout << "i : " << i << std::endl;
        std::cout << "j : " << j << std::endl;
        // 1,0  2,0  3,0
        if (j == 0) break;
        j = dp[j - 1];
      }
      // 發現pattern重複的部分+1
      if (needle[j] == needle[i])
        dp[i] = j + 1;
      else {
        dp[i] = 0;
      }
    }
    // for (const auto &num : dp) {
    //   std::cout << num << ", ";
    // }
    // std::cout << std::endl;
    // kmp
    int i = 0;
    int j = 0;
    while (i < haystack_length) {  // 遍例字串
      // 發現字不一樣
      if (haystack[i] != needle[j]) {
        if (j == 0) {
          i += 1;
          continue;
        }
        j = dp[j - 1];
      } else {  // 發現一樣的字
        i += 1;
        j += 1;
      }
      if (j == needle_length)
        return i - j;
    }
    return -1;
  }
};

int main() {
  std::string haystack("hello");
  std::string needle("ll");
  std::cout << Solution().strStr(haystack, needle) << std::endl;
  return 0;
}