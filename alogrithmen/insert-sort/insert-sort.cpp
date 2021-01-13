#include <utility> // std::move, std::size_t

template<typename T, std::size_t N> 
void insertSort(T (&A)[N]) {
  for (int i = 1; i < N; ++i) {
    T key = A[i];
    int j = i-1;
    while (j >= 0 && A[j] > key) {
      // ein feld nach rechts rutschen, wenn key kleiner ist als j -> "platz schaffen"
      A[j+1] = A[j];
      --j;
    }
    A[++j] = key;
  }
}
