// first fit , process is allocated to first encountered allocatable block

#include <stdio.h>
#include <stdlib.h>

int main(){
    int num_procs,num_blocks;
    printf("Enter the number of processes: ");
    scanf("%d", &num_procs);
    printf("enter the num of blocks: ");
    scanf("%d",&num_blocks);

    int *process = (int *)calloc(num_procs,sizeof(int));
    int *block = (int *)calloc(num_blocks,sizeof(int));
    int *allocated = (int *)calloc(num_blocks,sizeof(int));
    
    for(int i=0;i<num_blocks;i++)
        allocated[i] = -1;

    printf("Enter the process : ");
    for(int i=0;i<num_procs;i++)
        scanf("%d",&process[i]);
    printf("enter the blocks:");
    for(int i=0;i<num_blocks;i++)
        scanf("%d",&block[i]);

    for(int i=0;i<num_procs;i++){
        /** int flag = 0; */
        int min = 100000;
        int ind = -1;
        for(int j=0;j<num_blocks;j++){
            if(allocated[j] != -1)
                continue;
            if(min>block[j] && block[j]>=process[i]){
                min = block[j];
                ind = j;
            }
            /** if(process[i]<=block[j]){ */
            /**     allocated[j] = i; */
            /**     flag = 1; */
            /**     break; */
            /** } */
        }
        if(ind == -1){
            printf("process  %d is not allocated\n",i);
        }
        else{
            allocated[ind]= i;
            printf("process %d is allocated\n",i);
        }
    }
        for(int i=0;i<num_blocks;i++){
            printf("%d  %d  %d\n",i,block[i],allocated[i]);
        }

    return 0;
}
