#include<iostream>
#include<vector>
#include <string>
using namespace std;

struct TreeNode{
  char ch;
  TreeNode* left;
  TreeNode* right;
};

TreeNode* create_tree(string pre,int pre_s,int pre_e,string mid,int mid_s,int mid_e){
  if(pre_s>pre_e)
    return NULL;

  TreeNode* root = new TreeNode();
  root->ch = pre[pre_s];

  if(pre_s==pre_e)
    return root;

  int l = mid_s;
  while(mid[l]!=pre[pre_s])
    l++;

  root->left = create_tree(pre,pre_s+1, pre_s+l-mid_s, mid, mid_s, l-1);
  root->right = create_tree(pre,pre_s+l-mid_s+1,pre_e,mid,l+1,mid_e);

  return root;
}

void post_order(TreeNode* root){
  if(!root)
    return;
  post_order(root->left);
  post_order(root->right);
  std::cout << root->ch;
}


int main(int argc,char **argv){
  string pre,mid;

  std::cin >> pre >> mid;

  TreeNode* root = create_tree(pre,0,pre.length()-1,mid,0,mid.length()-1);
  post_order(root);
  std::cout << std::endl;
}
