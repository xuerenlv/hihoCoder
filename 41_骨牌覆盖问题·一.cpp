#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[]) {
  long long s=1,e=1,n,t;
  cin>>n;

  if (n==0) {
    std::cout << 0 << std::endl;
  }else if (n==1){
    std::cout << e << std::endl;
  }

  while (--n != 1) {
    t=e;
    e=s+t;
    s=t;
  }

  std::cout << (s+e)%19999997 << std::endl;

  return 0;
}
