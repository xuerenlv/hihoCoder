#include <iostream>
using namespace std;

void int_to_str(int num, char str[])
{
 char c;
 int x = num;
 int i = 0;
 for ( i = 0; x <= num; i++)
 {
  str[i] = num % 10 + '0';
  x = num / 10;
 }
 str[i] = '\0';
  for  (int j = 0; j <= num;j++ &&i--)
  {
   c = str[j];
   str[j] = str[i];
   str[i] = c;

  }
}

int main(int argc,char **argv){
        int num;
        cin>>num;

        char str[100];

        int_to_str(num,str);

        std::cout << str << std::endl;

        return 0;
}
