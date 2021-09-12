// least recently used page reference will be removed from frame

#include <stdio.h>

int is_in_frame(int page_ref, int frame[][2], int num_frames){
    for(int i=0;i<num_frames;i++){
        if(page_ref==frame[i][0])
            return i;
    }
    return -1;
}

int min(int arr[][2], int size){
    int ind = -1;
    int MIN = 10000;
    for(int i=0;i<size;i++){
        if(arr[i][1]<MIN ){
            MIN = arr[i][1];
            ind = i;
        }
    }
    return ind;
}

void lru(){
    int num_pages,num_frames,num_faults;
    int page[101], frame[25][2], lru[25]; // page[][0] stores the reference and [][1] stores the recency number
    printf("Enter the number of pages: ");
    scanf("%d",&num_pages);
    printf("Enter the page reference string: ");
    for(int i=0;i<num_pages;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the number frame: ");
    scanf("%d",&num_frames);
    num_faults=0;
    for(int i=0;i<num_frames;i++)
        frame[i][1]=-1;
    for(int i=0;i<num_pages;i++){
        if(is_in_frame(page[i],frame,num_frames)==-1){
            int ind = min(frame,num_frames);
            frame[ind][0]=page[i];
            num_faults++;
            frame[ind][1]=i;
        }
        else{
            int ind = is_in_frame(page[i],frame,num_frames);
            frame[ind][1] = i;
        }
    }
    printf("number of page faults is %d\n",num_faults);
}

int main(){
    lru();
    return 0;
}
