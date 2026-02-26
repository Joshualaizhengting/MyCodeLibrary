#include <stdio.h>
void rPattern1(int height);

int main(){
    int height;
    
    printf("Enter the height: \n");
    scanf("%d", &height);
    
    printf("The pattern is: \n");
    rPattern1(height);
    
    return 0;
}

void rPattern1(int height){
 /* Write your code here */
    if (height == 0){
        return;
    }else{
        rPattern1(height - 1);
        for (int i = 0; i<height; i++){
            printf("*"); 
        }
        printf("\n");
    }
}