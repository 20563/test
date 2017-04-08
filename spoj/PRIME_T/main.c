#include <stdio.h>

/*
 * PRIME_T - Liczby Pierwsze
 * http://pl.spoj.com/problems/PRIME_T/
 * http://ideone.com/4eSs3u
 */

int main(void)
{
	int n;
	int l;
	int t;
	int i;
	int j;
	int wynik;

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &l);
		t = l;
		j = 0;
		while (--t > 1) {
			wynik = l % t;
			if (wynik == 0) {
				printf("NIE\n");
				j = 1;
				break;
			}
		}
		if (l == 1) {
			printf("NIE\n");
			j = 1;
		}
		if (j == 0)
			printf("TAK\n");
	}
	return 0;
}
