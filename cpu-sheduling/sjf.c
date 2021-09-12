/*
 *shortest job first
 * non-preemptive algorithm
 * */

#include <stdio.h>
#include <stdlib.h>

#define NUM 4

typedef struct process{
    int num;        // process number
    int isCompleted;  // true if completed
    int b_time;     // burst time
    int a_time;     // arrival time
    int c_time;     // completion time
    int tat_time;   // turn-around-time
    int w_time;     // waiting time
}process;

int short_b(const void *a,const void *b ){
    process *c = (process *)a;
    process *d = (process *)b;
    if(c->b_time > d->b_time)
        return 1;
    else
        return 0;
}

void completion_time(process p[]){
    qsort(p,NUM,sizeof(process),short_b);      // sort in ascending order of burst time
    int total_completion_time = 0, completed;
    for (int i=0;i<NUM; i++) {
        if(completed==NUM)
            break;
        if(p[i].isCompleted==0 && total_completion_time >= p[i].a_time){
            total_completion_time += p[i].b_time;
            p[i].c_time = total_completion_time;
            p[i].isCompleted = 1;
            completed++;
            /** printf("%d__%d__",p[i].num,p[i].c_time); */
            /** printf("\n"); */
            i=-1;

        }
    }
    /** for(int i=0;i<NUM;i++){ */
    /**     printf("%d__%d__",p[i].num,p[i].c_time); */
    /**     printf("\n"); */
    /** } */
   }

void turn_around_time(process p[]){
    for(int i=0;i<NUM;i++){
        p[i].tat_time = p[i].c_time - p[i].a_time;
    }
}

void waiting_time(process p[]){
    for(int i=0;i<NUM;i++){
        p[i].w_time = p[i].tat_time - p[i].b_time;
    }
}

void avg_time(process p[]){
    completion_time(p);
    turn_around_time(p);
    waiting_time(p);
    float avg_tat_time,avg_w_time;
    avg_tat_time = avg_w_time = 0;
    for(int i=0;i<NUM;i++){
        avg_tat_time += p[i].tat_time;
        avg_w_time += p[i].w_time;
    }
    avg_tat_time = avg_tat_time*1.0/NUM;
    avg_w_time = avg_w_time*1.0/NUM;
    printf("average turn around time: %f\n",avg_tat_time);
    printf("average waiting time: %f\n",avg_w_time);
}

void input(process p[]){
    for(int i=0;i<NUM;i++){
        printf("Enter the process %d burst time: ",i);
        scanf("%d",&p[i].b_time);
        printf("Enter the process %d arrival time: ",i);
        scanf("%d",&p[i].a_time);
        p[i].num = i;
        p[i].c_time =0;
        p[i].tat_time =0;
        p[i].w_time =0;
        p[i].isCompleted=0;
    }
}

int main(){

    process p[NUM];
    input(p);
    avg_time(p);
    return 0;
}
