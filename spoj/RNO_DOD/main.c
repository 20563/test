#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * RNO_DOD - Proste dodawanie
 * http://pl.spoj.com/problems/RNO_DOD/
 * http://ideone.com/9CZmCU
 */

int main(void)
{
	int8_t t;
	int8_t n;
	int32_t liczba;
	int32_t wynik;

	scanf("%" SCNd8, &t);
	while (t--) {
		scanf("%" SCNd8, &n);
		wynik = 0;
		while (n--) {
			scanf("%" SCNd32, &liczba);
			wynik += liczba;
		}
		printf("%" PRId32 "\n", wynik);
	}
	return 0;
}

