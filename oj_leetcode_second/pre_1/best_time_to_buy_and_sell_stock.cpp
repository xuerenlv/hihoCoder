//
//  best_time_to_buy_and_sell_stock.cpp
//  My_C++
//
//  Created by NLP (password:NLP) on 1/24/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#include "leetcode.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


//121. Best Time to Buy and Sell Stock  一次交易
int maxProfit(vector<int>& prices){
    int max_profit = 0;
    if (prices.size()<2) {
        return max_profit;
    }
    
    int max_price = prices[prices.size()-1];
    for (long i=prices.size()-2; i>=0; i--) {
        if (prices[i]>=max_price) {
            max_price=prices[i];
        }else{
            max_profit=max(max_profit,max_price-prices[i]);
        }
    }
    
    return max_profit;
}

int maxProfit_2(vector<int>& prices) {
    int ret = 0, max = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        ret += prices[i] - prices[i-1];
        if(ret < 0) ret = 0;
        if(ret > max) max = ret;
    }
    return max;
}


//122. Best Time to Buy and Sell Stock II 无限次交易
int maxProfit_122(vector<int>& prices){
    int max_profit = 0;
    
    if (prices.size()<2) {
        return max_profit;
    }
    
    for (int i=1; i<prices.size(); i++) {
        max_profit += max(0,prices[i]-prices[i-1]);
    }
    
    return max_profit;
}

//123. Best Time to Buy and Sell Stock III  最多2次交易
int maxProfit_123_use(vector<int>& prices,int start,int end){
    int max_profit = 0;
    if (end-start<1) {
        return max_profit;
    }
    
    int max_price = prices[end];
    for (long i=end-1; i>=start; i--) {
        
        if (prices[i]>=max_price) {
            max_price=prices[i];
        }else{
            max_profit=max(max_profit,max_price-prices[i]);
        }
    }
    
    return max_profit;
}

int maxProfit_123(vector<int>& prices){
    int max_profit = 0;
    
    if (prices.size()<2) {
        return max_profit;
    }
    
    for (int i=1; i<prices.size(); i++) {
        if(i!=1 && prices[i]<=prices[i-1]) // 过滤掉没意义的
            continue;
        
        max_profit = max(max_profit,maxProfit_123_use(prices,0,i)+maxProfit_123_use(prices, i+1, (int)prices.size()-1));
    }

    return max_profit;
}

void maxProfit_123_test(){
    vector<int> nums={1,2};
    
    cout<<"xhj"<<maxProfit_123_use(nums, 0, 1)<<endl;
    cout<<maxProfit_123(nums)<<endl;
}


//188. Best Time to Buy and Sell Stock IV  最多k次交易
int maxProfit_all(vector<int> &prices) {
    int n = prices.size();
    int sum = 0;
    for(int i = 1;i < n;i++){
        if(prices[i] > prices[i-1]){
            sum += prices[i] - prices[i-1];
        }
    }
    return sum;
}

// 在心中模拟出 profit 的增长过程
int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    if(k >= n/2){
        return maxProfit_all(prices);
    }
    int dp[2][n+1];
    memset(dp,0,sizeof(dp));
    for(int t = 1; t <= k; t++){
        int cur_max = 0x80000000;
        dp[t%2][0] = 0;
        for(int i = 0; i < n; i++){
            dp[t%2][i+1] = max(dp[(t+1)%2][i+1],max(dp[t%2][i],prices[i] + cur_max));
            cur_max = max(cur_max,dp[(t+1)%2][i] - prices[i]);
        }
    }
    return dp[k%2][n];
}
