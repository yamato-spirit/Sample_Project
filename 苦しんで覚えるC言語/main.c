#include <stdio.h>

int main(void) {
	int tensu;
	do {
		printf("1～100までの点数を入力してください\n");
		scanf_s("%d", &tensu);
	} while (tensu < 0 || 100 < tensu);
	printf("テスト結果は%d点です\n", tensu);
	
	return 0;
}