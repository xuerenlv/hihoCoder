#include <iostream>
#include <string>
using namespace std;

// 3.1 one array ,three stacks
struct StackNode{
  int data;
  int next;
  StackNode():data(0),next(-1){}
  StackNode(int d):data(d),next(-1){}
};

class MyStack{
public:
  MyStack():size(0),capacity(100){
    top1 = -1;
    top2 = -1;
    top3 = -1;
    container = new StackNode[100];
  }

  // container copy
  void copy_container(StackNode* container,StackNode* new_container,int size){
    while (size) {
      new_container[size].data = container[size].data;
      new_container[size].next = container[size].next;
      size--;
    }
  }

  // 入栈
  void put(int stacknum,int data){
    if(size>=capacity-3){
      capacity += 200;
      StackNode* new_container = new StackNode[capacity];
      copy_container(container,new_container,size);
      delete container;
      this->container = new_container;
    }

    container[size].data = data;


    if(stacknum==1){
      container[size].next = top1;
      top1 = size;
    }else if(stacknum==2){
      container[size].next = top2;
      top2 = size;
    }else if(stacknum==3){
      container[size].next = top3;
      top3 = size;
    }else{
      // 出错
    }
  }

  // 出栈
  int pop(int stacknum){
    if(stacknum==1){
      if(top1==-1){
        return -1;
      }else{
        StackNode s = container[top1];
        top1 = container[top1].next;
        return s.data;
      }
    }else if(stacknum==2){
      if(top2==-1){
        return -1;
      }else{
        StackNode s = container[top2];
        top2 = container[top2].next;
        return s.data;
      }
    }else if(stacknum==3){
      if(top3==-1){
        return -1;
      }else{
        StackNode s = container[top3];
        top3 = container[top3].next;
        return s.data;
      }
    }else{
      return -1;
    }
  }

private:
  int top1,top2,top3;
  int size;
  int capacity;
  StackNode* container;
};


// 3.2




int main(int argc, char const *argv[]) {

  return 0;
}
