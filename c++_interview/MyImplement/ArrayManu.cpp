#include <iostream>
using namespace std;


int main(int argc, char const *argv[]) {

        int n;
        cin>>n;

        // 随机初始化
        int arr[n][n];

        // Defined in header <cstring>
        // void* memset( void* dest, int ch, std::size_t count );
        // Converts the value ch to unsigned char and copies it into each of the first count characters of the
        // object pointed to by dest. If the object is not trivially-copyable (e.g., scalar, array, or a C-compatible struct),
        //  the behavior is undefined. If count is greater than the size of the object pointed to by dest, the behavior is undefined.
        memset(arr,0,sizeof(arr));
        // 初始化为0的时候，挺好用

        for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++)
                        std::cout << arr[i][j] << " ";
                std::cout << std::endl;
        }



        return 0;
}
