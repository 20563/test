#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
/*
 * JSUMRZYM - Dodawanie rzymskie
 * http://pl.spoj.com/problems/JSUMRZYM/
 * http://ideone.com/edBLzT
 */

/*
 * ASCII letters representation
 * I = 73, V = 86, X = 88, L = 76, C  = 67, D = 68, M = 77
 */

int8_t roman[7] = {73, 86, 88, 76,  67,  68,   77};
int16_t arabic[7] = { 1,  5, 10, 50, 100, 500, 1000};

int16_t atr(char *liczba)
{
	int8_t i;
	int16_t output = 0, tmp = 0;

	while (*liczba) {
		for (i = 0; i < 7; i++) {
			if ((char)*liczba == roman[i]) {
				if (tmp < arabic[i])
					tmp *= -1;
				output += tmp;
				tmp = (arabic[i]);
				break;
			}
		}
		liczba++;
	}

	return output + tmp;
}

char *rta(int16_t liczba)
{
	int8_t ileZnakow = 0, mod = 0, i = 0;

	/*
	 * Letters required for number representation in roman
	 * 0 = 0, 1 = 1, 2 = 2, 3 = 3, 4 = 2, 5 = 1, 6 = 2, 7 = 3, 8 = 4, 9 = 2
	 */

	int8_t map[10] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
	char *output = (char *)malloc(sizeof(*output)), *out = output, tmp;

	while (liczba) {
		ileZnakow += map[liczba % 10];
		output = (char *)realloc(output,
			sizeof(*output) * (ileZnakow + 1));
		mod = liczba % 5;
		if (mod == 4) {
			if (((liczba - 4) % 10) == 0)
				*out++ = roman[i+1];
			else
				*out++ = roman[i+2];
			*out++ = roman[i];
		} else {
			while (mod--)
				*out++ = roman[i];
			if ((liczba % 10) >= 5)
				*out++ = roman[i+1];
		}
		liczba /= 10;
		i += 2;
		*out = '\0';
	}

	for(i = 0; i < ileZnakow; i++){
		tmp = output[i];
		output[i] = output[ileZnakow-1];
		output[ileZnakow-1] = tmp;
		ileZnakow--;
	}
	return output;
}

/*
 * longest number 3888 MMMDCCCLXXXVIII 15 chars
 * highest number 3999 MMMCMXCIX 12 bits
 */

int main(void)
{
	char a[16] = {0}, b[16] = {0}, *output = NULL;

	while (scanf("%15s %15s", a, b) == 2) {
		output = rta(atr(a) + atr(b));
		printf("%s\n", output);
		free(output);
	}
	return 0;
}
