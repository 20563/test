#include <stdio.h>

/*
 * ETI06F1 - Pole pewnego koła
 * http://pl.spoj.com/problems/ETI06F1/
 * http://ideone.com/lfme35
 */

int main(void)
{
	double r;
	double d;

	scanf("%lf %lf", &r, &d);
	printf("%lf", 3.141592654 * ((r * r) - ((d * d) / 4)));
	return 0;
}
