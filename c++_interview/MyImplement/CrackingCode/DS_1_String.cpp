#include <iostream>
#include <string>
using namespace std;


// 1.1
bool uniqueStr(string s){
  int unique_rem[26];
  memset(unique_rem,0,sizeof(unique_rem));
  for(size_t i =0;i<s.size();i++){
    unique_rem[s[i]-'a']++;
    if (unique_rem[s[i]-'a']==2) {
      return false;
    }
  }
  return true;
}

// 1.2
void reverseStr(char* str){
  int len = 0;
  while (str[len]!='\0') {
    len++;
  }
  int left = 0,right = len-1;
  while(left<right){
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
  }
}

// 1.3
bool isPermutation(string s1,string s2){
  int len_s1 = s1.size(),len_s2=s2.size();
  if(len_s1!=len_s2)
    return false;

  int temp_re[26];
  memset(temp_re,0,sizeof(temp_re));
  for(int i=0;i<len_s1;i++){
    temp_re[s1[i]-'a']++;
    temp_re[s2[i]-'a']++;
  }
  for(int i=0;i<26;i++){
    if(temp_re[i]!=0)
      return false;
  }
  return true;
}

// 1.4



int main(int argc, char const *argv[]) {

  return 0;
}
