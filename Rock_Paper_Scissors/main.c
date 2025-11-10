#include <stdio.h>
#include "test.h"
#include <stdlib.h> // rand() と srand() のために必要

int main() {
    srand(time(NULL));	// 乱数生成器を現在の時刻で初期化
    printf("0はグー, 1はチョキ, 2はパーを表しています\n");
    int user_hand, com_hand;
    while (1) {
        user_hand = getUserHand();
        com_hand = getComputerHand();
        int win_lose_num = judge(user_hand, com_hand);
        displayResult(win_lose_num,user_hand, com_hand);
        if (win_lose_num != 0) {
            break;
        }
    }

    return 0;
}   