// first in first out

#include <stdio.h>
#include <stdlib.h>

int is_in_frame(int page_ref, int frame[], int num_frames){
    for(int i=0;i<num_frames;i++){
        if(page_ref==frame[i])
            return 1;
    }
    return -1;
}

void fifo(){
    int num_pages,num_frames,num_faults,first;
    int page[101], frame[25];
    printf("Enter the number of pages: ");
    scanf("%d",&num_pages);
    printf("Enter the page reference string: ");
    for(int i=0;i<num_pages;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the number frame: ");
    scanf("%d",&num_frames);
    num_faults=0;
    first=0;
    for(int i=0;i<num_pages;i++){
        if(is_in_frame(page[i],frame,num_frames)==-1){
            num_faults++;
            frame[first]=page[i];
            first=(first+1)%num_frames;
        }
    }
    printf("The number of page faults is %d\n",num_faults);
}

int main(){
    fifo();
    return 0;
}
