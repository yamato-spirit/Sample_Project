#include <stdio.h>
#include <time.h>   // time() のために必要
#include <string.h> // (今回は不要かもしれませんが、文字列操作の基本)
#include <ctype.h>  // isspace() のため

// じゃんけんゲーム
/* 1. ユーザーが出す手を入力
   2. コンピューターが自動で出す手を決定
   3. 勝ち負け判定→勝敗の表示

   ～AIに関数の分け方を聞いてみた結果～
   getUserHand(): ユーザーの入力を受け取る
   getComputerHand(): コンピューターの手をランダムに決める
   judge(): 2つの手を比較して勝敗を判定する
   displayResult(): 判定結果とそれぞれのT手を表示する
*/
int getUserHand(void) {
	char buffer[100];
	int result;
	int user_num; // ユーザーの手
	while (1) {
		printf("0,1,2のいずれかの数字を半角で入力してね！\n");
		// 1.ユーザーが入力をせずにCtrl + Cなどで作業を中断した際に実行するif文
		if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
			printf("入力に失敗しました\n");
			return -1; // エラーを通知
		}
		// 2.ユーザーからの入力を整数に変換
		char *Endptr; /* Endptrに整数に変換できなかったアドレスを格納 ex)\nの\ */ 
		user_num = (int)strtol(buffer, &Endptr, 10); // user_numには整数に変換できたものを格納する ex)123.2 → 123
		// 3. 入力の確認
		if (Endptr == buffer) {
			result = 0;
			printf("不正な入力です\n");
		}
		else {
			while (isspace((unsigned char)*Endptr)) { // 空白文字なら最後までポインタを進める
				Endptr++;
			}
			if ((*Endptr == '\n' || *Endptr == '\0') && (0 <= user_num && user_num <= 2)) {
				result = 1;
				break;
			}
			else {
				result = 0;
				printf("不正な入力です\n");
			}
		}
	}

	return user_num;
}
int getComputerHand(void) {
	int com_num = rand() % 3;

	return com_num;
}
int judge(int user, int com) {
	int win_lose_num = (user - com + 3) % 3; // 勝敗の判定を表す整数を格納

	return win_lose_num;
}
void displayResult(int win_lose_num, int user, int com) {
	char user_hand;
	char com_hand;
	
	switch (user) {
	case 0:
		printf("あなたの出した手はグー vs ");
		break;
	case 1:
		printf("あなたの出した手はチョキ vs ");
		break;
	case 2:
		printf("あなたの出した手はパー vs ");
		break;
	}
	switch (com) {
	case 0:
		printf("COMの出した手はグー\n");
		break;
	case 1:
		printf("COMの出した手はチョキ\n");
		break;
	case 2:
		printf("COMの出した手はパー\n");
		break;
	}

	switch (win_lose_num) {
	case 0:
		printf("あいこです...もう一回チャレンジ！！\n");
		break;
	case 1:
		printf("残念,,,あなたの負けです\n");
		break;
	case 2:
		printf("Congratulations！！あなたの勝ちです\n");
		break;
	}
	return;
}