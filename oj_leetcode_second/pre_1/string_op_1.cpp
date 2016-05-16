//
//  string_op_1.cpp
//  My_C++
//
//  Created by NLP (password:NLP) on 2/21/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#include "string_op_1.h"
#include <map>
#include <algorithm>


//67. Add Binary
string addBinary(string a, string b) {
    string::size_type a_len=a.size();
    string::size_type b_len=b.size();
    if(a_len==0)
        return b;
    if(b_len==0)
        return a;
    
    int wei=0,sum=0;
    string re;
    while(a_len>0 && b_len>0)
    {
        sum = wei+(a.at(a_len-1)-'0') +(b.at(b_len-1)-'0');
        wei=sum/2;
        sum=sum%2;
        a_len--;
        b_len--;
        re = (char)(sum+'0')+re;
    }
    while(a_len>0)
    {
        sum = wei+(a.at(a_len-1)-'0') ;
        wei=sum/2;
        sum=sum%2;
        a_len--;
        re = (char)(sum+'0')+re;
    }
    while(b_len>0)
    {
        sum = wei +(b.at(b_len-1)-'0');
        wei=sum/2;
        sum=sum%2;
        b_len--;
        re = (char)(sum+'0')+re;
    }
    return wei==0 ? re:'1'+re;
}

//3. Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(string s){
    if(s.length()<=1)
        return s.length();
    map<char, int> container;
    
    int max_len = 0;
    int start = 0;
    container[s[0]]=0;
    for(int i=1;i<s.length();i++){
        char ch = s[i];
        
        map<char, int>::iterator iter = container.find(ch);
        if ( iter != container.end() && iter->second >= start) {
            max_len = max(max_len, i-start);
            start = iter->second+1;
        }
        
        container[ch] = i;
    }
    int m = (int)s.length()-start;
    max_len = max(max_len, m);
    
    return max_len;
}


//6. ZigZag Conversion
string convert(string s, int nRows){
    if (nRows <= 1)
        return s;
    
    const int len = (int)s.length();
    string *str = new string[nRows];
    
    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]); // string 的追加
        
        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;
        
        row += step;
    }
    
    s.clear(); // 清除原有内容
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }
    
    delete[] str; // 内存泄漏
    return s;
}




//5. Longest Palindromic Substring
string longestPalindrome(string s){
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
        if (s.size() - i <= max_len / 2) break;
        int j = i, k = i;
        while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
        i = k+1;
        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
        int new_len = k - j + 1;
        if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);

}





















//判断一个字符串是不是回文
bool whether_hui_wen(string str){
    int i =0,j=str.length()-1;
    
    while (j>i) {
        if(str[i]!=str[j])
            return false;
        j--;
        i++;
    }
    
    return true;
}



