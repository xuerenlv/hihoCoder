//
//  two_sum_1.cpp
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



// two sum 1
vector<int> twoSum(vector<int> &nums, int target) {
  vector<int> re(2);
  map<int, int> container;

  for (int i = 0; i < nums.size(); i++) {
    map<int, int>::iterator iter = container.find(target - nums[i]);
    if (iter != container.end()) {
      re[0] = iter->second + 1;
      re[1] = i + 1;
      return re;
    }
    container[nums[i]] = i;
  }

  return re;
}

// three sum 15
vector<vector<int>> threeSum_overtime(vector<int> &nums) {
  vector<vector<int>> re;

  if (nums.size() < 3)
    return re;

  sort(nums.begin(), nums.end()); // 既然已经排序好了，为何不去用二插查找
  for (int i = 0; i < nums.size() - 2; i++) {
    int a = nums[i];
    if (a > 0)
      break;

    vector<int> container;
    for (int j = i + 1; j < nums.size() - 1; j++) {
      int c = nums[j];
      if (find(container.begin(), container.end(), -c - a) != nums.end()) {
        vector<int> in(3);
        in.push_back(a);
        in.push_back(-c - a);
        in.push_back(c);
        re.push_back(in);
      } else {
        container.push_back(c);
      }
    }
  }

  return re;
}

// 二叉查找 速度好一些
vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> re;

  if (nums.size() < 3)
    return re;

  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 2; i++) {
    int a = nums[i];
    if (a > 0)
      break;
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    long start = i + 1;
    long end = nums.size() - 1;
    while (start < end) {
        int sum = nums[start] + nums[end] + nums[i];
        if ( sum == 0) {
        re.push_back({a, nums[start], nums[end]});

        start++;
        end--;
        while (start < nums.size() && nums[start] == nums[start - 1]) {
          start++;
        }
        while (end >= 0 && nums[end] == nums[end + 1]) {
          end--;
        }

      } else if (sum > 0) {
        end--;
      } else {
        start++;
      }
    }
  }

  return re;
}



//18. 4Sum
vector<vector<int>> fourSum(vector<int>& nums, int target){
  vector<vector<int>> re;

  if (nums.size() < 4)
    return re;

  sort(nums.begin(), nums.end());
  for (int k = 0; k < nums.size() - 3; k++) {
    int f_a = nums[k];
    if (k > 0 && nums[k] == nums[k - 1])
      continue;

    for (int i = k + 1; i < nums.size() - 2; i++) {
      int a = nums[i];
      if (i > k + 1 && nums[i] == nums[i - 1])
        continue;

      long start = i + 1;
      long end = nums.size() - 1;
      while (start < end) {
        int sum = nums[start] + nums[end] + a + f_a;
        if (sum == target) {
          re.push_back({f_a, a, nums[start], nums[end]});

          start++;
          end--;
          while (start < nums.size() && nums[start] == nums[start - 1]) {
            start++;
          }
          while (end >= 0 && nums[end] == nums[end + 1]) {
            end--;
          }

        } else if (sum > target) {
          end--;
        } else {
          start++;
        }
      }
    }
  }

  return re;
}


//16. 3Sum Closest
int threeSumClosest(vector<int>& nums, int target){
  int re = 0;

  if (nums.size() < 3)
    return re;

  int maxval = numeric_limits<int>::max() / 10;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 2; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    long start = i + 1;
    long end = nums.size() - 1;
    while (start < end) {
      int sum = nums[start] + nums[end] + nums[i];
      if (sum == target) {
        return target;
      } else if (sum > target) {
        end--;
      } else {
        start++;
      }
      maxval = abs(maxval - target) < abs(sum - target) ? maxval : target;
    }
  }

  return maxval;
}


