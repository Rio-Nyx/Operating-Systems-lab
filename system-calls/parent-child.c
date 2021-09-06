#include <stdio.h>
#include <unistd.h>
void child(int n){
    int a,b;
    a=0;b=1;
    for(int i=0;i<n;i++){
        printf("Fibonacci number %d\n",a);
        b=a+b;
        a=b-a;
    }
}

void parent(int n){
    int count=0;
    int num=2;
    int isPrime=1;
    int f=fork();
    
    if(f>0){
        while(count<n){
            isPrime=1;
            for(int i=2;i<=num/2;i++){
                if(num%i==0)
                    isPrime=0;
            }
            if(isPrime==1){
                count++;
                printf("Prime number: %d \n",num);
            }
            num++;
        }
    }
    else
        child(n);
}

int main(){
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    parent(n);
   return 0; 
}
