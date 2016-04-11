#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct TrieNode{
  bool is_word;
  int count_1;
  TrieNode *son;
  TrieNode():is_word(false),count_1(0),son(NULL){};
};

void  insert_word(int start,const char* str,TrieNode* current) {
  if(current->son == NULL){
    current->son = new TrieNode[26];
  }
  current->count_1++;
  if (str[start+1]=='\0') {
    current->son[str[start]-'a'].is_word=true;
    return;
  }
  insert_word(start+1, str, &(current->son[str[start]-'a']));
}

int query_word(int start,const char* str,TrieNode* current){
  if(current->son==NULL)
    return 0;
  if(str[start+1]=='\0'){
    return current->son[str[start]-'a'].count_1;
  }else{
    return query_word(start+1, str, &(current->son[str[start]-'a']));
  }
}

int main() {
  int n;
  char str[1000];
  cin>>n;
  TrieNode* root = new TrieNode();
  for(int i=0;i<n;i++){
    scanf("%s", str);
    insert_word(0, str, root);
  }

  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    scanf("%s", str);
    printf("%d\n",query_word(0, str, root));
  }

  return 0;
}
