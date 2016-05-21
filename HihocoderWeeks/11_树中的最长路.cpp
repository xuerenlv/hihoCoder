#include<iostream>
#include<vector>
using namespace std;



int get_max_path(vector<int> *edge,int current) {
  if(edge[current].size()==0)
    return 0;
  if(edge[current].size()==1)
    return 1+get_max_path(edge,edge[current][0]);

  int len[2]={0};
  for(vector<int>::iterator iter = edge[current].begin();iter!=edge[current].end();iter++){
    int length =1+ get_max_path(edge,*iter);
    if(length>len[0]){
      len[1]=len[0];
      len[0]=length;
    }else if(length>len[1]){
      len[1]=length;
    }
  }
  return len[0]+len[1];
}


int main(int argc,char **argv){
  int n;
  cin>>n;

  vector<int> *edge = new vector<int>[n+1];
  int s,e;
  for(int i=1;i<n;i++){
    cin >> s >> e;
    edge[s].push_back(e);
  }

  std::cout << get_max_path(edge,1) << std::endl;

  return 0;
}
