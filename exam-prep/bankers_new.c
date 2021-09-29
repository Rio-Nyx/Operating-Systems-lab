#include <stdio.h>

int num_procs, num_res;
int **max, **alloc, **need;
int *avail, *finished;

int **allocate(){
    int **alloc = (int **)malloc(num_procs*sizeof(int *));
    for(int i=0;i<num_procs;i++){
        alloc[i] = (int *)calloc(num_res,sizeof(int));
    }
    return alloc;
}

void calc_need(){
    for(int i=0;i<num_procs;i++){
        for(int j=0;j<num_res;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void deadlock(){
    for(int i=0;i<n;i++){
        for()
    }
}

void input(){
    printf("Enter the number of process: ");
    scanf("%d",&num_procs);
    printf("Enter the number of resources: ");
    scanf("%d",&num_res);
    
    max = allocate();
    alloc = allocate();
    need = allocate();
    avail = (int*)calloc(num_res,sizeof(int));
    finished  = (int*)calloc(num_procs,sizeof(int));


    printf("Enter the MAX matrix: \n");
    for(int i=0;i<num_procs;i++){
        for(int j=0;j<num_res;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the ALLOC matrix: \n");
    for(int i=0;i<num_procs;i++){
        for(int j=0;j<num_res;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("Enter the avail matrix: \n");
    for(int i=0;i<num_res;i++){
        scanf("%d",&avail[i]);
    }
}

int main(){

    return 0;
}
