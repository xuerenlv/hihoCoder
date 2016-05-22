#include <iostream>
#include <string>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //  链表排序
    ListNode* sortList(ListNode* head) {
      if(head == NULL)
        return NULL;
      ListNode* mid = getMid(head);
      ListNode* next_mid = mid->next;
      mid->next = NULL;
      return merge(sortList(head),sortList(next_mid));
    }

    // 获取一个链表的中点
    ListNode* getMid(ListNode* head){
      ListNode* p=head,*q=head;
      while(q->next!=NULL && q->next->next!=NULL){
        p = p->next;
        q = q->next->next;
      }
      return p;
    }

    // 合并两个有序链表
    ListNode* merge(ListNode* head_1,ListNode* head_2){
      if(head_1==NULL)
        return head_2;
      if(head_2==NULL)
        return head_1;

      ListNode *new_head;
      if(head_1->val<head_2->val){
        new_head = head_1;
        head_1 = head_1->next;
      }else{
        new_head = head_2;
        head_2 = head_2->next;
      }
      new_head->next = merge(head_1,head_2);
      return new_head;
    }
};



// 2.1 remove duplicates
void removeDuplicates(ListNode* head){
  if(head==NULL || head->next==NULL)
    return;

  ListNode *new_head =head,*new_tail = head,*p=head->next;
  head->next = NULL;

  while(p!=NULL){
    ListNode* q = new_head,*s;
    while(q!=NULL && q->val != p->val){
      q=q->next;
    }
    if(q!=NULL){
      p=p->next;
    }else{
      s=p;
      p=p->next;
      s->next = NULL;
      new_tail->next = s;
      new_tail = new_tail->next;
    }
  }
}



// 2.4  partition list by k
void partionByK(ListNode* head,int k){
  if(head==NULL)
    return;
  ListNode *new_head_1,*new_head_2;
  ListNode *new_tail_1,*new_tail_2;
  ListNode *p = head,*s;
  while(p!=NULL){
    s=p;
    p=p->next;
    s->next = NULL;
    if(p->val<k){
      if(new_head_1 == NULL){
        new_head_1 = s;
        new_tail_1 = s;
      }else{
        new_tail_1 = s;
        new_tail_1 = new_tail_1 -> next;
      }
    }else{
      if(new_head_2 == NULL){
        new_head_2 = s;
        new_tail_2 = s;
      }else{
        new_tail_2 = s;
        new_tail_2 = new_tail_2 -> next;
      }
    }
    new_tail_1 -> next = new_head_2;
  }
}



int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
