#include <stdio.h>
#include <stdlib.h>

/*
 * FLAMASTE - Flamaster
 * http://pl.spoj.com/problems/FLAMASTE/
 * http://ideone.com/wQq5Bg
 */

int main(void)
{
	int i;
	int j;
	int C;
	char *zdanie;
	size_t zsize = 200;
	size_t n;
	int rep;

	zdanie = (char *)malloc(zsize * sizeof(char));
	if (zdanie == NULL) {
		perror("Unable to allocate buffer");
		exit(1);
	}
	scanf("%d", &C);
	getchar();
	for (i = 1; i <= C; ++i) {
		rep = 1;
		n = getline(&zdanie, &zsize, stdin);
		for (j = 0; j < n; j++) {
			if (zdanie[j] == zdanie[j+1])
				rep++;
			else {
				if (rep >= 3)
					printf("%c%d", zdanie[j], rep);
				else if (rep == 2)
					printf("%c%c", zdanie[j], zdanie[j]);
				else
					printf("%c", zdanie[j]);
				rep = 1;
			}
		}
	}
	free(zdanie);
	return 0;
}
