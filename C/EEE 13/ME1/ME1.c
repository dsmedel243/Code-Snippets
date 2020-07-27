//Danica Medel
//2016-01028

#include <stdio.h>
#include "quicksort.h"

int main(){
	
    int sizearray, a;

    printf("What is the size of your array?");
    scanf("%d", &sizearray); 

    int nums[sizearray];

    printf("Enter %d elements: ", sizearray);
    for(a = 0; a < sizearray; a++)
        scanf("%d", &nums[a]);

	quicksort(nums, 0, sizearray-1);
	
    printf("Sorted: ");
	for(int i=0; i<sizearray; i++)
		printf("%d ", nums[i]);

    printf("\n");
	
	return 0;
}
