#include <stdio.h>

/*
 * PRZEDSZK - Przedszkolanka
 * http://pl.spoj.com/problems/PRZEDSZK/
 * http://ideone.com/eqe9HT
 */

int main(void)
{
	int N;
	int a;
	int b;
	int i;
	int t;
	int j;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		j = 0;
		scanf("%d %d", &a, &b);
		if (a > b) {
			t = a;
			a = b;
			b = t;
		}
		t = b;
		while ((t % a) != 0) {
			t += b;
			j++;
			}
			printf("%d\n", t);
	}
	return 0;
}
