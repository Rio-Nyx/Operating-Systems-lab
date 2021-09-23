/*shared memory model of ipc uses a buffer which is shared among producer and consumer
 *the buffer can be bounded or unbounded
 * */
#include <stdio.h>
#include <stdlib.h>

int in=0,out=0;
int size;
int *buffer;
int x;

void producer(){
    int next=1;
    // if buffer is full
    buffer[in] = next;
    printf("producer producing %d\n",in+1);
    in = (in+1)%size;
    x++;
}

void consumer(){
    int next;
    next = buffer[out];
    printf("consumer consumes %d\n",out);
    out = (out+1)%size;
    x--;
}

int main(){
    printf("Enter the size of buffer: ");
    scanf("%d",&size);
    buffer = (int *)calloc(size+1,sizeof(int));
    int op;
    while(1){
        printf("1.producer\n2.consumer\n3.exit\n");
        scanf("%d",&op);
        if(op == 1){
            if((in+1)%size == out)
                printf("buffer is full\n");
            else
                producer();
        }else if(op == 2){
            if(in == out) 
                printf("Buffer is empty\n");
            else
                consumer();
        }else if(op == 3){
            break;
        }
    }
    return 0;
}
