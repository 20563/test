#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * PRIME_T - Liczby Pierwsze
 * http://pl.spoj.com/problems/PRIME_T/
 * http://ideone.com/4eSs3u
 */

int main(void)
{
	int32_t nTest, i;
	int16_t number, tmp, wynik;
	int8_t j;

	scanf("%" SCNd32, &nTest);
	for (i = 0; i < nTest; i++) {
		scanf("%" SCNd16, &number);
		tmp = number;
		j = 0;
		while (--tmp > 1) {
			wynik = number % tmp;
			if (wynik == 0) {
				j = 1;
				break;
			}
		}
		if (number == 1)
			j = 1;
		printf( j == 0 ? "TAK\n" : "NIE\n");
	}
	return 0;
}
