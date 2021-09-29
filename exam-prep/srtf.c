#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n;
int current_time;

typedef struct process{
    int num;
    int a_time;
    int b_time;
    int c_time;
    int tat_time;
    int wt_time;
    int remaining_time;
    int isfinished;
}process;

process *p;

int short_a(const void*a, const void *b){
    process *c = (process *)a;
    process *d = (process *)b;
    if(c->a_time>d->a_time)
        return 1;
    return 0;
}

// process with mininum remaining time and arrival time<=completion_time
int find_proc(){
    int ind = -1;
    int min = 10000;
    for(int i=0;i<n;i++){
        if(p[i].isfinished == 0 ){
            if(p[i].a_time<=current_time && p[i].remaining_time<min){
                /** if(i==2 || i==3) */
                /**     printf("--%d--%d--\n",i,p[i].remaining_time); */
                /** if(i==3) */
                /**     printf("burst time : %d--%d\n",min,p[i].b_time); */
                min = p[i].remaining_time;
                ind = i;
            }
        }
    }
    return ind;
}

void completion_time(){
    int finished = 0;
    qsort(p,n,sizeof(process),short_a);
    current_time = 0;
    while(finished<n){
        /** if(i==n) */
        /**     i=0; */
        int ind = find_proc();
        printf("%d\n",ind);
        if(ind != -1){
            p[ind].remaining_time--;
        }
        if(p[ind].remaining_time == 0){
            p[ind].isfinished = 1;
            finished++;
            p[ind].c_time = current_time+1;
        }
        current_time++;
        /** sleep(1); */
    }
}

void tat_time(){
    for(int i=0;i<n;i++){
        p[i].tat_time = p[i].c_time - p[i].a_time;
    }
}

void wt_time(){
    for(int i=0;i<n;i++){
        p[i].wt_time = p[i].tat_time - p[i].b_time;
    }
}

void average(){
    int t_tat=0,t_wt=0;
    for(int i=0;i<n;i++){
        t_tat+=p[i].tat_time;
        t_wt+=p[i].wt_time;
    }
    printf("arverage tat: %f\n",(t_tat*1.0/n));
    printf("arverage wt: %f\n",(t_wt*1.0/n));
}

void input(){
        printf("enter number of process: \n");
        scanf("%d",&n);
        p = (process *)malloc(n*sizeof(process));
        printf("enter the process arival and burst time:\n");
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].a_time,&p[i].b_time);
        }
        for(int i=0;i<n;i++){
            p[i].isfinished = 0;
            p[i].remaining_time = p[i].b_time;
        }
}

void srtf(){
    input();
    completion_time();
    tat_time();
    wt_time();
    average();
}

int main(){
    srtf();
    return 0;
}
