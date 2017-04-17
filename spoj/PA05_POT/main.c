#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * PA05_POT - Czy umiesz potęgować
 * http://pl.spoj.com/problems/PA05_POT/
 * http://ideone.com/ZmmUJs
 */

int main(void)
{
	int8_t D, c[3], i, l;
	int32_t a, b;
	int64_t wynik;

	scanf("%" SCNd8, &D);
	for (i = 0; i < D; i++) {
		wynik = 1;
		l = 0;
		scanf("%" SCNd32 " %" SCNd32, &a, &b);
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
		printf("%" PRId8 "\n", (int8_t)(wynik % 10));
	}
	return 0;
}
