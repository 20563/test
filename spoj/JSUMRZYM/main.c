#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* we can compile with flag -DNDEBUG or #define NDEBUG
 * but this only disable assert, not test function
 */

#define UNIT_TEST
#ifdef UNIT_TEST
#include <assert.h>
#include <string.h>
#endif /* UNIT_TEST */

/*
 * JSUMRZYM - Dodawanie rzymskie
 * http://pl.spoj.com/problems/JSUMRZYM/
 * http://ideone.com/edBLzT
 */

static int16_t rta(const char *number);
static char *atr(int16_t number);

#ifdef UNIT_TEST
#define CHECK_ATR(number, a, b, input) check_atr(a, b, input, number)

/**
 * check() - test to check function
 *
 * @a: first value
 * @b: second value
 * @input: pointer to expected value
 * @number: test number
 *
 * Return: display if test is done or fail,
 * and when fail then returns assert
 */

static void check_atr(int16_t a, int16_t b, char *input, int8_t number)
{
	char *output = NULL;
	int8_t c = 0;

	output = atr(a + b);
	c = strcmp(input, output);
	printf("test: %04" PRId8 " [%s] %04" PRId16 " + %04" PRId16 " = %04"
		PRId16 " %s %s %s\n", number, (c == 0)?"done":"fail", a, b,
		a + b, output, (c == 0)?"==":"!=", input);
	assert(c == 0);
}

/**
 * run_tests() - start all tests
 */

void run_tests(void)
{
	CHECK_ATR(1, 2, 1, "III");
	CHECK_ATR(2, 1000, 1, "MI");
	CHECK_ATR(3, 123, 157, "CCLXXX");
	CHECK_ATR(4, 145, 23, "CLXVIII");
	CHECK_ATR(5, 3887, 1, "MMMDCCCLXXXVIII");
	CHECK_ATR(6, 3999, 0, "MMMCMXCIX");
	CHECK_ATR(7, 14, 4, "XVIII");
	CHECK_ATR(8, 123, 256, "CCCLXXIX");
	CHECK_ATR(9, 4, 5, "IX");
	CHECK_ATR(10, 20, 4, "XXIV");
}

#else
void run_tests(void) {}
#endif /* UNIT_TEST */

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

	static int8_t map[] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2};
	static char output[15] = {0};
	char *out = output, tmp;

	/* while the number is not zero convert arabic chars
	 * to numbers repersentation and store result in reversed order
	 */

	while (number) {
		chars_num += map[number % 10];
		mod = number % 5;
		if (mod == 4) {
			if ((number - 4) % 10 == 0)
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
 * main()
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

	/* we doesnt need to add #ifdef
	 * because if UNIT_TEST is not defined
	 * then function returns void
	 */

#ifdef UNIT_TEST
	run_tests();
#endif /* UNIT_TEST */

	while (scanf("%15s %15s", a, b) == 2) {
		output = atr(rta(a) + rta(b));
		printf("%s\n", output);
	}

	return 0;
}

