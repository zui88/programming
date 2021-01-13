// helper functions
void swap (int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int parent(int i) {
  return (i-1) / 2;
}

int left(int i) {
  return 2*i + 1;
}

int right(int i) {
  return 2*i + 2;
}

void maxHeapify(int A[], int size, int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (l < size && A[l] > A[i])
    largest = l;
  if (r < size && A[r] > A[largest])
    largest = r;
  if (largest != i) {
    swap (&A[i], &A[largest]);
    maxHeapify(A, size, largest);
  }
}

// Laufzeit: O(lg(n)*n), engere Eingrenzung: O(n)
void buildMaxHeap (int A[], int size) {
  int i;
  for (i = parent(size-1); i >= 0; --i) {
    maxHeapify(A, size, i);
  }
}

void heapSort (int A[], int size) {
  buildMaxHeap (A, size);
  int i;
  for (i = size-1; i > 0 ; --i) {
    swap(&A[0], &A[i]);
    maxHeapify(A, i, 0);
  }
}
