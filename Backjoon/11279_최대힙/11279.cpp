#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int heap[100001];

void printHeap(int heapMax) {
  printf("heap is : ");
  for(int i = 0; i < heapMax; i++) {
    printf("%d ", heap[i]);
  }
  printf("\n");
}

void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insertElement(int a, int heapMax) {
  heap[heapMax] = a;
  int previousIndex = heapMax;
  for(int i = std::ceil((double)heapMax / 2) - 1; i >= 0; i = std::ceil((double)i / 2) - 1) {
    //printf("prev : %d, now : %d\n", previousIndex, i);
    if(heap[previousIndex] > heap[i]) {
      int temp = heap[i];
      heap[i] = heap[previousIndex];
      heap[previousIndex] = temp;
    }
    previousIndex = i;
  }
}

void deleteElement(int& heapMax) {
  if(heapMax == 0) {
    printf("0\n");
    return;
  }
  printf("%d\n", heap[0]);
  heap[0] = heap[heapMax - 1];
  heapMax--;

  for(int i = 0; i <= heapMax; ) {
    // 만약 다다음 원소가 없다면 아래꺼만 비교
    if((i * 2) + 2 >= heapMax) {
      if(heap[(i * 2) + 1] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i * 2) + 1];
        heap[(i * 2) + 1] = temp;
        break;
      }
      else break;
    } else {
      int nextIndex = (i * 2) + 1;
      int nextNextIndex = (i * 2) + 2;
      
      if(heap[i] < heap[nextIndex] || heap[i] < heap[nextNextIndex]) {
        if(heap[nextIndex] > heap[nextNextIndex]) {
          swap(nextIndex, i);
          i = nextIndex;
        } else {
          swap(nextNextIndex, i);
          i = nextNextIndex;
        }
      } else {
        break;
      }
    }
  }
}

int main() {
  int N;
  scanf("%d", &N);
  int heapMax = 0;
  int a;
  for(int i = 0; i < N; i++) {
    
    scanf("%d", &a);
    if(a != 0) {
      insertElement(a, heapMax);
      heapMax++;
    } else if(a == 0) {
      deleteElement(heapMax);
      
    }
    printHeap(heapMax);
  }
}