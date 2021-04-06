#include "common.h"
/*
input : 121
reverse : 121
isPalindrome : true

input : 123
reverse : 321
isPalindrome : false

input : -101
reverse : 101-
isPalindrome : false
所以有負號的一定不是Palindrome

Constraints:
-231 <= x <= 231 - 1
*/

/*
將數字串reverse後再與原數字串比對是否一樣。
*/
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    int reverse{0}, origin{x};
    do {
      reverse = reverse * 10 + x % 10;
    } while (x /= 10);
    return reverse == origin;
  }
};
int main(int argc, char *argv[]) {
  const int &&num = std::atoi(argv[1]);

  std::shared_ptr<Solution> &&obj = std::make_shared<Solution>();
  if (obj->isPalindrome(num)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}