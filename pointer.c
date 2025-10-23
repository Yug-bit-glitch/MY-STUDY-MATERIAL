#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n;
    scanf("%d",&n);

    int *length=(int*)malloc(n*sizeof(int));

    int **matrix=(int**)malloc(n*sizeof(int*));


    for(int i=0;i<n;i++){
        scanf("%d",&length[i]);
        matrix[i]=(int *)malloc(length[i]*sizeof(int));
        for(int j=0;j<length[i]){
            scanf("%d",&matrix[i][j]);
        }
    }

    for(i=n-1;i>=0;i--){
        for(int j=0;j<length[i];j++){
            printf("%d ",matrix[i][j])
        }
        printf("\n");
    }
    for(int i =0;i<n;i++){
        free(matrix[i]);
    }
    free(matrix);
    free(length);

}
