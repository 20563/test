#include <stdio.h>

/*
 * PRZEDSZK - Przedszkolanka
 * http://pl.spoj.com/problems/PRZEDSZK/
 * http://ideone.com/8n802L
 */

#include <stdio.h>

int main(void)
{
	int N;
	int a;
	int b;
	int i;
	int t;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		if (a > b) {
			t = a;
			a = b;
			b = t;
		}
		t = b;
		while ((t % a) != 0)
			t += b;
		printf("%d\n", t);
	}
	return 0;
}
