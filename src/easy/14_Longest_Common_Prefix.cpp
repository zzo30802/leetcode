#include "../../include/common.h"
/*

*/
class Solution {
 public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) return "";
    for (size_t i = 0; i < strs.front().size(); ++i) {
      for (const auto &str : strs)
        // i == str.size() : 表示如果字串全部相等
        // str.at(i) != strs.front().at(i)) : 如果目前字母對比不一樣，則回傳起始字母到上個字母的字串
        if (i == str.size() || str.at(i) != strs.front().at(i))
          return strs.front().substr(0, i);
    }
    return strs.front();
  }
};

int main(int argc, char *argv[]) {
  std::vector<std::string> str_vec;
  str_vec.emplace_back("flower");
  str_vec.emplace_back("flow");
  str_vec.emplace_back("flight");

  std::shared_ptr<Solution> &&obj = std::make_shared<Solution>();
  std::string ret = obj->longestCommonPrefix(str_vec);
  std::cout << "ret : " << ret << std::endl;
  return 0;
}
