#include <stdio.h>
#include "heap.h"

int main(int argc, char *argv[])
{
  int A0[] = {
    16, 4, 10, 14, 7, 9, 3, 2, 8, 1
  };
  int A1[] = {
    5, 42, 88, 2353, 1, 3, 99
  };
  int i;
  int sizeArry0 = sizeof (A0) / sizeof (int);
  int sizeArry1 = sizeof (A1) / sizeof (int);
  printf("maxHeapify\n");
  maxHeapify(A0, sizeArry0, 1);
  for (i = 0; i < sizeArry0; ++i) {
    printf("%d ", A0[i]);
  }
  printf("\n"); 
  printf("buildMaxHeap\n");
  buildMaxHeap(A1, sizeArry1);
  for (i = 0; i < sizeArry1; ++i) {
    printf("%d ", A1[i]);
  }
  printf("\n"); 
  printf("heapSort\n");
  heapSort(A1, sizeArry1);
  for (i = 0; i < sizeArry1; ++i) {
    printf("%d ", A1[i]);
  }
  printf("\n");
  return 0;
}
