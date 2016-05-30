#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;


int main(int argc, char const *argv[]) {
  string s("xhj");

  std::cout << s << std::endl;

  s.insert(1,"E");
  std::cout << s << std::endl;

  return 0;
}
