#include <stdio.h>
#include <stdlib.h>

int** d_allocate(int r,int c){
    int **mat = (int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        mat[i] = (int *)malloc(c*sizeof(int));
    }
    return mat;
}

int main(){
    int num_procs,num_resources;
    printf("Enter the no: of processes: ");
    scanf("%d",&num_procs);
    printf("Enter the number of resources: ");
    scanf("%d",&num_resources);

    int **max = d_allocate(num_procs, num_resources);
    int **need = d_allocate(num_procs, num_resources);
    int **alloc = d_allocate(num_procs, num_resources);

    int *avail = (int *)calloc(num_resources,sizeof(int));
    int *finished = (int *)calloc(num_procs,sizeof(int));

    printf("Enter the max matrix:\n");
    for(int i=0;i<num_procs;i++)
            for(int j=0;j<num_resources;j++)
                scanf("%d",&max[i][j]);
    printf("enter the allocation matrix:\n");
    for(int i=0;i<num_procs;i++)
            for(int j=0;j<num_resources;j++)
                scanf("%d",&alloc[i][j]);
    for(int i=0;i<num_resources;i++)
        scanf("%d",&avail[i]);
    for(int i=0;i<num_procs;i++)
            for(int j=0;j<num_resources;j++)
                need[i][j] = max[i][j] - alloc[i][j];
    int i=0;
    int non_allocs = 0;
    while(non_allocs<num_procs ){
        if(i == num_procs)
            i=0;
        if(finished[i] == 1){
            i++;
            non_allocs++;
            continue;
        }
        else{
            int flag = 0;
            for(int j=0;j<num_resources;j++){
                if(need[i][j]>avail[j])
                    flag = 1;
            }
            if(flag == 0){
                finished[i] = 1;
                printf("p[%d] -> ",i);
                for(int j=0;j<num_resources;j++)
                    avail[j] += alloc[i][j];
            }
            else{
                non_allocs++;
            }
        }
        i++;
    }

    return 0;
}
