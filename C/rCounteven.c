#include <stdio.h>
int rCountEvenDigits1(int num);
void rCountEvenDigits2(int num, int *result);
int main(){
    int number, result=0;

    printf("Enter the number: \n");
    scanf("%d", &number);

    printf("rCountEvenDigits1(): %d\n", rCountEvenDigits1(number));
    
    rCountEvenDigits2(number, &result);
    
    printf("rCountEvenDigits2(): %d\n", result);
    return 0;
}

int rCountEvenDigits1(int num){
/* Write your code here */
    if (num == 0){
        return 0;
    } else {
        int digit = num % 10;
        int remainder = rCountEvenDigits1(num / 10);
        if (digit%2 == 0){
            return remainder + 1;
        }else{
            return remainder;
        }
    }
}
void rCountEvenDigits2(int num, int *result){
/* Write your code here */
    if (num == 0){
        *result = 0;
    } else {
        int digit = num%10;
        rCountEvenDigits2(num/10, result);
        if (digit%2 == 0){
            *result += 1;
        }else{
            *result += 0;
        }
    }
}