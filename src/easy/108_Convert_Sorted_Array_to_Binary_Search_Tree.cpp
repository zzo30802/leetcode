/*
Title: 108. Convert Sorted Array to Binary Search Tree

Descriptoion:
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
For Example:

Opinion:
height-balanced binary search tree其每個node的兩個subtrees的深度相差不超過2
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
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
  //*****recursive 1*****
  // TreeNode *sortedArrayToBST(vector<int> &nums) {
  //   return CreateNode(nums, 0, nums.size() - 1);
  // }
  //*****recursive 2*****
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) return NULL;
    int mid = nums.size() / 2;
    TreeNode *cur = new TreeNode(nums[mid]);
    std::vector<int> left(nums.begin(), nums.begin() + mid);
    std::vector<int> right(nums.begin() + mid + 1, nums.end());
    cur->left = sortedArrayToBST(left);
    cur->right = sortedArrayToBST(right);
    return cur;
  }

  void PrintTree(TreeNode *root) {
    // std::vector<int> ret;
    if (!root) return;
    std::queue<TreeNode *> q{{root}};
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();
      if (node) std::cout << node->val << " ";
      if (node->left) q.emplace(node->left);
      if (node->right) q.emplace(node->right);
    }
    std::cout << std::endl;
  }

 private:
  // 找出left & right的mid為中心建立node，node->left和node->right呼叫此function繼續重複到left > rught為止(表示vector所有元素已經遍歷過了)
  TreeNode *CreateNode(vector<int> &nums, int left, int right) {
    if (left > right) return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *cur = new TreeNode(nums[mid]);
    cur->left = CreateNode(nums, left, mid - 1);
    cur->right = CreateNode(nums, mid + 1, right);
    return cur;
  }
};

int main() {
  std::vector<int> nums{-10, -3, 0, 5, 9};
  TreeNode *ret = Solution().sortedArrayToBST(nums);
  Solution().PrintTree(ret);
}