// page replacement
// lfu,keep count of previous hits in frame
// replace the one with least frequency

#include <stdio.h>
#include <stdlib.h>

int *page;
int *frame;
int num_pages,num_frames;
// frequency, input number
int **frequency_frame;
int num_faults=0;

int is_in_frame(int p){
    for(int i=0;i<num_frames;i++){
        if(p == frame[i])
            return i;
    }
    return -1;
}

int min_of_freq(){
    int MIN = 10000;
    int ind=-1;
    int order=0;
    for(int i=0;i<num_frames;i++){
        if(frequency_frame[i][0]<=MIN){
            if(MIN==10000 || frequency_frame[i][1]<order){
                MIN = frequency_frame[i][0];
                order = frequency_frame[i][1];
                ind = i;
            }
        }
    }
    return ind;
}

void lfu(){
    /** printf("dkfspfsf"); */
    for(int i=0;i<num_frames;i++){
        frequency_frame[i][0] = -1;
        frequency_frame[i][1] = i - num_frames;
    }
    for(int i=0;i<num_pages;i++){
        /** if(i==2){ */
        /**     for(int j=0;j<num_frames;j++) */
        /**         printf("\n__  %d  %d__\n",frame[j],is_in_frame(page[i])); */
        /** } */
        if(is_in_frame(page[i]) != -1){
            frequency_frame[is_in_frame(page[i])][0]++;
            frequency_frame[is_in_frame(page[i])][1] = i;
        }else{
            printf("page %d - %d not in\n",i,page[i]);
            int ind = min_of_freq();
            num_faults++;
            printf("\n__%d__\n",ind);
            /** if(ind == -1){ */
            /**     printf("inside error\n"); */
            /**     continue; */
            /** } */
            frame[ind] = page[i];
            frequency_frame[ind][0] = 0;
            frequency_frame[ind][1] = i;
        }
    }
}

void input(){
    printf("Enter the number of pages: ");
    scanf("%d",&num_pages);
    printf("Enter the number of frames: ");
    scanf("%d",&num_frames);
    page = (int *)calloc(num_pages,sizeof(int));
    frame = (int *)calloc(num_frames,sizeof(int));
    frequency_frame = (int **)malloc(num_frames*sizeof(int*));
    for(int i=0;i<num_frames;i++)
        frequency_frame[i] = (int *)malloc(3*sizeof(int));
    printf("Enter the number of pages: \n");
    for(int i=0;i<num_pages;i++)
        scanf("%d",&page[i]);
    /** printf("Enter the number of frames: \n"); */
    /** for(int i=0;i<num_frames;i++) */
    /**     scanf("%d",&frame[i]); */
    
}

int main(){
    input();
    lfu();
    printf("number of faults: %d\n",num_faults);
    return 0;
}
