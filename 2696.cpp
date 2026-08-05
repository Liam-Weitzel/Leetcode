#include <string>

struct Node {
  Node* next;
  Node* prev;
  char val;
};

class Solution { // Aug 05, 2026
public:
  int minLength(std::string s) {
    //Doubly linkedlist as it has O(1) removal in the middle unlike string or stacks
    //I think we can be greedy and just always take the first best.

    //Create linked list
    Node* head = new Node();
    Node* iter = head;
    for(char i : s) {
      Node* next = new Node();
      next->prev = iter;
      iter->next = next;
      iter->val = i;
      iter = next;
    }

    //Traverse and remove until nothing can be romeved anymore
    iter = head;
    while(iter) {
      if(iter->prev) {
        if((iter->prev->val == 'A' && iter->val == 'B')
        || (iter->prev->val == 'C' && iter->val == 'D')) {
          if(iter->prev->prev && iter->next) {
            iter->prev->prev->next = iter->next;
            iter->next->prev = iter->prev->prev;
          } else if(!iter->prev->prev && iter->next) {
            head = iter->next;
            iter->next->prev = nullptr;
          } else if(iter->prev->prev && !iter->next) {
            iter->prev->prev->next = nullptr;
          }
          iter = head;
        } else iter = iter->next;
      } else iter = iter->next;
    }

    iter = head;
    int res = 0;
    while(iter->next) {
      res++;
      iter = iter->next;
    }

    //Check & return size
    return res;
  }
};
