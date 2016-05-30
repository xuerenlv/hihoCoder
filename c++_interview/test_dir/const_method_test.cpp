#include <iostream>
using namespace std;


class CL{
private:
  int num;

public:
  CL(int num):num(num){}

  int getNum() const{
    // num+=100;
    return num;
  }
  int getNum(){
    return num+10;
  }
};


int main(int argc,char **argv){
    CL cc(10);
    std::cout << cc.getNum() << std::endl;
        return 0;
}
