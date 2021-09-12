#include  <stdio.h>

int mutex=1;
int full=0, empty=10;
int x=0;

void producer(){
    mutex--;
    empty--;
    full++;
    x++;
    printf("prodcuer creates %d\n",x);
    mutex++;
}

void consumer(){
    mutex--;
    empty++;
    full--;
    printf("consumer uses %d\n",x);
    x--;
    mutex++;
}

int main(){
    int n;
    printf("1 - producer\n2 - consumer\n3 - exit\n");
    while(1){
        printf("Enter the option: ");
        scanf("%d",&n);
        if(n==3)
            break;
        else if(n==1){
            if(mutex==1 && empty!=0)
                producer();
            else
             printf("buffer is full\n");
        }
        else if(n==2){
            if(mutex==1 && full!=0)
                consumer();
            else
                printf("buffer is empty\n");
        }
    }
}
