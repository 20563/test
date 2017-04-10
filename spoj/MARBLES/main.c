#include <stdio.h>

/*
 * MARBLES - Marbles
 * http://www.spoj.com/problems/MARBLES/
 * http://ideone.com/EyGuFl
 */

long long combination(int n, int k)
{
	int i = 0;
	long long j = 1;
	int l = 1;

	for (i = n-k+1; i < n; i++) {
		j = (j * i) / l;
		l++;
	}
	return j;
}

int main(void)
{
	int T = 0;
	int n = 0;
	int k = 0;
	long long i = 0;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		i = 0;
		i = (combination(n, k));
		printf("%lld\n", i);
	}
	return 0;
}
