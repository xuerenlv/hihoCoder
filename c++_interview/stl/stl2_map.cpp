#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main(int argc, char const *argv[]) {
  map<int, string> map_1;

  map_1.insert(pair<int,string>(11,"11_str"));


  map<int, string>::iterator l_it = map_1.find(1);

  if (l_it==map_1.end()) {
    std::cout << "Not found" << std::endl;
  }else{
    std::cout << l_it->first << std::endl;
    std::cout << l_it->second << std::endl;
  }

  return 0;
}
