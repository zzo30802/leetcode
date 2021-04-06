#include <iostream>
#include <memory>

// #include "../../include/common.h"
#include "stack"
#include "string"
using namespace std;

/*
// 20. Valid Parentheses
說明 : 輸入的括號(Parentheses)是否按照規格?

範例：
Input: "()"
Output: true

Input: "()[]{}"
Output: true

Input: "(]"
Output: false

Input: "([)]"
Output: false

Input: "{[]}"
Output: true

個人想法：
只要是左半邊的括號先放入stack，讀取到右半邊的括號就
檢查stack中如果沒有其左半邊或stack為空就回傳false
*/
class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> stack;
    for (auto c : s) {
      switch (c) {
        case '(': {
          stack.emplace('(');
          break;
        }
        case '[': {
          stack.emplace('[');
          break;
        }
        case '{': {
          stack.emplace('{');
          break;
        }
        case ')': {
          if (stack.empty() || stack.top() != '(')
            return false;
          stack.pop();  // pop掉最上層的符號，繼續向外檢查
          break;
        }
        case ']': {
          if (stack.empty() || stack.top() != '[')
            return false;
          stack.pop();
          break;
        }
        case '}': {
          if (stack.empty() || stack.top() != '{')
            return false;
          stack.pop();
          break;
        }
      }
    }
    if (!stack.empty())
      return false;
    return true;
  }
};

int main() {
  std::shared_ptr<Solution> &&obj = std::make_shared<Solution>();
  std::string str = "{[]}";
  if (obj->isValid(str)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}