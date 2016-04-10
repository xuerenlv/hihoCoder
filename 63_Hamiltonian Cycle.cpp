#include<iostream>
#include<vector>
using namespace std;

int ver[13];
vector<int> v[13];
bool visited[13];
int count1 = 0;
int n=0,m=0;

void dfs(int original_start,int start,int alrea_vis){
  visited[start] = true;
  if(++alrea_vis == n){
    // 走完所有的顶点，可以回到起点
    for(vector<int>::iterator iter = v[start].begin();iter!=v[start].end();iter++){
      if (*iter == original_start) {
        count1++;
      }
    }
  }else{
    for(vector<int>::iterator iter = v[start].begin();iter!=v[start].end();iter++){
      if(!visited[*iter]){
        dfs(original_start,*iter, alrea_vis);
      }
    }
  }
  visited[start] = false;
}


int main(int argc, char const *argv[]) {
  cin>>n>>m;

  int s,e;
  for(int i=0;i<m;i++){
    cin>>s>>e;
    v[s].push_back(e);
  }

  for(int i=1;i<=n;i++)
    dfs(i, i, 0);


  cout<<count1<<endl;
  return 0;
}
