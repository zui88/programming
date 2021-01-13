#include <utility> // std::move
#include <stdlib.h>

// destructable move
template<class T, class P> void swap(T &t, P &p) {
  T tmp = std::move(t);
  t = std::move(p);
  p = std::move(tmp);
}

template <class T>
int partition(T A[], int l, int r) {
  int x = A[r];
  int i = l-1;
  for (int j = l; j < r; ++j) {
    if (A[j] <= x) {
      ++i;
      swap(A[i], A[j]);
    }
  }
  swap(A[i+1], A[r]);
  return i+1;
}

template <class T>
void quickSort(T A[], int l, int r) {
  if (l < r) {
    int q = partition(A, l, r);
    quickSort(A, l, q-1);
    quickSort(A, q+1, r);
  }
}
