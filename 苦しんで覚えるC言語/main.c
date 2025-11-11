#include <stdio.h>

int main(void) {
	int reg_price;
	int sale_rate[] = {1, 3, 5, 8};
	float sale_price[] = {0.1, 0.3, 0.5, 0.8};
	printf("定価を入力して下さい\n");
	scanf_s("%d", &reg_price);
	for (int i = 0; i < 4; i++) {
		printf("定価の%d割引は%d円です\n", sale_rate[i], (int)(reg_price * (1 - sale_price[i]) + 0.5)); 
		// +0.5をint(キャスト変換)前に加えて、8割引が定価 * 0.1999...になる問題を解決
	}
	
	return 0;
}