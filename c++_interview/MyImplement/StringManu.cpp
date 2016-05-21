#include <cstring>
#include <string>
#include <iostream>
using namespace std;



int main(){

        // string st("xhj");
        // const char* str_1 = st.c_str();

        // 有符号转换为无符号 输出 1
        // printf("%d\n", -1>strlen(str_1));


        // 创建之后，里面的值默认是 ‘\0’ 也就是 int 类型的 0
        // char* a = new char[100];
        // a[1]='t';
        // a[2]='\0';
        // printf("%d\n", a[10]==0);
        // printf("%s\n", a);

        string* t = new string[100];
        for(int i=0;i<100;i++)
          std::cout << "/* message */"<<(t[i].size()==0) << std::endl;

}
