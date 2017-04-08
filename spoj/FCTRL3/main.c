#include <stdio.h>

/*
 * FCTRL3 - Dwie cyfry silni
 * http://pl.spoj.com/problems/FCTRL3/
 * http://ideone.com/GTMUE6
 */

int silnia(int x)
{
	if (x == 0)
		return 1;
	return x * silnia(x - 1);
}

int main(void)
{
	int D;
	int n;
	int i;
	int s;

	scanf("%d", &D);
	for (i = 0; i < D; i++) {
		scanf("%d", &n);
		if (n > 10)
			printf("0 0\n");
		else {
			s = silnia(n);
			printf("%d %d\n", ((s / 10) % 10), (s % 10));
		}

	}
	return 0;
}
