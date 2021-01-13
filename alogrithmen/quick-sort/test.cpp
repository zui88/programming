#include <stdio.h>
#include "quick-sort.hpp"

int main(int argc, char *argv[])
{
  int A[] = {
    4, 23, 42, 55
  };
  int N = sizeof(A)/sizeof(int), i;
  quickSort(A, 0, N-1);
  for (i = 0; i < N; ++i) {
    printf("%d\n",A[i]);
  }
  return 0;
}
