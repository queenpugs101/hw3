#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  if (head == nullptr){
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* curr = head;
  Node* next = head->next;
  curr->next =nullptr;
  llpivot(next, smaller, larger, pivot);

  if(curr->val > pivot){ // if larger add to larger
    curr->next = larger;
    larger = curr;

  }
  else{ // smaller or equal add to smaller
    curr->next = smaller;
    smaller = curr;
  }
 
  head = nullptr;
}
