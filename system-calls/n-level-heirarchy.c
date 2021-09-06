#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void processes(int n){
    int p;
    for(int i=0;i<n;i++){
        p = fork();
        if(p == 0){
            printf("process id: %d and parent id: %d\n",getpid(),getppid());
        }
        else
            exit(0);
    }
    for(int i=0;i<3;i++)
        wait(NULL);
}

int main(){
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    processes(n);
    return 0;
}
