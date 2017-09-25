#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int tri_num[10] = { 0, };

int sumdigit(int i) {
	if (i == 8)
		return 0;
	else 
		return sumdigit(i+1) + tri_num[i];
}

int main() {
	int digit, X;
	printf("Enter the N(the digit): ");
	scanf("%d", &digit);
	printf("Enter the X(the sum of all digits):");
	scanf("%d", &X);
	int i;
	while (1) {
		for (i = 0; i < digit; i++)
		{
			if (tri_num[i] == 3) {
				tri_num[i] = 0;
				tri_num[i + 1] += 1;
			}
		}
		sumdigit(0);
		if (tri_num[digit] == 1)
			break;

		if (sumdigit(0) <= X) {
			for (i = 0; i < digit; i++) {
				printf("%d", tri_num[i]);
			}
			printf("\n");
		}
		tri_num[0]++;
	}
}