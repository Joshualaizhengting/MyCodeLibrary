#include <stdio.h>
#include <string.h>

void rStrReverse2(char *str, int n);

int main(){
    char str[40], *p;

    printf("Enter a string: \n");
    fgets(str, 40, stdin);
    if (p=strchr(str,'\n'))
    *p = '\0';

    rStrReverse2(str,strlen(str));
    printf("rStrReverse2(): %s", str);
    
    return 0;
}

void rStrReverse2(char *str, int n){
/* Write your code here */
    int left = 0;
    int right = n-1;

    if (left >= right){
        return;
    }else{
        char c = str[left];
        str[left] = str[right];
        str[right] = c;

        rStrReverse2(str+1, n-2);
    }
}