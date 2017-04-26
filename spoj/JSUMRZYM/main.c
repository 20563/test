#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <assert.h>
#include <pthread.h>
#include <time.h>

/*
 * JSUMRZYM - Dodawanie rzymskie
 * http://pl.spoj.com/problems/JSUMRZYM/
 * http://ideone.com/edBLzT
 */
 
 #define FAULT -1

const char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int16_t arabic[7] = {1, 5, 10, 50, 100, 500, 1000};

void check_tra(int16_t a, int16_t b, char *input, int8_t number);
void time_trigger(void);
void delay(double time_s);
void check_rta(const char *input, const int16_t expected_result);

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

void run_test() {
	check_rta(NULL, FAULT);
	check_rta("MMMM", FAULT);
	check_rta("MMMMCMXCIX", FAULT);
	check_rta("III", 3);
	check_rta("MCDXCIX", 1499);
	check_rta("MMMCDLVII", 3457);
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
	pthread_t time_thread;
	
	if(pthread_create(&time_thread, NULL, time_trigger, NULL)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	
	run_test();
	delay(10);
	return 0;
}

void check_rta(const char *input, const int16_t expected_result)
{
	int16_t result = 0;

	result = rta(input);
	(result == expected_result)? printf("test passed\n"):(printf("test failed\n"));
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
