/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Title: 83. Remove Duplicates from Sorted List

Description:

For example:

Opinion:

*/

#include <iostream>
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode* next) : val(x), next(next){};
};

class Solution {
 public:
  //*****我自己的解法*****
  // ListNode* deleteDuplicates(ListNode* head) {
  //   ListNode* copy_head = head;
  //   ListNode *h = NULL, **t = &h;
  //   int list_len = 0;
  //   while (head != nullptr) {
  //     list_len++;
  //     head = head->next;
  //   }
  //   std::cout << "list_len : " << list_len << std::endl;

  //   std::vector<bool> check_table;  // to check the number is exist or not.
  //   check_table.resize(list_len, false);
  //   head = copy_head;  // 重置head
  //   while (head != nullptr) {
  //     if (!check_table[head->val]) {  // 如果沒發現元素就新增
  //       std::cout << "head->val : " << head->val << std::endl;
  //       check_table[head->val] = true;
  //       // 新增node排入新的linked_list
  //       ListNode* node = new ListNode(head->val);
  //       *t = node;
  //       t = (&node->next);

  //       head = head->next;
  //     } else {  // 發現有相同元素就跳過
  //       head = head->next;
  //       continue;
  //     }
  //   }
  //   return h;
  // }

  //*****其他方法***** 1 1 2 3 3
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* temp = head;
    while (head->next) {                   // head->next != nullptr
      if (head->val == head->next->val) {  // 目前的字與下一個字一樣
        head->next = head->next->next;
      } else {
        head = head->next;
      }
    }
    return temp;
  }

  // ListNode* deleteDuplicates(ListNode* head) {
  //   /*
  //   1. 根據list最後一個元素的值來建立table空間
  //   2. 讀取每個值，在相應的vector位置設為true
  //   */
  //   if (head == nullptr || head->next == nullptr) return head;
  //   ListNode* temp = head;

  //   // 找list最後一個值
  //   int num = 0;
  //   while (true) {
  //     if (!head->next) {
  //       num = head->val;
  //       break;
  //     }
  //     head = head->next;
  //   }
  //   std::cout << "num : " << num << std::endl;

  //   head = temp;
  //   std::vector<bool> table;
  //   table.resize(num, false);

  //   while (head) {
  //     if (!table[head->val]) {
  //       table[head->val] = true;
  //     }
  //     head = head->next;
  //   }

  //   ListNode *h = nullptr, **t = &h;
  //   for (int i = 0; i < table.size(); i++) {
  //     if (table[i + 1]) {
  //       ListNode* node = new ListNode(i + 1);
  //       *t = node;
  //       t = (&node->next);
  //     }
  //   }
  //   return h;
  // }

  void PrintList(ListNode* head) {
    while (head != nullptr) {
      std::cout << head->val << " ";
      head = head->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  ListNode a1(1);
  ListNode a2(2);
  ListNode a3(3);
  ListNode a4(3);
  ListNode* l1 = new ListNode(1, &a1);
  a1.next = &a2;
  a2.next = &a3;
  a3.next = &a4;

  ListNode b1(1);
  ListNode b2(2);
  ListNode* l2 = new ListNode(1, &b1);
  b1.next = &b2;

  ListNode* ret = Solution().deleteDuplicates(l2);
  // std::cout << ret->val << std::endl;
  Solution().PrintList(ret);
}