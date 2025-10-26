#include <stdio.h>
int main(){
    int x=5,y=6,z=7;
    int *arr[]={&x,&y,&z};
    int **p=arr+1;
    **p=10;
    printf("%d %d %d\n", x,y,z);
    return 0;
}
