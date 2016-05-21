#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

int N,P,W,H;
int* para_size;

bool is_ok(int size){
  int hang_zi_fu = W/size,lie_zi_fu = H/size;

  int sum_hang = 0;
  for(int i=0;i<N;i++){
    sum_hang+=para_size[i]%hang_zi_fu==0?para_size[i]/hang_zi_fu:para_size[i]/hang_zi_fu+1;
    if(sum_hang/lie_zi_fu>P)
      return false;
  }

  return true;
}

int max_size(){
  int min_w_h = min(W,H);

  int left=1,right = min_w_h;
  while (left<right) {
    int mid = (left+right)/2;
    if(is_ok(mid)){
      left = mid;
      if(is_ok(right)){
        left = right;
      }else{
        right--;
      }
    }else{
      right = mid-1;
    }
    // std::cout << left<<"  "<<right << std::endl;
  }
  return left;
}


int main(int argc, char const *argv[]) {
  int n_test_case;

  scanf("%d\n", &n_test_case);

  for(int i=0;i<n_test_case;i++){
    scanf("%d %d %d %d\n", &N,&P,&W,&H);
    para_size = new int[N];
    for(int j=0;j<N;j++){
      scanf("%d", para_size+j);
    }
    printf("%d\n", max_size());
  }

  return 0;
}
