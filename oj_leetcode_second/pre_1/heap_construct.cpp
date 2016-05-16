//
//  heap_construct.cpp
//  My_C++
//
//  Created by NLP (password:NLP) on 2/23/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#include <stdio.h>
#include "structure_header.h"

#include "some_my_util.h"
#include <iostream>
using namespace std;


// 堆排序，主方法
void heap_sort(int* array,int len){
    build_max_heap(array, len);
    
    int i = len-1;
    while ( i != 0) {
        swap_my((array+i), (array));
        adjust_max_heap_down(array, i, 0);
        i--;
    }
}

// 构建大根堆
void build_max_heap(int* array,int len){
    for (int i=len/2; i>=0; i--) {
        adjust_max_heap_down(array, len, i);
    }
}

// 大根堆的调整，递归算法
void adjust_max_heap_down(int* array,int len,int start){
    int l = 2 * start;
    int r = 2 * start + 1;
    
    int largest = start;
    if (l < len && array[l]>array[largest]) {
        largest = l;
    }
    if (r < len && array[r]>array[largest]) {
        largest = r;
    }
    
    if ( largest != start ){
        swap_my((array+start),(array+largest));
        adjust_max_heap_down(array, len, largest);
    }
}

// 大根堆的调整，非递归算法
void adjust_max_heap_down_iteration(int* array,int len,int start){
    
    while (start<len){
        int l = 2 * start;
        int r = 2 * start + 1;
    
        int largest = start;
        if (l < len && array[l]>array[largest]) {
            largest = l;
        }
        if (r < len && array[r]>array[largest]) {
            largest = r;
        }
    
        if ( largest != start ){
            swap_my((array+start),(array+largest));
            start = largest;
        }else{                 // 是连贯的，要考虑到建堆的过程
            break;
        }
    }
}

void swap_my(int* a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void test_normal_structure_heap_main(){
        int a[15]={1,4,2,8,1,9,3,0,1,5,1,1,3,0,21};
    
        heap_sort(a, 15);
        Arrays::to_console(a, 15);
    
    cout<<"xhj"<<endl;
}