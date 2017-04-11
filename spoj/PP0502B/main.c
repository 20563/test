#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * PP0502B - Tablice
 * http://pl.spoj.com/problems/PP0502B/
 * http://ideone.com/RQue89
 */

int main(void)
{
	int8_t t, n;
	int8_t *tablica;
	int8_t i = 0;

	scanf("%" SCNd8, &t);
	while (t--) {
		scanf("%" SCNd8, &n);
		tablica = (int8_t *)malloc(n * sizeof(int8_t));
		i = 0;
		while (n--) {
			scanf("%" SCNd8, &tablica[i]);
			i++;
		}
		while (i--) {
			printf("%" PRId8, tablica[i]);
			if (i != 0)
				printf(" ");
		}
		printf("\n");
		free(tablica);
	}
	return 0;
}
