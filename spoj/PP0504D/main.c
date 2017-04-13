#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * PP0504D - Reprezentacja liczb typu float
 * http://pl.spoj.com/problems/PP0504D/
 * http://ideone.com/mxMV9X
 */


int8_t countbits(int16_t number)
{
	int8_t i = 0;

	while (number) {
		number % 2;
		number >>= 1;
		i++;
	}
	return i;
}

int32_t mantysa(float liczba, int8_t bits)
{
	int32_t tmp = (int32_t)liczba;
	int32_t mantysa = 0, shift;
	int8_t i = 0;

	liczba -= tmp;
	shift = (tmp ^ (1 << (bits - 1))) << (24 - bits);
	while (i != (24 - bits)) {
		liczba *= 2;
		if (liczba >= 1) {
			liczba -= 1;
			mantysa = (mantysa << 1) | 1;
		} else
			mantysa <<= 1;
		i++;
	}
	mantysa |= shift;
	return mantysa;
}

void printfloat(float liczba)
{
	int8_t bits;
	int32_t exp, m = 0, sign = 0;

	if (liczba < 0) {
		sign = (1 << 31);
		liczba *= -1;
	}
	bits = countbits(liczba);
	if (bits != 0) {
		exp = (bits + 126);
		m = mantysa(liczba, bits) | (exp << 23) | sign;
	}
	printf("%x %x %x %x\n", (m & 0xff000000) >> 24,
		(m & 0xff0000) >> 16, (m & 0xff00) >> 8, m & 0xff);
}

int main(void)
{
	int8_t t;
	float liczba;

	scanf("%" SCNd8, &t);
	while (t--) {
		scanf("%f", &liczba);
		printfloat(liczba);
	}
	return 0;
}
