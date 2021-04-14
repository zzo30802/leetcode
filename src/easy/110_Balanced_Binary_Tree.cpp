// https://github.com/grandyang/leetcode/issues/110

// 判斷是否為height-balanced binary tree
// 其left, right子樹高度不相差1以上

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr){};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){};
};

class Solution {
 public:
  //*****recursive 1******
  // bool isBalanced(TreeNode *root) {
  //   if (!root) return true;
  //   if (std::abs(GetDepth(root->left) - GetDepth(root->right)) > 1) return false;
  //   return isBalanced(root->left) && isBalanced(root->right);
  // }
  // int GetDepth(TreeNode *root) {
  //   if (!root) return 0;
  //   return 1 + std::max(GetDepth(root->left), GetDepth(root->right));
  // }

  //*****recursive 2*****
  bool isBalanced(TreeNode *root) {
    if (checkDepth(root) == -1)
      return false;
    else
      return true;
  }
  int checkDepth(TreeNode *root) {
    if (!root) return 0;
    int left = checkDepth(root->left);
    if (left == -1) return -1;
    int right = checkDepth(root->right);
    if (right == -1) return -1;
    int diff = abs(left - right);
    if (diff > 1)
      return -1;
    else
      return 1 + std::max(left, right);
  }

  //   TreeNode *VectorToTree(std::vector<int> &nums) {
  //   // check input
  //   if (nums.empty()) return nullptr;
  //   // 最後一個node是否有兩個leaf
  //   int is_last_node_have_two_leaf = nums.size() % 2 == 0 ? false : true;

  //   int index = 1;

  //   // 計算幾個node，再放入queue
  //   int node = nums.size() / 2;
  //   TreeNode *root = new TreeNode(nums[0]);

  //   while (node > 0) {
  //   }
  // }
};

int main() {
  // create tree
  TreeNode right_subtree1(20, new TreeNode(15), new TreeNode(7));
  TreeNode *root = new TreeNode(3, new TreeNode(9), &right_subtree1);

  bool ret = Solution().isBalanced(root);
  if (ret) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
}