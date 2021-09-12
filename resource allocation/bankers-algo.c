#include <stdio.h>
#include <stdlib.h>

int** d_allocate(int r,int c){
    int **mat = (int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        mat[i] = (int *)malloc(sizeof(int)*c);
    }
    return mat;
}

void input(int **mat,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

int main(){
    int **alloc,**max,*avail,**need,*sequence,*finished;
    int num_proc,num_res;
    printf("Enter the number of processes:  ");
    scanf("%d",&num_proc);
    printf("Enter the number of resources: ");
    scanf("%d",&num_res);

    alloc = d_allocate(num_proc,num_res);
    max = d_allocate(num_proc, num_res);
    need = d_allocate(num_proc, num_res);

    avail = (int *)calloc(num_proc,sizeof(int));
    finished = (int *)calloc(num_proc,sizeof(int));
    sequence = (int *)calloc(num_proc,sizeof(int));

    printf("Enter the allocation matrix:\n");
    input(alloc,num_proc,num_res);
    printf("Enter the maximum resource matrix:\n");
    input(max,num_proc,num_res);
    printf("Enter the available matrix:\n");
    for(int i=0;i<num_res;i++)
        scanf("%d",&avail[i]);

    int non_alloc = 0;
    // need matrix
    printf("NEED matrix :\n");
    for(int i=0;i<num_proc;i++){
        for(int j=0;j<num_res;j++){
            need[i][j] = max[i][j] - alloc[i][j];
            printf(" %d ",need[i][j]);
        }
        printf("\n");
    }
    int i=0;
    int is_allocatable = 1;
    int num_finished = 0;
    // non_alloc - number of continous non allocatable steps
    while(non_alloc<num_proc && num_finished<num_proc){
        i = i%num_proc;
        is_allocatable = 1;
        if(finished[i]==1)
            is_allocatable = 0;
  
        // if all resources are allocatable for current process
        for(int j=0;j<num_res;j++){
            if(need[i][j]>avail[j])
                is_allocatable = 0;
        }
        // avail = avail + alloc
        if(is_allocatable==1){
            non_alloc = 0;
            sequence[num_finished] = i;
            finished[i] = 1;
            num_finished++;
            for(int j=0;j<num_res;j++){
                avail[j] += alloc[i][j];
                need[i][j] = 0;
            }
        }
        else{
            non_alloc++;
        }
        ++i;
    }

    if(num_finished==num_proc){
        printf("sequence in which process is completed: ");
        int i=0;
        for(i=0;i<num_proc-1;i++){
            printf("P%d -> ",sequence[i]);
        }
        printf("P%d\n",sequence[i]);
    }else{
        printf("process cannot be completed\n");
    }
    return 0;
}
