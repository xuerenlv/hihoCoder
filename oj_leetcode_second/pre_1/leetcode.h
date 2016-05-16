//
//  leetcode.h
//  My_C++
//
//  Created by NLP (password:NLP) on 1/23/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#ifndef My_C___leetcode_h
#define My_C___leetcode_h

#include <vector>
using namespace std;


//******************************************************************* first start
// two sum 1
vector<int> twoSum(vector<int>& nums, int target); // 1，二叉查找也是可以的 O（nlog（n）＋log（n））； 2，基于hash的方法也是可以的 O（n）
void test_two_sum_1();


// three sum 15
vector<vector<int>> threeSum(vector<int>& nums);
void test_three_sum();

//18. 4Sum
vector<vector<int>> fourSum(vector<int>& nums, int target);

//16. 3Sum Closest
int threeSumClosest(vector<int>& nums, int target);
//******************************************************************* first end




//******************************************************************* second start
//121. Best Time to Buy and Sell Stock
int maxProfit(vector<int>& prices);

//122. Best Time to Buy and Sell Stock II
int maxProfit_122(vector<int>& prices);

//123. Best Time to Buy and Sell Stock III
int maxProfit_123(vector<int>& prices);
int maxProfit_123_use(vector<int>& prices,int start,int end);
void maxProfit_123_test();

//188. Best Time to Buy and Sell Stock IV
int maxProfit(int k, vector<int>& prices);

//******************************************************************* second end




#endif
