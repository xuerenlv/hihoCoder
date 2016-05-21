#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n;
int mi_gong[101][101];

int max_profit(){
        int ans = mi_gong[1][1];

        for(int i=2; i<=n; i++) {
                for(int j=1; j<=i; j++) {
                        if(j==1) {
                                mi_gong[i][j]= mi_gong[i-1][j]+mi_gong[i][j];
                        }else{
                                mi_gong[i][j]= max(mi_gong[i-1][j],mi_gong[i-1][j-1])+mi_gong[i][j];
                        }
                        if(ans<mi_gong[i][j])
                                ans=mi_gong[i][j];
                }
        }
        return ans;
}

int main(int argc, char const *argv[]) {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
                for(int j=1; j<=i; j++)
                        scanf("%d", &mi_gong[i][j]);

        printf("%d\n", max_profit());
        return 0;
}
