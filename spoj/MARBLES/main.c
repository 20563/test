#include <stdio.h>

/*
 * MARBLES - Marbles
 * http://www.spoj.com/problems/MARBLES/
 */

long double factorial(double x)
{
	if (x == 0)
		return 1;
	return x * factorial(x - 1);
}

int main(void)
{
	int T;
	int n;
	int k;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		printf("%0.Lf\n", factorial(n - 1) /
			((factorial(k - 1) * factorial(n - k))));
	}
	return 0;
}
