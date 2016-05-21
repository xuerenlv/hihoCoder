// 来自算法导论

#include<iostream>
#include<math.h>
using namespace std;

int price[5]={1,3,2,5,4};



int main(int argc,char **argv){
  std::cout << "输入钢条长度：" << std::endl;

  int n;
  std::cin >> n;

  int* r = new int[n+1];
  memset(r,0,20*sizeof(int));
  int p = -1;
  for(int i=1;i<=n;i++){
    p = -1;
    for(int j=1;j<=i && j<= 5;j++){
      p = max(p,r[i-j]+price[j-1]);
    }
    r[i] = p;
  }

  std::cout << "profit: "<<r[n] << std::endl;

  return 0;
}
