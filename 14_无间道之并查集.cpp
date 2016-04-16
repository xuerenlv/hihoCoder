#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

const int maxn = 200009;

map <string, int> l;
int n, r[maxn], tn;
char t1[30], t2[30];

// 字符串map数字
int getNum(char* x) {
	string a(x);
	map <string, int> :: iterator i = l. find(a);
	if (i == l. end()) {
		int r = ++ tn;
		l. insert(pair<string, int> (a, r));
		return r;
	}
	else
		return i-> second;
}

int getRoot(int n) {
  while (n != r[n]){
    r[n] = r[r[n]];
    n = r[n];
  }
  return n;
}

int main() {
	scanf("%d", &n);
	tn = 0;
  // 节点的初始化
	for (int i = 1; i <= n * 2; ++ i)
		r[i] = i;
    
	for (int i = 0; i < n; ++ i) {
		int opt;
		scanf("%d%s%s", &opt, t1, t2);
		int x = getRoot(getNum(t1));
		int y = getRoot(getNum(t2));
		if (!opt)
			r[x] = y;
		else
			puts((x == y) ? "yes" : "no");
	}
}
