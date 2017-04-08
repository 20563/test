#include <stdio.h>

/*
 * CHI_BINARY - Binary numbers
 * http://www.spoj.com/problems/CHI_BINARY/
 * http://ideone.com/7umq6a
 */

#define NBITS 32

void tobin(int *n_ops)
{
	int i = 0;
	int t = *n_ops;

	*n_ops = 0;
	while (t) {
		*n_ops |= ((t % 10) << i);
		t /= 10;
		i++;
	}
}

void output(int out)
{
	int i = 0;
	int k = 0;
	int bins[NBITS] = {0};

	while (out) {
		if (out & 1)
			bins[i] = 1;
		else
			bins[i] = 0;
		out >>= 1;
		i++;
	}
	if (i == 0)
		printf("%d", bins[i]);
	for (; i >= 0; i--) {
		if (bins[i] == 0 && k == 0)
			continue;
		else {
			printf("%d", bins[i]);
			k = 1;
		}
	}
}

void shift(long long int *num)
{
	*num |= *num >> 1;
	*num |= *num >> 2;
	*num |= *num >> 4;
	*num |= *num >> 8;
	*num |= *num >> 16;
	*num |= *num >> 32;
}

int greater(int A, int B)
{
	long long int is = 0;
	long long int l = ~A & B;
	long long int g = A & ~B;

	shift(&l);

	is = g & ~l;

	shift(&is);

	is &= 1;

	return is;
}

int addition(int A, int B)
{
	int carry;
	int out;

	carry = (A & B) << 1;
	out = A ^ B;
	if (carry)
		return addition(out, carry);
	else
		return out;
}

int substraction(int A, int B)
{
	if (greater(B, A))
		A |= (((B << 1) | B) ^ B);
	return addition(A, addition(~B, 1));
}

int multiplication(int A, int B)
{
	int out = 0;

	while (B) {
		if (B & 1)
			out = addition(out, A);
		A <<= 1;
		B = (B >> 1);
	}
	return out;
}

void division(int A, int B)
{
	int remainder = 0;
	int division = B;
	int quotient = 0;
	int i = 0;

	if (greater(B, 0)) {
		for (i = 31; i > 0; i--) {
			remainder <<= 1;
			remainder |= ((A & (1 << (i - 1))) >> (i-1));
			if (greater(remainder, division) ||
				(remainder ^ division) == 0) {
				remainder = substraction(remainder, division);
				quotient |= (1 << (i-1));
			}
		}
	}
	output(quotient);
	printf(" ");
	output(remainder);
}

int main(void)
{
	int n_ops = 0;
	int oper = 0;
	int A = 0;
	int B = 0;

	scanf("%d", &n_ops);
	tobin(&n_ops);
	while (n_ops--) {
		scanf("%d %d %d", &oper, &A, &B);
		tobin(&oper);
		tobin(&A);
		tobin(&B);
		switch (oper) {
		case 0: {
			output(greater(A, B));
			printf("\n");
			break;
		}
		case 1: {
			output(addition(A, B));
			printf("\n");
			break;
		}
		case 2: {
			output(substraction(A, B));
			printf("\n");
			break;
		}
		case 3: {
			output(multiplication(A, B));
			printf("\n");
			break;
		}
		case 4: {
			division(A, B);
			printf("\n");
			break;
		}
		default:
			break;
		}
	}
	return 0;
}
