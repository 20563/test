#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * PP0504B - StringMerge
 * http://pl.spoj.com/problems/PP0504B/
 * http://ideone.com/eWGzxG
 */

#define T_SIZE 1001

char *string_merge(char *S1, char *S2);

char *string_merge(char *S1, char *S2)
{
	int16_t i = 0, j = 0;
	char *S = NULL;

	S = (char *)malloc(sizeof(char));
	while (i < T_SIZE) {
		if (S2[i] == '\0' || S1[i] == '\0')
			break;
		S = (char *)realloc(S, (i + 1) * 2 * sizeof(char) + 1);
		S[j] = S1[i];
		S[j+1] = S2[i];
		j += 2;
		i++;
	}
	S[j] = '\0';
	return S;
}

int main(void)
{
	int32_t t;
	char S1[T_SIZE] = {0}, S2[T_SIZE] = {0}, *S = NULL;

	scanf("%" SCNd32, &t);
	getchar();
	while (t--) {
		scanf("%s %s", S1, S2);
		S = string_merge(S1, S2);
		printf("%s\n", S);
		free(S);
	}
	return 0;
}
