// optimal page replacement

#include <stdio.h>

int is_in_frame(int key, int frame[], int c){
	for (int i = 0; i < c; i++)
		if (frame[i] == key)
			return 1;
	return 0;
}

int optimalInd(int page[], int frame[], int num_pages, int index,int c){
	int res = -1, last = index;
	for (int i = 0; i <c; i++) {
		int j;
		for (j = index; j < num_pages; j++) {
			if (frame[i] == page[j]) {
				if (j > last) {
					last = j;
					res = i;
				}
				break;
			}
		}
		if (j == num_pages)
			return i;
	}
    if(res == -1)
        return 0;
    else
        return res;
}

void optimalPage(int page[], int num_pages, int num_frames){
	int frame[num_frames];
    int c=0;
	int hit = 0;
	for (int i = 0; i < num_pages; i++) {
		if (is_in_frame(page[i], frame,c)) {
			hit++;
			continue;
		}
		if (c < num_frames){
            frame[c]=page[i];
            c++;
        }
		else {
			int j = optimalInd(page, frame, num_pages, i + 1,c);
			frame[j] = page[i];
		}
	}
	printf("Total page fault is %d\n",hit);;
	/** printf("No. of misses = %d\n",num_pages - hit); */
}

int main(){
	int page[100];
	int num_pages;
    printf("enter the number of pages: ");
    scanf("%d",&num_pages);
    printf("Enter the page reference string: ");
    for(int i=0;i<num_pages;i++)
        scanf("%d",&page[i]);
	int num_frames;
    printf("Enter the frame number: ");
    scanf("%d",&num_frames);
	optimalPage(page, num_pages, num_frames);
	return 0;
}
