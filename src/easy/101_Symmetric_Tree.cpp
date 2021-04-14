/*
Title: 101. Symmetric Tree

Description:
判斷tree是否為對稱。

For Example:
input:
    1
   / \
  2   2
 / \ / \
3  4 4  3
output: true

input:
    1
   / \
  2   2
   \   \
   3    3
Opinion: false

*/
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
  bool isSymmetric(TreeNode *root) {
    if (!root) return false;
    return isSymmetric(root->left, root->right);
  }

  // 由vector, queue建立tree
  TreeNode *make_tree(std::vector<int> &vec) {
    TreeNode *root;
    for (int i = 0; i < vec.size(); i++) {
      insert(&root, vec[i]);
    }
    return root;
  }

 private:
  // 由此function來比較left和right兩個node有沒有對稱
  bool isSymmetric(TreeNode *left, TreeNode *right) {
    // 如果兩個都為空回傳true
    if (!left && !right)
      return true;
    else if ((!left && right) || (left && !right) || (left->val != right->val))
      return false;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
  }

  // 檢查root下的left和right是否有缺元素，有缺的話就新增node上去
  void insert(TreeNode **root, int val) {
    std::queue<TreeNode *> q;
    q.push(*root);
    while (q.size()) {
      // 如果是迴圈的第一次，這邊會先取出root
      TreeNode *temp = q.front();
      q.pop();
      // 檢查left有沒有缺
      if (!temp->left) {
        temp->left = new TreeNode(val);
        return;
      } else {
        q.push(temp->left);  // 因為已經有left，所以把left排到queue，之後在檢查其下的left和right
      }
      // 檢查right
      if (!temp->right) {
        temp->right = new TreeNode(val);
        return;
      } else {
        q.push(temp->right);
      }
    }
  }
};

int main() {
  TreeNode left_1(3);
  TreeNode left_2(4);
  TreeNode *left = new TreeNode(2, &left_1, &left_2);
  TreeNode right_1(4);
  TreeNode right_2(3);
  TreeNode *right = new TreeNode(2, &right_1, &right_2);
  TreeNode *root = new TreeNode(1, left, right);

  bool ret = Solution().isSymmetric(root);
  if (ret) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
}