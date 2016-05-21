//
//  link_list_qu.cpp
//  My_C++
//
//  Created by NLP (password:NLP) on 2/21/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#include "link_list_qu.h"
#define NULL 0



//2. Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode new_head(-1);
    ListNode *p = &new_head;
    int wei = 0,sum=0;
    while(l1!=NULL && l2!=NULL)
    {
        sum = l1->val+l2->val+wei;
        wei=sum/10;
        sum%=10;
        l1=l1->next;
        l2=l2->next;
        p->next=new ListNode(sum);
        p=p->next;
    }
    while( l2!=NULL)
    {
        sum = l2->val+wei;
        wei=sum/10;
        sum%=10;
        l2=l2->next;
        p->next=new ListNode(sum);
        p=p->next;
    }
    while(l1!=NULL)
    {
        sum = l1->val+wei;
        wei=sum/10;
        sum%=10;
        l1=l1->next;
        p->next=new ListNode(sum);
        p=p->next;
    }
    p->next = wei==0?NULL :new ListNode(wei);
    return new_head.next;
}