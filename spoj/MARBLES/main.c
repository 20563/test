#include <stdio.h>

/*
 * MARBLES - Marbles
 * http://www.spoj.com/problems/MARBLES/
 */

long long int combination(int n, int k)
{
	int i = 0;

	long double s = 1;
	long double j = 1;

	for (i = n-k+1; i < n; i++)
		j *= i;
	for (i = 1; i < k; i++)
		s *= i;

	return j /= s;
}

int main(void)
{
	int T;
	int n;
	int k;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		printf("%lld\n", combination(n, k));
	}
	return 0;
}
