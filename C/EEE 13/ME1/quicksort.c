#include <stdio.h>

void swap(int nums[], int i, int j)
{
	int temp = nums[j];
	nums[j] = nums[i];
	nums[i] = temp;
}

int quicksortPartition(int nums[], int low, int high)
{
	int pivot = nums[high];
	int i = low;
	
	for(int j = low; j < high; j++)
    {
		if(nums[j] <= pivot)
        {
			swap(nums, i, j);
			i++;
		}
	}

	swap(nums, i, high);
	return i;
}

void quicksort(int nums[], int low, int high)
{
	if(low < high)
    {
		int pivot = quicksortPartition(nums, low, high);
		quicksort(nums, low, pivot-1);
		quicksort(nums, pivot+1, high);
	}	
}