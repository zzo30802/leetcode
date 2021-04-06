/*
Title: 58. Length of Last Word    

Description:
Given a string s consists of some words separated by spaces,
return the length of the last word in the string.
If the last word does not exist, return 0.

For Example:
Input: s = "Hello World"
Output: 5

Input: s = " "
Output: 0

My opinion:

*/
#include <iostream>
#include <string>
#include <vector>
class Solution {
 public:
  // int lengthOfLastWord(std::string s) {
  //   int left = 0, right = (int)s.size() - 1, res = 0;
  //   while (s[left] == ' ') ++left;
  //   while (s[right] == ' ') --right;
  //   for (int i = left; i <= right; ++i) {
  //     if (s[i] == ' ')
  //       res = 0;
  //     else
  //       ++res;
  //   }
  //   return res;
  // }

  int lengthOfLastWord(std::string s) {
    int left = 0, right = (int)s.size() - 1, res = 0;
    while (s[left] == ' ') ++left;    // 把左邊的space拿掉
    while (s[right] == ' ') --right;  // 把右邊的space拿掉
    // 從left往right搜尋，如果遇到space的話，res歸零
    for (int i = left; i <= right; i++) {
      if (s[i] == ' ')
        res = 0;
      else
        res++;
    }
    return res;
  }
};

int main() {
  std::string str("Hellosdf sdf World");  // Hellosdf sdf World
  std::cout << Solution().lengthOfLastWord(str) << std::endl;
  return 0;
}