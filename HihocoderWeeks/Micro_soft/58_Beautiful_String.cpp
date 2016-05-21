#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


string is_beautiful(char* st,int len){
        if(len<3)
                return "NO";

        vector<int> v_count;
        vector<char> v_char;
        int v_len=0;

        int count=1;
        for(int i=1; i<=len; i++) {
                if(i!=len && st[i]==st[i-1]) {
                        count++;
                }else{
                        v_count.push_back(count);
                        v_char.push_back(st[i-1]);
                        v_len++;
                        count=1;
                        if(v_len>=3) {
                                if(v_char[v_len-3]+1==v_char[v_len-2] && v_char[v_len-2]+1==v_char[v_len-1]) {
                                        if(v_count[v_len-3]>=v_count[v_len-2] && v_count[v_len-2]<=v_char[v_len-1])
                                                return "YES";
                                }
                        }
                }
        }
        return "NO";
}

int main(int argc, char const *argv[]) {
        int n,len;
        cin>>n;
        char a[104860];
        for(int i=0; i<n; i++) {
                scanf("%d", &len);
                scanf("%s", a);
                std::cout << is_beautiful(a,len)<< std::endl;

        }

        return 0;
}
