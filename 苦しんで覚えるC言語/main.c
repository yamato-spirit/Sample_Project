#include <stdio.h>

int main(void) {
	int drink = 198;
	int milk = 138;
	float tax = 0.05; // 消費税率
	int sum, change;
	sum = drink * 1 + milk * 2; // 金額合計(税抜き)
	change = 1000 - (int)(sum * (1 + tax)); // おつり (int) → キャスト変換を忘れない！！
	printf("清涼飲料水1本と牛乳2本を1,000円で購入した際のおつりは%d円です\n", change);
	return 0;
}