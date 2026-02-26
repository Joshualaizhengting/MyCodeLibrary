#include <stdio.h>
#define SIZE 20

int rCountArray(int array[], int n, int a);

int main(){
    int array[SIZE];
    int index, count, target, size;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    
    printf("Enter %d numbers: \n", size);
    
    for (index = 0; index < size; index++){
        scanf("%d", &array[index]);}
    
    printf("Enter the target number: \n");
    scanf("%d", &target);

    count = rCountArray(array, size, target);
    printf("rCountArray(): %d\n", count);
    return 0;
}

int rCountArray(int array[], int n, int a){
/* Write your program code here */
    int count = 0;    
    if (n == 0){
        return 0;
    }else{
        if (array[0] == a){
            count += 1;
        }
        return count + rCountArray(array+1, n-1, a);
    }   
}

/*int rCountArray(int array[], int n, int a){
    if (n==0){
        return 0
    }else{
        => return (if a match, add 1, else add 0) + count from rest doing the same
        return (array[0] == a ? 1:0) + rCountArray(array + 1, n-1, a);
    }
}
*/
