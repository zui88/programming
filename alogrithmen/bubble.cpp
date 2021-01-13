#include <utility> // std::move

// destructable move
template<class T, class P> void swap(T &t, P &p) {
  T tmp = std::move(t);
  t = std::move(p);
  p = std::move(tmp);
}

// O(n^2)
// reference to an arry with compilerdeduction of members
template<class T, std::size_t N> void bubble(T (&A)[N]) {
  for (int i = N-1; i > 0; --i) {
    for (int j = 1; j <= i; ++j) {
      if (A[j-1] > A[j]) {
	swap(A[j-1], A[j]);
      }
    }
  }
}
