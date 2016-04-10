
#include <stdio.h>

#define N 1048576

int A[N], k;

int readInt()
{
	int val, ch;
	while(((unsigned)(ch = getchar() - '0')) > 9)
		;
	val = ch;
	while(((unsigned)(ch = getchar() - '0')) <= 9)
		val = (val << 3) + (val << 1) + ch;
	return val;
}

int median3(int a, int b, int c)
{
	if(a < b) {
		if(b <= c) return b;
		else return a < c ? c : a;
	} else { // b <= a
		if(a <= c) return a;
		else return b < c ? c : b;
	}
}

int findKth(int lo, int hi) // find in [lo, hi] the kth (global) number
{
    int i, j, pivot, temp;

	while(hi - lo >= 2) {
		pivot = median3(A[lo], A[hi], A[(lo + hi) >> 1]);
		i = lo - 1;
		j = hi + 1;
		while(1) {
			for(++i; A[i] < pivot; ++i) ;
			for(--j; A[j] > pivot; --j) ;
			if(i < j) {
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			} else break;
		}
		if(k < i) hi = i;
		else lo = i;
	}
	// 在 lo 到 hi 之间进行插入排序
	for(i = lo + 1; i <= hi; i++) {
		temp = A[i];
		for(j = i; j > lo && A[j - 1] > temp; j--)
			A[j] = A[j - 1];
		A[j] = temp;
	}
	return A[k];
}

int main()
{
    int n, i;
    n = readInt();
    k = readInt() - 1;
    for(i = 0; i < n; i++)
		A[i] = readInt();
	if(k < 0 || k >= n)
        printf("-1\n");
	else
		printf("%d\n", findKth(0, n - 1));
    return 0;
}
