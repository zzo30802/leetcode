/*
Title: 111. Minimum Depth of Binary Tree

Description:

For Example:

Opinion:
這題跟第104題很像，只是改成搜尋最小深度
*/
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
  //*****recursive*****
  // int minDepth(TreeNode *root) {
  //   if (!root)
  //     return 0;
  //   else if (!root->left)
  //     return 1 + minDepth(root->right);
  //   else if (!root->right)
  //     return 1 + minDepth(root->left);
  //   return 1 + std::min(minDepth(root->left), minDepth(root->right));
  // }

  //*****層序遍歷 (Level-order Traversal)*****由上而下一層層的遍歷
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    int ret = 0;
    std::queue<TreeNode *> q{{root}};
    while (!q.empty()) {
      ++ret;
      // 從queue中遍歷每個node檢查其下的left & right
      for (int i = q.size(); i > 0; i--) {
        TreeNode *t = q.front();
        q.pop();
        if (!t->left && !t->right) return ret;
        if (t->left) q.emplace(t->left);
        if (t->right) q.emplace(t->right);
      }
    }
    return -1;
  }
};

int main() {
  // create tree
  TreeNode right_subtree1(20, new TreeNode(15), new TreeNode(7));
  TreeNode *root = new TreeNode(3, new TreeNode(9), &right_subtree1);

  std::cout << Solution().minDepth(root) << std::endl;
}