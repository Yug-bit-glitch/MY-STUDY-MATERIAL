#include<stdio.h>

int main(){
    int n,q;
    scanf("%d %d",&n,&q);

    long long a[n+1];
    for(int i=1;i<n+1;i++){
        scanf("%lld",&a[i]);
    }

    long long pre_sum[n+1];
    pre_sum[0]=0;
    for(int i=1;i<n+1;i++){
        // take care in this step 
        // prefer 1 index not 0
        pre_sum[i]=pre_sum[i-1]+a[i];
    }

    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        if(l==1){
            printf("%lld\n",pre_sum[r]);
        }else{
            printf("%lld\n",pre_sum[r]-pre_sum[l-1]);
        }
    }
    return 0;
}