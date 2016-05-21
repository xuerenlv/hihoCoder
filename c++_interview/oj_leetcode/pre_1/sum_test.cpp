//
//  sum_test.cpp
//  My_C++
//
//  Created by NLP (password:NLP) on 1/23/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#include "leetcode.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;



void test_two_sum_1(){
    vector<int> nums={3,2,4};
    int target = 6;
    
    vector<int> re = twoSum(nums, target);
    cout<<re[0]<<"  "<<re[1]<<endl;
}


void test_three_sum(){
    vector<int> nums={0,2,2,3,0,1,2,3,-1,-4,2};
    vector<vector<int>>  re =threeSum(nums);
    
    for(vector<vector<int>>::iterator iter = re.begin();iter<re.end();iter++){
        vector<int> in = *iter;
        cout<<in[0]<<" "<<in[1]<<" "<<in[2]<<endl;

    }

}