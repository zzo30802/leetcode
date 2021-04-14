/*
https://leetcode.com/problems/same-tree/submissions/
https://github.com/grandyang/leetcode/issues/100
Title: 100. Same Tree

Description:

For Example:

Opinion:

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
  //*****我的方法***** 太複雜，需要一個個檢查node是否存在再去檢查其值是否相等
  // bool isSameTree(TreeNode *p, TreeNode *q) {
  //   if (!p || !q)
  //     return false;
  //   else if (!p && !q)
  //     return true;
  //   else if
  //   if (p->left->val == q->left->val)
  //     if (p->right->val == q->right->val)
  //       return true;
  //   return false;
  // }

  //*****recursive***** 利用深度優先搜尋DFS來遞歸
  // bool isSameTree(TreeNode *p, TreeNode *q) {
  //   if (!p && !q)
  //     return true;
  //   else if ((!p && q) || (!q && p))
  //     return false;
  //   else if (p->val != q->val)
  //     return false;  // 比較root
  //   return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  // }

  //*****Binary Tree Preorder Traversal(先序遍歷) root->left->right*****
  // bool isSameTree(TreeNode *p, TreeNode *q) {
  //   std::stack<TreeNode *> st;
  //   st.push(p);
  //   st.push(q);
  //   while (!st.empty()) {
  //     q = st.top();
  //     st.pop();
  //     p = st.top();
  //     st.pop();
  //     if (!p && !q) continue;  // p, q都nullptr時
  //     if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
  //     // p, q都存在的話就檢查其leaf的內容
  //     st.push(p->right);
  //     st.push(q->right);
  //     st.push(p->left);
  //     st.push(q->left);
  //   }
  //   return true;
  // }

  //*****Binary Tree Inorder Traversal(中序遍歷) left -> root -> right*****
  // bool isSameTree(TreeNode *p, TreeNode *q) {
  //   std::stack<TreeNode *> st;
  //   while (p || q || !st.empty()) {  // p,q,st如果全部都為空就跳出while
  //     while (p || q) {
  //       // 檢查p和q是否一樣 (利用or的特性:一旦發現為true，後面都不會進行判斷，所以可以先判斷是否為nullptr再判斷值是否相等)
  //       if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
  //       st.push(p);
  //       st.push(q);
  //       p = p->left;
  //       q = q->left;
  //     }
  //     p = st.top();
  //     st.pop();
  //     q = st.top();
  //     st.pop();
  //     p = p->right;
  //     q = q->right;
  //   }
  //   return true;
  // }

  // XXXXXX 很難懂
  //*****Binary Tree Postorder Traversal(後序遍歷) left -> right -> root *****
  bool isSameTree(TreeNode *p, TreeNode *q) {
    std::stack<TreeNode *> st1, st2;
    TreeNode *head1, *head2;
    while (p || q || !st1.empty() || !st2.empty()) {
      while (p || q) {
        if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
        st1.push(p);
        st2.push(q);
        p = p->left;
        q = q->left;
      }
      p = st1.top();
      q = st2.top();
      if ((!p->right || p->right == head1) && (!q->right || q->right == head2)) {
        st1.pop();
        st2.pop();
        head1 = p;
        head2 = q;
        p = nullptr;
        q = nullptr;
      } else {
        p = p->right;
        q = q->right;
      }
    }
    return true;
  }

  TreeNode *make_tree(std::vector<int> v) {
    TreeNode *root = new TreeNode(v[0]);
    for (int i = 1; i < v.size(); i++) {
      Insert(&root, v[i]);
    }
    return root;
  }

 private:
  //
  void Insert(TreeNode **root, int val) {
    std::queue<TreeNode *> q;
    q.push(*root);
    while (q.size()) {
      TreeNode *temp = q.front();
      q.pop();
      // left
      if (!temp->left) {  // 如果沒有 左子node
        temp->left = new TreeNode(val);
        // if (val != NULL)
        //   temp->left = new TreeNode(val);
        // else
        //   temp->left = new TreeNode(0);
        return;
      } else {
        q.push(temp->left);
      }
      // right
      if (!temp->right) {  // 如果沒有 右子node
        temp->right = new TreeNode(val);
        // if (val != NULL)
        //   temp->right = new TreeNode(val);
        // else
        //   temp->right = new TreeNode(0);
        return;
      } else {
        q.push(temp->right);
      }
    }
  }
};

int main() {
  //*********一般的方式建立tree*********
  // TreeNode p_left(2);
  // TreeNode p_right(3);
  // TreeNode *p = new TreeNode(1, &p_left, &p_right);
  // TreeNode q_left(2);
  // TreeNode q_right(3);
  // TreeNode *q = new TreeNode(1, &q_left, &q_right);
  // bool ret = Solution().isSameTree(p, q);

  //*********利用queue和vector建立tree********
  std::vector<int> p_vec{1, 2, 3};
  std::vector<int> q_vec{1, 2, 3};
  TreeNode *p = Solution().make_tree(p_vec);
  TreeNode *q = Solution().make_tree(q_vec);
  bool ret = Solution().isSameTree(p, q);
  if (ret) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
}