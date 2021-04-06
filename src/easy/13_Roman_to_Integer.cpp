#include "common.h"
// https://sravyadivakarla.medium.com/roman-to-integer-c-c94dad7d6eed

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.

只要小的字母在大的字母前面就是減
*/
class Solution {
 public:
  // int romanToInt(string s) {
  //   int res{0};
  //   for (std::string::iterator iter = s.begin(); iter < s.end(); iter++) {
  //     // std::cout << *iter << std::endl; // print
  //     switch (*iter) {  // char
  //                       // accumulate
  //       case 'I':
  //         res += res >= 5 ? 1 : 1;
  //         break;
  //       case 'V':
  //         res += 5;
  //         break;
  //       case 'X':
  //         res += 10 * (res >= 50 ? -1 : 1);
  //         break;
  //       case 'L':
  //         res += 50;
  //         break;
  //       case 'C':
  //         res += 100 * (res >= 500 ? -1 : 1);
  //         break;
  //       case 'D':
  //         res += 500;
  //         break;
  //       case 'M':
  //         res += 1000;
  //         break;
  //     }
  //   }
  //   return res;
  // }

  int romanToInt(string s) {
    map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int total = 0;
    for (int i = 0; i < s.length(); i++) {
      if (m[s[i + 1]] <= m[s[i]])
        total += m[s[i]];
      else
        total -= m[s[i]];
    }
    return total;
  }
};

int main(int argc, char *argv[]) {
  std::string &&str = argv[1];
  std::cout << "input string : " << str << std::endl;

  std::shared_ptr<Solution> &&obj = std::make_shared<Solution>();
  const int &&result = obj->romanToInt(str);
  std::cout << "result: " << result << std::endl;
  return 0;
}