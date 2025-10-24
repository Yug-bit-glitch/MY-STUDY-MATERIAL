#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 2000
#define N 51

typedef struct{
    char name[N];
    int balance;
}account;

account a[MAX];

int acc=0;

int find_acc(const char* name){
    for(int i=0;i<acc;i++){
        if(strcmp(a[i].name,name)==0){
            return i;
        }
    }
    return -1;
}
// the adress of first letter is passed in string it reads till we get a null terminator
int get_acc(const char* name){
    int idx=find_acc(name);
    // idx is maintained to score the details of accounts in array
    // idx is updated to acc that is count of no of accounts dynamicaaly 
    if(idx==-1){
        strcpy(a[acc].name,name);
        a[acc].balance=0;
        idx=acc;
        acc++;
    }
    // idx returned is used in withdraw,deposit and all other functions
    return idx;
}

void deposit(const char* name,int amount){
int idx=get_acc(name);
a[idx].balance+=amount;
}

void withdraw(const char*name,int amount){
    int idx=get_acc(name);
    if(a[idx].balance>=amount){
        a[idx].balance-=amount;
    }else{
        printf("-1\n");
    }
}

void check(const char*name){
    int idx=get_acc(name);
    printf("%d\n",a[idx].balance);
}

void transfer(const char* name1,const char* name2,int amount){

int idx1=get_acc(name1);
int idx2=get_acc(name2);

if(a[idx1].balance>=amount){
    a[idx1].balance-=amount;
    a[idx2].balance+=amount;
}else{
    printf("-1\n");
}

}

int main(){
    int q;
    scanf("%d",&q);
// in scanf this style is new for me 
    for(int i=0;i<q;i++){
 
        char nau[10];
        scanf("%s",nau);

    if(strcmp(nau,"DEPOSIT")==0){
        char name[N];
        int amount;
        scanf("%s %d",name,&amount);
        deposit(name,amount);
    }else if(strcmp(nau,"WITHDRAW")==0){
        char name[N];
        int amount;
        scanf("%s %d",name,&amount);
        withdraw(name,amount);
    }else if(strcmp(nau,"CHECK")==0){
        char name[N];
        scanf("%s %d",name);
        check(name);
    }else if(strcmp(nau,"TRANSFER")==0){
        char name1[N];
        char name2[N];
        int amount;
        scanf("%s %s %d",name1,name2,&amount);
        transfer(name1,name2,amount);
    }

}
return 0;
}
