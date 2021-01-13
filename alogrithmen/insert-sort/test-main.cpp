// #include "bubble.cpp"
#include "insert-sort.cpp"
#include <iostream>

int main(int argc, char *argv[])
{
  int A[] = {
    8,5,1,9,7,3,2
  };
  // std::cout << "bubble: \n";
  // bubble(A);
  // for (int i = 0; i < sizeof(A)/sizeof(int); ++i) {
  //   std::cout<<A[i]<<'\n';
  // }
  std::cout << "insert-sort: \n";
  insertSort(A);
  for (int i = 0; i < sizeof(A)/sizeof(int); ++i) {
    std::cout<<A[i]<<'\n';
  }
  return 0;
}

