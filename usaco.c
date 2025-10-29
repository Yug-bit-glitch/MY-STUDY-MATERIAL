#include<stdio.h>
#include<stdlib.h>

int compare(const void* a,const void *b){
    long long p1=*(long long*)a;
    long long p2=*(long long*)b;
    return p1-p2;
}

int lowerindex(long long* arr,int x,int n){
int low=0;
int high=n-1;
int idx=-1;
while(low<=high){
int mid=low+(high-low)/2;
if(arr[mid]>=x){
    idx=mid;
    high=mid-1;
}else{
    low=mid+1;
}
}
return idx;
}


int highindex(long long* arr,int x,int n){
int low=0;
int high=n-1;
int idx=-1;
while(low<=high){
int mid=low+(high-low)/2;
if(arr[mid]<=x){
    idx=mid;
    low=mid+1;
}else{
    high=mid-1;
}
}
return idx;
}

int main(){
int n,q;
scanf("%d %d",&n,&q);
long long arr[n];
for(int i=0;i<n;i++){
scanf("%lld",&arr[i]);
}
qsort(arr,n,sizeof(long long),compare);
for(int i=0;i<q;i++){
long long a,b;
scanf("%lld %lld",&a,&b);
printf("%d\n",highindex(arr,b,n)-lowerindex(arr,a,n)+1);
}
return 0;
}
