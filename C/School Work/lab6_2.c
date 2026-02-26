#include <stdio.h>
int rDigitPos1(int num, int digit);
void rDigitPos2(int num, int digit, int *pos);

int main(){
    int number, digit, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);

    printf("Enter the digit: \n");
    scanf("%d", &digit);

    printf("rDigitPos1(): %d\n", rDigitPos1(number, digit));
    rDigitPos2(number, digit, &result);

    printf("rDigitPos2(): %d\n", result);
    return 0;
}

int rDigitPos1(int num, int digit){
/* Write your program code here */
    if (num == 0){
        return 0;
    }
    if (num%10 == digit){
        return 1;
    }else{
        int result = rDigitPos1(num/10, digit);
        return result == 0 ? -1: result + 1;
        /* if result == 0 => this means digit not found -> which means we gotta get rid of
        all the valus accumulated from recursing if result is 0 -> -1 */
    }
}

/* in this case i think that using pointers is much easier */

void rDigitPos2(int num, int digit, int *pos){
/* Write your program code here */
    if (num == 0){
        *pos = 0;
        return;
    }
    if (num%10 == digit){
        *pos = 1;
        return;

    }else{
        rDigitPos2(num/10, digit, pos);
        /* only add 1 when digit is found if not dont*/
        if (*pos != 0){
            *pos += 1;
        }
    }
}