# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/shm.h>
# include <sys/ipc.h>
/** # include <semaphore.h> */


int main(){
    const char * name = "string";
    key_t key = ftok(name,52);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    int *temp = (int *)shmat(shmid,(void *)0,0);
    int in = 0;
    int max = 100;
    int iteration = 10;
    while(iteration--){
        temp[in] = rand() % 1000;
        printf("Producer produces: %d\n",temp[in]);
        in= (in+1)%max;
        sleep(rand()%3);
    }
    shmdt(temp);
    return 0;
}
