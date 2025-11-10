#include <stdio.h>
#include "test.h"

int main() {
    printf("0はグー, 1はチョキ, 2はパーを表しています\n");
    int user_hand, com_hand;
    while (1) {
        user_hand = getUserHand();
        com_hand = getComputerHand();
        int win_lose_num = judge(user_hand, com_hand);
        displayResult(win_lose_num);
        if (win_lose_num != 0) {
            break;
        }
    }
    

    return 0;
}   