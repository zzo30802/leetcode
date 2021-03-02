#include "common.h"
/*
想法 :
不用管Z字型怎麼走，只要知道返回的結果是根據row來移動，
nRows為4的話表示字母會在這四行之間照順序來回移動，分成
四行來個別存入字串，最後再組合起來就好
*/
class Solution {
 public:
  std::string convert(std::string s, int nRows) {
    // check
    if (nRows <= 1 || s.size() <= nRows) return s;

    // 4行vector
    vector<string> ret(nRows);

    int current_row = 0;
    int step = 1;  // 表示current_row移動方向

    for (int i = 0; i < s.size(); i++) {
      // 在最後一行，往上移動
      if (current_row == nRows - 1) step = -1;
      // 在第一行，往下移動
      if (current_row == 0) step = 1;
      cout << current_row << endl;
      ret[current_row] += s[i];
      current_row += step;
    }

    string result;
    for (int i = 0; i < nRows; i++) {
      result += ret[i];
    }
    return result;
  }
};

int main() {
  std::shared_ptr<Solution> obj = std::make_shared<Solution>();
  const std::string s = "PAYPALISHIRING";
  int nRows = 3;
  std::cout << s << " : " << obj->convert(s, nRows) << endl;
}