//
//  link_list_qu.h
//  My_C++
//
//  Created by NLP (password:NLP) on 2/21/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#ifndef __My_C____link_list_qu__
#define __My_C____link_list_qu__


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
};


//2. Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



#endif /* defined(__My_C____link_list_qu__) */
