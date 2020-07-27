#include <stdio.h>

void swap(int nums[], int i, int j){
	int temp = nums[j];
	nums[j] = nums[i];
	nums[i] = temp;
}

int quicksortPartition(int nums[], int low, int high){
	int pivot = nums[high];
	int i = low;
	int temp, a, b;
	
	for(int j = low; j < high; j++){
		if(nums[j] <= pivot){
			swap(nums, i, j);
			i++;
		}
	}
	
	swap(nums, i, high);
	return i;
}

void quicksort(int nums[], int low, int high){
	if(low < high){
		int pivot = quicksortPartition(nums, low, high);
		quicksort(nums, low, pivot-1);
		quicksort(nums, pivot+1, high);
	}
	
}

int main(){
	
    int sizearray, a;

    printf("What is the size of your array?");
    scanf("%d", &sizearray); 

    int nums[sizearray];

    printf("Enter %d elements\n", sizearray);
    for(a = 0; a < sizearray; a++)
        scanf("%d", &nums[a]);

	quicksort(nums, 0, sizearray-1);
	
	for(int i=0; i<sizearray; i++)
		printf("%d ", nums[i]);
	
	return 0;
}