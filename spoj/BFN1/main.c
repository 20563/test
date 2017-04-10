#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * BFN1 - Zabawne Dodawanie Piotrusia
 * http://pl.spoj.com/problems/BFN1/
 * http://ideone.com/dRAiBR
 */

int32_t revert(int32_t liczba)
{
	int32_t cyfry = 0;
	int32_t i = 1;

	while (liczba) {
		cyfry = (cyfry * i) + (liczba % 10);
		liczba /= 10;
		i = 10;
	}
	return cyfry;
}

int8_t isPalindrom(int32_t liczba)
{
	if (liczba == revert(liczba))
		return 1;
	return 0;
}

int main(void)
{
	int32_t t;
	int32_t n;
	int8_t i;

	scanf("%" SCNd32, &t);
	while (t--) {
		scanf("%" SCNd32, &n);
		i = 0;
		while (!isPalindrom(n)) {
			n += revert(n);
			i++;
		}
		printf("%" PRId32 " %" PRId32 "\n", n, i);
	}
	return 0;
}
