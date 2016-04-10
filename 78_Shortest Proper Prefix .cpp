#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define N 2000100

struct Trie{
	char ch;
  int s,son[27];
}t[N];

int n,tot=1;
char a[N];

// 读入整数
inline int in(){
	int x=0; char ch=getchar(); bool f=true;
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=false;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (!f) x=-x;
	return x;
}

// 插入单词
inline void Insert(int x,int w,int len){
	int v=a[w]-'a';
	t[x].s++;
	if (!t[x].son[v]){
		t[x].son[v]=++tot;
		t[t[x].son[v]].s=0,t[t[x].son[v]].ch=a[w];
	}
	if (w==len-1){
		t[t[x].son[v]].s++; return;
	}
	Insert(t[x].son[v],w+1,len);
}

// 查询结果
inline int Query(int x){
	if (t[x].s<=5) return 1;
	int i,s=0;
	for (i=0; i<26; i++)
		if (t[x].son[i])
			s+=Query(t[x].son[i]);
	return s;
}

int main(){
	n=in();
  t[1].s=0,t[1].ch=' ';
	for (int i=1; i<=n; i++){
		scanf("%s",&a);
		Insert(1,0,strlen(a));
	}
	printf("%d\n",Query(1));
	return 0;
}
