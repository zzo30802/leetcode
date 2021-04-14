/*
Title: 112. Path Sum

Description:

For Example:

Opinion:
可利用 前序遍歷 (Preorder Traversal) 方法，根->左->右 sum疊加起來如果等於target就是答案
將根的值累加進左右node，直到最後的leaf，總和加起來等於target就返回true

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
  //*****前序遍歷 (Preorder Traversal)***** 用queue
  // bool hasPathSum(TreeNode *root, int targetSum) {
  //   if (!root) return false;
  //   // std::stack<TreeNode*> st{{root}};
  //   std::queue<TreeNode *> q{{root}};
  //   while (!q.empty()) {
  //     TreeNode *t = q.front();
  //     q.pop();
  //     if (!t->left && !t->right) {
  //       if (t->val == targetSum) return true;
  //     }
  //     if (t->left) {
  //       t->left->val += t->val;
  //       q.emplace(t->left);
  //     }
  //     if (t->right) {
  //       t->right->val += t->val;
  //       q.emplace(t->right);
  //     }
  //   }
  //   return false;
  // }

  //*****前序遍歷 (Preorder Traversal)***** 用stack
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) return false;
    std::stack<TreeNode *> st{{root}};
    while (!st.empty()) {
      TreeNode *t = st.top();
      st.pop();
      if (!t->left && !t->right) {
        if (t->val == targetSum) return true;
      }
      // 如果left存在，就使這個left中的val累加root的值
      if (t->left) {
        t->left->val += t->val;
        st.emplace(t->left);
      }
      if (t->right) {
        t->right->val += t->val;
        st.emplace(t->right);
      }
    }
    return false;
  }
};

int main() {
  // create tree
  TreeNode left2(11, new TreeNode(7), new TreeNode(2));
  TreeNode left1(4, &left2, nullptr);
  TreeNode right2(4, nullptr, new TreeNode(1));
  TreeNode right1(8, new TreeNode(13), &right2);
  TreeNode *root = new TreeNode(5, &left1, &right2);

  bool ret = Solution().hasPathSum(root, 22);
  if (ret)
    std::cout << "true" << std::endl;
  else
    std::cout << "false" << std::endl;
}