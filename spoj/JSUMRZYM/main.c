#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * JSUMRZYM - Dodawanie rzymskie
 * http://pl.spoj.com/problems/JSUMRZYM/
 * http://ideone.com/edBLzT
 */

const char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int16_t arabic[7] = {1, 5, 10, 50, 100, 500, 1000};

/**
 * rta() - convert numbers roman to arabic
 * @number: number in roman notation
 *
 * some description
 *
 * Return: return the number in arabic notation
 */

static int16_t rta(const char *number)
{
	int8_t i;
	int16_t output = 0, tmp = 0;

	/* converting and checking if number offset in roman
	 * is lower than next offset, then substract that numer
	 * from output value eg. IX, XC, CM.
	 */

	while (*number) {
		for (i = 0; i < 7; i++) {
			if (*number == roman[i]) {
				if (tmp < arabic[i])
					tmp *= -1;
				output += tmp;
				tmp = arabic[i];
				break;
			}
		}
		number++;
	}

	return output + tmp;
}

/* opis funckcji zgdnie z kernelem  zmienne z podkreslnikiem
 * zabazpieczyc funkcje przed przyjeciem zlych wartosci parametrow
 * unit testy plan git commit push review
 */

/**
 * atr() - convert numbers arabic to roman
 * @number: number in arabic notation
 *
 * some description
 *
 * Return: return the number in roman notation
 */

static char *atr(int16_t number)
{
	int8_t chars_num = 0, mod = 0, i = 0;

	/* Letters required for number representation in roman
	 * 0 = 0, 1 = 1, 2 = 2, 3 = 3, 4 = 2, 5 = 1, 6 = 2, 7 = 3, 8 = 4, 9 = 2
	 */

	int8_t map[10] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
	static char output[15] = {0};
	char *out = output, tmp;

	/* while the number is not zero convert arabic chars
	 * to numbers repersentation and store result in revesed order
	 */

	while (number) {
		chars_num += map[number % 10];
		mod = number % 5;
		if (mod == 4) {
			if (((number - 4) % 10) == 0)
				*out++ = roman[i+1];
			else
				*out++ = roman[i+2];
			*out++ = roman[i];
		} else {
			while (mod--)
				*out++ = roman[i];
			if ((number % 10) >= 5)
				*out++ = roman[i+1];
		}
		number /= 10;
		i += 2;
		*out = '\0';
	}

	/*  reverse string to the proper order
	 */

	for (i = 0; i < chars_num; i++) {
		tmp = output[i];
		output[i] = output[chars_num-1];
		output[chars_num-1] = tmp;
		chars_num--;
	}
	return output;
}

/*
 * longest number 3888 MMMDCCCLXXXVIII 15 chars
 * highest number 3999 MMMCMXCIX 12 bits
 */

/**
 * main() - sum two numbers in arabic and return in roman
 *
 * @a: first number in roman
 * @b: second number in roman
 *
 * some description
 *
 * Return: display result of sum and return 0;
 */

int main(void)
{
	char a[16] = {0}, b[16] = {0}, *output = NULL;

	while (scanf("%15s %15s", a, b) == 2) {
		output = atr(rta(a) + rta(b));
		printf("%s\n", output);
	}
	return 0;
}

