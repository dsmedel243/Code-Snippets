#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

void swap(int nums[], int i, int j);
int quicksortPartition(int nums[], int low, int high);
void quicksort(int nums[], int low, int high);

#endif /* __QUICKSORT_H__ */