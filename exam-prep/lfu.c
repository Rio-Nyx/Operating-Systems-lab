#include <stdio.h>
#include <stdlib.h>

int num_pages,num_frames,page_faults;
int *frame, *page;
int *frequency;
int *recency;

void allocate(){
    frame = (int *)malloc(num_frames*sizeof(int));
    page = (int *)malloc(num_pages*sizeof(int));
    frequency = (int *)malloc(num_frames*sizeof(int));
    recency = (int *)malloc(num_frames*sizeof(int));
}

int is_in_frame(int p){
    for(int i=0;i<num_frames;i++)
        if(frame[i]==p)
            return i;
    return -1;
}

void input(){
    printf("Enter the number of pages: ");
    scanf("%d",&num_pages);
    printf("Enter the number of frames: ");
    scanf("%d",&num_frames);
    printf("enter the page reference string: ");
    for(int i=0;i<num_pages;i++)
        scanf("%d",&page[i]);
    for(int i=0;i<num_frames;i++){
        frequency[i] = i-num_frames;
        frame[i] = -1;
        recency[i] = -1;
    }

}

void completion_time(){
    page_faults = 0;
    for(int i=0;i<num_pages;i++){
        if(is_in_frame(page[i]) !=-1){
            frequency[is_in_frame(page[i])]++;
            recency[is_in_frame(page[i])] = i;
        }
        else{
            page_faults++;
            int min = 1000;
            int pr_rec = -1;
            int ind = -1;
            for(int j=0;j<num_frames;j++){
                if(frequency[j]<=min){
                    if((frequency[j]==min && recency[j]>pr_rec) || frequency[j]<min){
                        min = frequency[j];
                        ind = j;
                        pr_rec = recency[j];
                    }
                }
            }
            frequency[ind] = 0;
            recency[ind] = i;
            frame[ind] = page[i];
        }
    }
    printf("number of page_faults: %d\n",page_faults);
}

void lfu(){
    allocate();
    input();
    completion_time();
}
int main(){
    lfu();
    return 0;
}
