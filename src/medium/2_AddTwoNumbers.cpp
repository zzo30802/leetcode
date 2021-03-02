#define test_idx 0
#include "common.h"
/**
 * https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a
 *single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 **/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

#if test_idx == 0
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int x = 0, y = 0, carry = 0, sum = 0;
    // *h->NULL **t->NULL *t
    ListNode *h = NULL, **t = &h;
    while (l1 != NULL || l2 != NULL) {  // 只要找不到元素就會中止while
      x = this->getValueAndMoveNext(l1);
      y = this->getValueAndMoveNext(l2);

      sum = carry + x + y;

      // 計算下一個點的元素
      ListNode *node = new ListNode(sum % 10);  // 計算除10的餘數
      *t = node;                                // 此點的ptr指向node
      t = (&node->next);

      carry = sum / 10;  // 目前節點的值加起來有沒有超過10
    }

    // if (carry > 0) {
    //   ListNode *node = new ListNode(carry % 10);
    //   *t = node;
    // }
    return h;
  }

  // 列印ListNode
  void printList(ListNode *node) {
    while (node != NULL) {
      cout << node->val << " ";
      node = node->next;
    }
    cout << endl;
  }

 private:
  int getValueAndMoveNext(ListNode *&l) {
    int x = 0;
    if (l != NULL) {  // 有元素的話
      x = l->val;     // 儲存目前的值，並return
      l = l->next;    // 將目前位置移動到下一個元素
    }
    return x;
  }
};
int main() {
  cout << "start" << endl;
  std::shared_ptr<Solution> &&obj = make_shared<Solution>();
  // ListNode 1
  ListNode l1(2);
  ListNode l1_1(4);
  ListNode l1_2(3);
  l1.next = &l1_1;
  l1_1.next = &l1_2;
  // ListNode 2
  ListNode l2(5);
  ListNode l2_1(6);
  ListNode l2_2(4);
  l2.next = &l2_1;
  l2_1.next = &l2_2;
  // Add Two Numbers
  ListNode *l3 = obj->addTwoNumbers(&l1, &l2);
  obj->printList(l3);
  return 0;
}
#elif test_idx == 1
class Solution {
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int currentValue = 0;
    int nextValue = 0;
    ListNode *h = NULL, **t = &h;
    while (l1 != NULL || l2 != NULL) {
      int x1 = l1->val;
      int x2 = l2->val;
      l1 = l1->next;
      l2 = l2->next;
      currentValue = nextValue + x1 + x2;
      ListNode *node = new ListNode(currentValue % 10);  //新增一個點
      *t = node;          // 目前節點放入新node的ptr
      t = (&node->next);  // 將指標指到下一個節點位置
    }
  }

 private:
};
int main() {
  cout << "start" << endl;
  std::shared_ptr<Solution> &&obj = make_shared<Solution>();
  // ListNode 1
  ListNode l1(2);
  ListNode l1_1(4);
  ListNode l1_2(3);
  l1.next = &l1_1;
  l1_1.next = &l1_2;
  // ListNode 2
  ListNode l2(5);
  ListNode l2_1(6);
  ListNode l2_2(4);
  l2.next = &l2_1;
  l2_1.next = &l2_2;
  // Add Two Numbers
  ListNode *l3 = obj->addTwoNumbers(&l1, &l2);
  obj->printList(l3);

  // obj->printList(&l1);

  /*
  int *a = NULL;
  int **b = &a;
  std::cout << a << std::endl; // a =0000000000000000
  std::cout << b << std::endl; // b =000000A9B40FFAF8
  std::cout << *b << std::endl;//*b =0000000000000000
  */

  ListNode *h = NULL, **t = &h;
  ListNode *node = new ListNode(10);
  *t = node;
  t = (&node->next);
  std::cout << &node << std::endl;  // 000000A5810FF948
  std::cout << node << std::endl;   // 000001CD330E8340
  std::cout << *t << std::endl;     // 0000000000000000
  std::cout << t << std::endl;      // 000001CD330E8348
  std::cout << &**t << std::endl;   // 0000000000000000
  std::cout << **t << std::endl;
}
#elif test_idx == 2
/*
Input: 1 -> 2 -> 9 -> 9 -> NULL
Output:
Original list is : 1 2 9 9
Resultant list is : 1 3 0 0

Input: 9 -> 9 -> 9 -> 9 -> NULL
Output:
Original list is : 9 9 9 9
Resultant list is : 1 0 0 0 0
*/

// Node of the linked list
struct Node {
  int data;
  Node *next;
};

class Solution {
 public:
  // Function to create a new node
  Node *CreateNode(int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
  }

  void Print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << endl;
      temp = temp->next;
    }
    cout << endl;
  }

  // Function to add one to a number
  Node *AddOne(Node *head) {
    // To store the last node in the linked
    // list which is not equal to 9
    Node *last = NULL;
    Node *cur = head;

    // 找出list中最後一個不等於9的數字
    while (cur->next != NULL) {
      if (cur->data != 9) {
        last = cur;
      }
      cur = cur->next;
    }

    // If last node is not equal to 9
    // add 1 to it and return the head
    if (cur->data != 9) {
      cur->data++;
      return head;
    }

    // If list is of the type 9 -> 9 -> 9 ...
    // 在list最前面加上一個0的node
    if (last == NULL) {
      last = new Node();
      last->data = 0;
      last->next = head;
      head = last;
    }
    last->data++;
    last = last->next;
    while (last != NULL) {  // 遍歷list
      last->data = 0;
      last = last->next;
    }
    return head;
  }

 private:
};
#endif
