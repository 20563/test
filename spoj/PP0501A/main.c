#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * PP0501A - NWD
 * http://pl.spoj.com/problems/PP0501A/
 * http://ideone.com/0Ky4v2
 */

int main(void)
{
	int32_t t;
	int32_t a;
	int32_t b;
	int32_t tmp;

	scanf("%" SCNd32, &t);
	while (t--) {
		scanf("%" SCNd32 " %" SCNd32, &a, &b);
		if (a < b) {
			tmp = a;
			a = b;
			b = tmp;
		}
		tmp = a % b;
		while (tmp) {
			a = tmp;
			tmp = b % tmp;
			b = a;
		}
		printf("%" PRId32 "\n", b);
	}
	return 0;
}
