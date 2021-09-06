// memory allocation-first fit

#include <stdio.h>
#include <stdlib.h>

void first_fit(int *block,int *process,int num_blocks,int num_procs){
    // block size
    int *proc_in_block = (int*)malloc(num_blocks*sizeof(int));
    for(int i=0;i<num_blocks;i++)
        proc_in_block[i] = -1;
    printf("Enter the block sizes\n");
    for(int i=0;i<num_blocks;i++)
        scanf("%d",&block[i]);
    printf("Enter the process sizes\n");
    for(int i=0;i<num_procs;i++)
        scanf("%d",&process[i]);
    for(int i=0;i<num_procs;i++){
        int flag=0;
        for(int j=0;j<num_blocks;j++){
            if(process[i]<=block[j] && proc_in_block[j]==-1){
                proc_in_block[j] = i;
                block[j]-=process[i];
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("process %d couldn't be allocated\n",i);
    }
    printf("Block no.  free memory  proccess allocated\n");
    for(int i=0;i<num_blocks;i++){
        printf("%d \t\t %d \t\t %d\n",i,block[i],proc_in_block[i]);
    }
}
int main(){
    int num_blocks,num_procs;
    int *block,*process;
    printf("Enter the number of blocks: ");
    scanf("%d",&num_blocks);
    printf("Enter the number of process: ");
    scanf("%d",&num_procs);
    block = (int*)malloc(num_blocks*sizeof(int));
    process = (int*)malloc(num_procs*sizeof(int));

    first_fit(block,process,num_blocks,num_procs);

    return 0;
}
