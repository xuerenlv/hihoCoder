#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int n,m;

int max_get(int need[],int value[]){
    int best[n+1][m+1];

    for(int j=0;j<=m;j++)
        best[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j<need[i-1]){
                best[i][j]=best[i-1][j];
            }else{
                best[i][j]=max(best[i-1][j],best[i-1][j-need[i-1]]+value[i-1]);
            }
        }
    }

    return best[n][m];
}


int main(int argc,char **argv){
    cin>>n>>m;
    int need[n],value[n];

    for(int i = n;i>0;i--){
        cin >> need[i-1]>>value[i-1];
    }

    cout<<max_get(need,value)<< endl;
    return 0;
}
