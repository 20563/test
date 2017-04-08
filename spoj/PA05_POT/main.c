#include <stdio.h>

/*
 * PA05_POT - Czy umiesz potęgować
 * http://pl.spoj.com/problems/PA05_POT/
 * http://ideone.com/ZmmUJs
 */

int main(void)
{
	int D;
	long int a;
	long int b;
	int c[3];
	int i;
	long long int wynik;
	int l;

	scanf("%d", &D);
	for (i = 0; i < D; i++) {
		wynik = 1;
		l = 0;
		scanf("%ld %ld", &a, &b);
		c[0] = a % 10;
		c[1] = ((c[0] * c[0]) % 10);
		c[2] = ((c[1] * c[1]) % 10);
		while (b) {
			if (b & 1)
				wynik *= c[l];
			b >>= 1;
			if (l < 2)
				l++;
		}
		printf("%d\n", (int)(wynik % 10));
	}
	return 0;
}
