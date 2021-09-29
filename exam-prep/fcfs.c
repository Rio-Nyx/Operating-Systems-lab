// fcfs
// tat = ct-at 
// wt = tat-bt
//input - at,btr

#include <stdio.h>
#include <stdlib.h>

typedef struct process{
    int num;
    int b_time;
    int a_time;
    int c_time;
    int tat_time;
    int wt_time;
}process;

process *p;
int n;

int short_a(const void *a,const void *b){
    process* c = (process *)a;
    process* d = (process *)b;
    if(c->a_time>d->a_time)
        return 1;
    return 0;
}

void completion_time(){
    printf("");
    qsort(p,n,sizeof(process),short_a);
    int total = 0;
    for(int i=0;i<n;i++){
        if(total< p[i].a_time)
            total=p[i].a_time;
        p[i].c_time = p[i].b_time + total;
        total = p[i].c_time;
    }
}

void tat_time(){
    for(int i=0;i<n;i++)
        p[i].tat_time = p[i].c_time - p[i].a_time;
}

void waiting_time(){
    for(int i=0;i<n;i++)
        p[i].wt_time = p[i].tat_time - p[i].b_time;
} 

void average(){
    completion_time();
    tat_time();
    waiting_time();
    for(int i=0;i<n;i++)
        printf(" %d ",p[i].c_time);
    int t_tat=0,t_wt=0;
    for(int i=0;i<n;i++){
        t_tat += p[i].tat_time;
        t_wt += p[i].wt_time;
    }
    printf("average tat: %f\n",(t_tat*1.0/n));
    printf("average wt: %f\n",(t_wt*1.0/n));
}

void input(){
    /** int num_procs; */
    /** printf("enter the number of processes : "); */
    /** scanf("%d",&num_procs); */
    printf("Enter the burst time and arrival time of %d processes:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].b_time,&p[i].a_time);
    }
}

int main(){
    printf("Enter the number of proceses: ");
    scanf("%d",&n);
    p = (process *)malloc(n*sizeof(process));
    input();
    average();
    return 0;
}
