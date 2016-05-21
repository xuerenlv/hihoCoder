#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

// Eratosthenes筛法
int eratosthesnes(int n){
  if(n<1)
    return 0;
  bool flag[n+1];
  memset(flag,true,sizeof(flag));

  int prim_count = 0;
  for(int i=2;i<=n;i++){
    if(flag[i]){
      prim_count++;
      int multi = 2;
      while (multi*i<=n) {
        flag[multi*i]=false;
        multi++;
      }
    }
  }

  return prim_count;
}


// better Eular筛法'
int eular(int n){
  if(n<1)
    return 0;
  bool flag[n+1];
  memset(flag,true,sizeof(flag));

  int prim_count = 0;
  std::vector<int> prim_list;
  for(int i=2;i<=n;i++){
    if(flag[i]){
      prim_count++;
      prim_list.push_back(i);
    }

    for(int j=0;j<prim_count;j++){
      if(i*prim_list[j]>n)
        break;
      flag[i*prim_list[j]]=false;
    }
  }

  return prim_count;
}


int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  // std::cout << eratosthesnes(n) << std::endl;
  std::cout << eular(n) << std::endl;
  return 0;
}
