/*memoize it/
#include<stdio.h>

int way(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    if(n==2)return 2;
    if(n==3)return 4;
    return way(n-1)+way(n-2)+way(n-3);
}

int main(){
int n;
scanf("%d",&n);
printf("%d",way(n));
    return 0;
}
