/*
Title: 104. Maximum Depth of Binary Tree

Description:
回傳tree的最大深度

For Example:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Input: root = [1,null,2]
Output: 2

Input: root = []
Output: 0

Input: root = [0]
Output: 1

Opinion:

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
  // int maxDepth(TreeNode *root) {
  //   if (!root) return 0;
  //   return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  // }
  //*****層序遍歷 (Level-order Traversal)*****由上而下一層層的遍歷
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    int ret = 0;
    std::queue<TreeNode *> q{{root}};
    while (!q.empty()) {
      ++ret;
      for (int i = q.size(); i > 0; i--) {
        TreeNode *t = q.front();
        q.pop();
        if (t->left) q.emplace(t->left);
        if (t->right) q.emplace(t->right);
      }
    }
    return ret;
  }
};

int main() {
  // create a tree
  TreeNode left(9);
  TreeNode right_1(15);
  TreeNode right_2(7);
  TreeNode right(20, &right_1, &right_2);
  TreeNode *root = new TreeNode(3, &left, &right);
  // class object
  Solution obj;
  std::cout << obj.maxDepth(root) << std::endl;
}
