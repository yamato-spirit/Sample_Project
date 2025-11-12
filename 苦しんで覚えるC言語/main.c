#include <stdio.h>

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d~%d = %2d    ", j + 1, i + 1, (i + 1) * (j + 1));
		}
		printf("\n");
	}
	
	return 0;
}