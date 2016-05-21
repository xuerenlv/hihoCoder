#include <iostream>
#include <string>
using namespace std;



class HashXhj{
public:
  explicit HashXhj(int capacity){
    this -> con = new string[capacity];
    // memset(this -> con,0,sizeof(con));
    this -> capacity = capacity;
  }

  // 求取 hash 值
  int HashFunc(string s){
    long long hash_val = 0;
    for(size_t i=0;i<s.size();i++){
      hash_val += 8 * (s[i]-'a');
    }
    return (int)(hash_val % this->capacity);
  }

  // 添加
  int put(string s){
    if(this->size==this->capacity)
      return -1;

    int hash_val = HashFunc(s);
    while(con[hash_val].size()){
      hash_val=(hash_val+1)%capacity;
    }

    this->size++;
    con[hash_val]=s;
    return hash_val;
  }

  // 查找
  bool search(string s){
    int hash_val = HashFunc(s);
    while(con[hash_val].size()){
      return con[hash_val]==s;
    }
    return false;
  }

private:
  string* con;
  int size;
  int capacity;
};




int main(int argc, char const *argv[]) {
  HashXhj xhj_ha(100);
  string a = "xhj";
  string b = "xhj2";

  xhj_ha.put(a);
  xhj_ha.put(b);

  std::cout << xhj_ha.search(a) << std::endl;
  std::cout << xhj_ha.search(b) << std::endl;
  std::cout << xhj_ha.search("xhj3") << std::endl;

  return 0;
}
