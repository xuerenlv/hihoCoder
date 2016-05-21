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

// 1.4 assum has sufficient space
void swapSpace(char* re_str){
  int len = 0;
  while(re_str[len]!='\0')
    len++;

  bool flag = true;
  int index = len-1;
  while(len > 0){
    if(re_str[len-1]==' ' && !flag){
      re_str[index--] = '0';
      re_str[index--] = '2';
      re_str[index--] = '%';
    }else{
      flag = false;
      re_str[index--] = re_str[len-1];
    }
    len--;
  }
}

// 1.5
string compressStr(string ori_str){
  string new_str = "";
  int len_new = 0,len_ori = ori_str.size();

  int count = 0;
  char pre = '\0';
  for(int i=0;i<len_ori;i++){
    if(ori_str[i]==pre){
      count++;
    }else{
      if(count != 0 ){
        new_str = new_str+string(1,pre)+to_string(count);
        len_new+=2;
      }

      count = 1;
      pre = ori_str[i];
    }
  }

  return len_new>=len_ori? ori_str:new_str;
}


// 1.6
void rotate90Degree(int *(*grid),int n){
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int temp = grid[i][j];
      grid[i][j] = grid[j][i];
      grid[j][i] = temp;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n/2;j++){
      int left = j,right = n-j-1,temp;
      temp = grid[i][left];
      grid[i][left] = grid[i][right];
      grid[i][right] =temp;
    }
  }
}


// 1.7
void setZero(int *(*grid),int m,int n){
  int row[m],col[n];
  memset(row,0,sizeof(row));
  memset(col,0,sizeof(col));

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(grid[i][j]==0){
        row[i]=1;
        col[j]=1;
      }
    }
  }

  for(int i=0;i<m;i++){
    if(row[i])
      for(int j=0;j<n;j++)
        grid[i][j]=0;
  }

  for(int j=0;j<n;j++){
    if(col[j])
      for(int i=0;i<m;i++)
        grid[i][j]=0;
  }

}


// 1.8

// bool isRotation(string s1,string s2){
//   int len_s1 = s1.size(),len_s2 = s2.size();
//   if(len_s1!=len_s2)
//     return false;
//
//   for(int i = len_s1-1;i>=0;i--){
//     if()
//   }
//
//
// }




int main(int argc, char const *argv[]) {



  return 0;
}
