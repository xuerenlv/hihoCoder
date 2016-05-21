//
//  quick_sort.cpp
//  My_C++
//
//  Created by NLP (password:NLP) on 16/2/28.
//  Copyright (c) 2016年 NLP (password:NLP). All rights reserved.
//

#include <stdio.h>
#include "structure_header.h"

#include "some_my_util.h"
#include <iostream>
using namespace std;




int partion_1(int* arr,int start,int end){
    int qiefen = *(arr+start);
    
    int index = start;
    
    for (int i=start+1 ; i <= end; i++) {
        if (*(i+arr) < qiefen) {
            index++;
            if (i != index) {
                swap_my(index+arr, i+arr);
            }
        }
    }
    
    if (index != start) {
        swap_my(index+arr, start+arr);
    }
    
    return index;
}

void quick_sort(int arr[],int left,int right){
    cout<<left<<"  "<<right<<endl;
    if (left < right) {
        int p = partion_1(arr, left, right);
        cout<<p<<endl;
        quick_sort(arr, left, p-1);
        quick_sort(arr, p+1, right);
    }
}




void test_normal_structure_quick_sort_main(){
    int a[]={4,1,6,2,8,2,8,1};
    quick_sort(a, 0, 8);

    Arrays::to_console(a, 8);
}

