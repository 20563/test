#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <pthread.h>
#include <time.h>

/** we can compile with flag -DNDEBUG or #define NDEBUG
 * but this only disable assert, not test function
 */

#define UNIT_TEST
#ifdef UNIT_TEST
#include <assert.h>
#include <string.h>

#define FAULT -1

#endif /** UNIT_TEST */

/**
 * JSUMRZYM - Dodawanie rzymskie
 * http://pl.spoj.com/problems/JSUMRZYM/
 * http://ideone.com/edBLzT
 */

static int16_t rta(const char *number);
static const char *atr(int16_t number);
void check_rta(const char *input, const int16_t expected_result);
void time_trigger(void);
void delay(double time_s);

#ifdef UNIT_TEST

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

static void check_atr(int8_t number, int16_t input,
	const char *expected, int8_t action)
{
	char const *output = NULL;
	int8_t c = 0;

	output = atr(input);
	c = strcmp(expected, output);

	/** if expected fail then pass */

	printf("test: %04" PRId8 " [%s] %s\n\n\t%04" PRId16 " %s %s %s\n\n",
		number, c == 0 ? "pass" : "fail",
		((c != 0 && action == 1) || c == 0)
		? "[but expected]" : "[not expected]",
		input, output, c == 0 ? "==" : "!=", expected);
}

/**
 * run_tests() - start all tests
 */

static void run_tests(void)
{
	check_atr(1, 3, "III", 0);
	check_atr(2, 1001, "MI", 0);
	check_atr(3, 280, "CCLXXX", 0);
	check_atr(4, 168, "CLXVIII", 0);
	check_atr(5, 3888, "MMMDCCCLXXXVIII", 0);
	check_atr(6, 3999, "MMMCMXCIX", 0);
	check_atr(7, 18, "XVIII", 0);

	/** good and marked as expected, allways good */
	check_atr(8, 18, "XVIII", 1);
	check_atr(9, 379, "CCCLXXIX", 0);

	/** bad and marked as good there allways be error */
	check_atr(10, 379, "CCCLXXI", 0);
	check_atr(11, 9, "IX", 0);
	check_atr(12, 24, "XXIV", 0);

	/** bad but marked as expected */
	check_atr(13, 123, "XXIVI", 1);

	/** bad but marked as expected */
	check_atr(14, 344, "I", 1);
	
	check_rta(NULL, FAULT);
	check_rta("MMMM", FAULT);
	check_rta("MMMMCMXCIX", FAULT);
	check_rta("III", 3);
	check_rta("MCDXCIX", 1499);
	check_rta("MMMCDLVII", 3457);
}

#else
static void run_tests(void) {}
#endif /** UNIT_TEST */

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
	
	if (number == NULL)
		return FAULT;

		
	

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
	
	output += tmp;

	if (output > 3999)
		return FAULT;
		
	return output;
}


/**
 * atr() - convert numbers arabic to roman
 * @number: number in arabic notation
 *
 * some description
 *
 * Return: return the number in roman notation
 */

static const char *atr(int16_t number)
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

	/**  reverse string to the proper order
	 */

	for (i = 0; i < chars_num; i++) {
		tmp = output[i];
		output[i] = output[chars_num-1];
		output[chars_num-1] = tmp;
		chars_num--;
	}
	return output;
}

/**
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

void check_rta(const char *input, const int16_t expected_result)
{
	int16_t result = 0;

	result = rta(input);
	(result == expected_result)? printf("test passed\n"):(printf("test failed\n"));
}

int main(void)
{
	char a[16] = {0}, b[16] = {0};
	char const *output = NULL;
	pthread_t time_thread;


	/** watek w main 2 operacje atomowe mutex semafor */

	/** we doesnt need to add #ifdef
	 * because if UNIT_TEST is not defined
	 * then function returns void
	 */

#ifdef UNIT_TEST
	run_tests();
#endif /** UNIT_TEST */

	
	if(pthread_create(&time_thread, NULL, time_trigger, NULL)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	
	delay(10);


	while (scanf("%15s %15s", a, b) == 2) {
		output = atr(rta(a) + rta(b));
		printf("%s\n", output);
	}

	return 0;
}

void time_trigger(void)
{
	while(1) {
		delay(1);
		printf("Hello World\n");

	}
	
}

void delay(double time_s) {
    const clock_t start = clock();
    clock_t current;
    do{
        current = clock();

    }while((double)(current-start)/CLOCKS_PER_SEC < time_s);
}
