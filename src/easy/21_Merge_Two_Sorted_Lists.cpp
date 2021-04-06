#include <iostream>
#include <memory>
#include <string>
/*
Title: 21. Merge Two Sorted Lists 

Description: 
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the
first two lists.

For example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

About my opinion:

*/

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  //*****方法一: 用recursive的方法*****
  // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  //   // 其中一個linked list只要為空就回傳另一個list
  //   if (!l1) return l2;
  //   if (!l2) return l1;
  //   //
  //   if (l1->val < l2->val) {  // l1->val最小
  //     l1->next = mergeTwoLists(l1->next, l2);
  //     return l1;
  //   } else {
  //     l2->next = mergeTwoLists(l2->next, l1);
  //     return l2;
  //   }
  // }

  //*****方法二: *****
  // 建立一個新的linked list，比較兩個list元素並把小的加入新list中
  // 由於有可能兩個list不一樣長，當其中一個先完成後，將另一個list剩下的元素直接排入新list
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(-1), *cur = dummy;
    // 當兩個linked list都還有值
    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;  // 較小元素當list起點
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    // while結束後表示一定有其中一個list已經結束，找到剩下的list接到cur後面
    cur->next = l1 ? l1 : l2;
    return dummy->next;
  }

  void PrintListNode(ListNode* l) {
    ListNode* node = l;
    while (node != 0) {
      std::cout << node->val << ", ";
      node = node->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  std::shared_ptr<Solution>&& obj = std::make_shared<Solution>();
  // l1
  ListNode l1(1);
  ListNode l1_0(2);
  ListNode l1_1(4);
  l1.next = &l1_0;
  l1_0.next = &l1_1;
  // l2
  ListNode l2(1);
  ListNode l2_0(3);
  ListNode l2_1(4);
  l2.next = &l2_0;
  l2_0.next = &l2_1;

  ListNode* ret_list = obj->mergeTwoLists(&l1, &l2);
  obj->PrintListNode(ret_list);
  return 0;
}