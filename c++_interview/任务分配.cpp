#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

struct Pair{
  int start,end;
};
Pair all_pairs[100002];

bool compare(Pair a,Pair b){
  return a.start < b.start;
}

// merge
int merge(Pair* all_pairs,int n){
  if(n<=1)
    return n;
  sort(all_pairs,all_pairs+n,compare);

  vector<int> ji_lu;
  ji_lu.push_back(all_pairs[0].end);
  for(int i=1;i<n;i++){
    vector<int>::iterator smallest = min_element(ji_lu.begin(),ji_lu.end());
    if(all_pairs[i].start < *smallest){
      ji_lu.push_back(all_pairs[i].end);
    }else{
      *smallest = all_pairs[i].end;
    }
  }

  return (int)ji_lu.size();
}

int main(int argc, char const *argv[]) {
  int n,st,en;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>st>>en;
    all_pairs[i].start = st;
    all_pairs[i].end = en;
  }
  std::cout << merge(all_pairs,n)  << std::endl;
  return 0;
}
