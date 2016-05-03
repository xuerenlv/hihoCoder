#include <iostream>
using namespace std;





int remain(int n,int k){
        if(n==1)
                return 0;

        int pre=0,next;
        for(int i=2; i<=n; i++) {
                next = (pre+k)%i;
                pre = next;
        }

        return next;
}






int main(int argc, char const *argv[]) {

        int n,a,b;
        cin>>n;
        for(int i=0; i<n; i++) {
                cin>>a>>b;
                std::cout << remain(a,b) << std::endl;
        }

        return 0;
}
