#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int num;
    int a_time;
    int b_time;
    int tat_time;
    int wt_time;
    int c_time;
    int remaining_time;
    int isdone;
}process;

process *p;
int n;
int tq;

int short_a(const void* a, const void *b){
    process *c = (process *)a;
    process *d = (process *)b;
    if(c->a_time > d->a_time)
        return 1;
    return 0;
}


void completion_time(){
    qsort(p,n,sizeof(process),short_a);
    for(int i=0;i<n;i++){
        p[i].remaining_time = p[i].b_time;
        p[i].isdone = 0;
    }
    int completed=0;
    int i=0;
    int total=0;
    while(completed < n){
        i%=n;
        if(p[i].isdone == 0){
            if(p[i].remaining_time>=tq)
                total+=tq;
            else
                total+=p[i].remaining_time;
            p[i].remaining_time -= tq;
        }
        if(p[i].isdone == 0 && p[i].remaining_time <=0 ){
            p[i].isdone=1;
            p[i].c_time = total;
            completed++;
        }
        i++;
    }
}

void tat_time(){
    for(int i=0;i<n;i++){
        p[i].tat_time = p[i].c_time - p[i].a_time;
    }
}
void waiting_time(){
    for(int i=0;i<n;i++){
        p[i].wt_time = p[i].tat_time - p[i].b_time;
    }
}

void average(){
    completion_time();
    tat_time();
    waiting_time();
    int t_tat=0,t_wt=0;
    for(int i=0;i<n;i++){
        t_tat += p[i].tat_time;
        t_wt += p[i].wt_time;
    }
    printf("average tat time: %f\n",(t_tat*1.0/n));
    printf("average wt time: %f\n",(t_wt*1.0/n));
}
void input(){
    p = (process *)malloc(n*sizeof(process));
    printf("Enter the burst time and arrival time:\n");
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].b_time,&p[i].a_time);
    }
    printf("enter the time slice: ");
    scanf("%d",&tq);
}

int main(){
    printf("Enter the number of process: ");
    scanf("%d",&n);
    input();
    average();
    return 0;
}
