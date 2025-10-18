#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
char *s=(char*)malloc(100001);
scanf("%100000s",s);
int len=strlen(s);
char * left=s;
char * right=s+len-1;

while(left<right){
    char temp=*left;
    *left=*right;
    *right=temp;
    left++;
    right--;
}

printf("%s",s);
free(s);
}
