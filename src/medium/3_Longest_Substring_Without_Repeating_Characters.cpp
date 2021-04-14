// #include "../../include/common.h"
/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Question:
Given a string s, find the length of the longest substring
without repeating
characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring. Example 4:

Input: s = ""
Output: 0
*/

/*
https://ithelp.ithome.com.tw/articles/10220036
想法 :
在字串中跟某字當作模板，逐一搜尋整個字串，直到找到下一個一樣的字，其中這一段距離就是答案了

*/
#define test 0
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
#if test == 0
  int lengthOfLongestSubstring(string s) {
    // 使用ascii值來找相同的字
    int ascii[256];
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      int len = 1;
      memset(ascii, 0, sizeof(ascii));  // 清空成0
      ascii[int(s[i])] = 1;             // ascii code中代表某字母的空間為1，表示出現過該字母
      for (int j = i + 1; j < s.length(); j++) {
        if (ascii[int(s[j])]) {
          if (len > ans) ans = len;
          break;
        }
        ascii[int(s[j])] = 1;
        len++;
        if (j == s.length() - 1 && len > ans) ans = len;
      }
    }
    if (ans == 0) ans = s.length();
    return ans;
  }
#elif test == 1
  int lengthOfLongestSubstring(string s) {
    int ascii[256];
    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
      int len = 1;
      std::memset(ascii, 0, sizeof(ascii));  // 將array初始化為0
      // int(s[i])會將char轉成ascii code，用位置表示是否出現過該字母
      ascii[int(s[i])] = 1;
      for (int j = i + 1; j < s.length(); j++) {
        if (ascii[int(s[j])]) {  // 根據字母的ascii值在array中的位置是否為1
          // 每次找到下一個相同的字時，檢查len有沒有比之前的ans還大，有的話就更新
          if (len > ans) {
            ans = len;
            break;
          }
          // 將搜尋過的字在array中轉成1 (為重複的字表示子字串越長)
          ascii[int(s[j])] = 1;
          len++;
        }
      }
      if (ans == 0) ans = s.length();
      return ans;
    }
    return ans;
  }
#endif
};

int main() {
  const std::string s = "pwwkew";
  std::cout << Solution().lengthOfLongestSubstring(s) << std::endl;

  int ascii[256];
  memset(ascii, 0, sizeof(ascii));
  std::cout << ascii[0] << std::endl;

  // std::shared_ptr<Solution> obj = std::make_shared<Solution>();

  // int ascii[256];
  // std::memset(ascii, 0, sizeof(ascii));
  // // ascii[int(s[0])] = 1;
  // std::cout << s[2] << std::endl;
  // std::cout << int(s[2]) << std::endl;  // 99
  // cout << sizeof(ascii) << endl;        // 1024 = 256 * 4
  // cout << ascii[int(s[2])] << endl;     // 0
  // cout << ascii[0] << endl;

  // int ret = obj->lengthOfLongestSubstring(s);
  // cout << ret << endl;
  return 0;
};