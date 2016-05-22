#include <iostream>
#include <string>
using namespace std;

// 链表节点
struct LinkNode{
  int data;
  LinkNode* next;
  LinkNode(int da):data(da){}
};

// LinkedList
class LinkedList{
public:
  explicit LinkedList(){
    this->root = new LinkNode(-1);
  }

  // 增加
  void add(int da){
    LinkNode* p = root;
    while(p->next != NULL)
      p=p->next;
    p->next = new LinkNode(da);
  }

  // 返回长度
  int getLen(){
    int len = 0;
    LinkNode* p =root;
    while(p->next != NULL){
      p=p->next;
      len++;
    }
    return len;
  }

  // 返回倒数第 k 个节点 的值
  int genReKth(int k){
    LinkNode *p=root,*q=root;

    while (k>0 && q != NULL) {
      k--;
      q=q->next;
    }

    if(k!=0 || q==NULL)
      return -1;

    while(q != NULL){
      p=p->next;
      q=q->next;
    }
    return p->data;
  }

  // 返回正数第 K(k>=1) 个节点的值
  int geyKth(int k){
    if(k<1)
      return -1;

    LinkNode *p=root;
    while(k>0 && p!=NULL){
      k--;
      p = p->next;
    }

    if(k!=0 || p==NULL)
      return -1;
    return p->data;
  }

  // 判断当前链表是否有环
  bool isCicle(){
    LinkNode *p= root,*q=root;
    while(q->next!=NULL && q->next->next!=NULL && p != q){
      p = p->next;
      q = q->next->next;
    }
    return p==q;
  }

  // 如果链表有环，返回环的起点
  LinkNode* getCicleStart(){
    if(!isCicle())
      return NULL;

    LinkNode *p= root,*q=root;
    while(p != q){
        p = p->next;
        q = q->next->next;
    }

    p=root->next;
    while(q!=p){
      p=p->next;
      q=q->next;
    }
    return p;
  }

private:
  LinkNode* root;
};



int main(int argc, char const *argv[]) {

  return 0;
}
