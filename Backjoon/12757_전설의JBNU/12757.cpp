#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

using namespace std;

// pair<int, int> heap[200002];

// void printHeap(int heapMax) {
//   printf("heap is : ");
//   for(int i = 1; i < heapMax; i++) {
//     printf("%d ", heap[i].first);
//   }
//   printf("\n");
// }

// void swap(int i, int j) {
//     pair<int, int> temp = heap[i];
//     heap[i] = heap[j];
//     heap[j] = temp;
// }

// void insertElement(int a, int b, int& heapMax) {
//   heap[heapMax].first = a;
//   heap[heapMax].second = b;
//   heapMax++;
//   int i = heapMax - 1;
//   int parentIndex = i / 2;
//   while(i > 1 && heap[parentIndex] < heap[i]) {
//     swap(i, parentIndex);
//     i = parentIndex;
//     parentIndex = i / 2;
//   }
// }

// // Index를 리턴한다.
// int searchElement(int& heapMax, int key, int keyMax) {
//   if(heapMax == 0) return -1;
//   int count = 0;
//   int target;
//   int diff = -1;
//   stack<int> q;
//   q.push(1);
//   while(!q.empty()) {
//     int index = q.top();
//     q.pop();
//     if(heap[index].first <= key + keyMax && heap[index].first >= key - keyMax) {
//       //printf("HIT %d\n", index);  
//       if(diff == -1) {
//         count = 1;
//         target = index;
//         diff = abs(heap[index].first - key);
//       }
//       else if(heap[index].first - key == diff) {
//         count++;
//       }
//       else if(abs(heap[index].first - key) < diff) {
//         count = 1;
//         target = index;
//         diff = abs(heap[index].first - key);
//       } else {
//         continue;
//       }
//     }

//     if(index * 2 < heapMax) {
//       int childLeft = index * 2;
//       if(heap[childLeft].first >= key - keyMax) {
//         q.push(childLeft);
//       }
//     }

//     if(index * 2 + 1 < heapMax) {
//       int childRight = index * 2 + 1;
//       if(heap[childRight].first >= key - keyMax) {
//         q.push(childRight);
//       }
//     }
//   }
//   if(count == 0) return -1;
//   if(count >= 2) return -2;
//   if(count == 1) return target;
// }

// void deleteElement(int key, int keyMax, int& heapMax) {
//   int index = searchElement(heapMax, key, keyMax);
//   if(index == -1 || index == -2) return;
//   heap[index] = heap[--heapMax];
//   int child = index * 2;
// 	if (child + 1 <= heapMax) {
// 		child = (heap[child] > heap[child + 1]) ? child : child + 1;
// 	}

// 	while (child <= heapMax && heap[index] < heap[child]) {
// 		swap(index, child);
    
// 		index = child;
// 		child = child * 2;
// 		if (child + 1 <= heapMax) {
// 			child = (heap[child] > heap[child + 1]) ? child : child + 1;
// 		}
// 	}
// }

// int main() {
//   // int now = 1;
//   // for(int i = 0; i < 10; i++) {
//   //   insertElement(i + 1, 100, now);
//   //   printHeap(now);
//   // }

//   // for(int i = 1; i <=10; i++) {
//   //   deleteElement(i, 0, now);
//   //   printHeap(now);
//   // }

//   int N, M, K;
//   scanf("%d %d %d", &N, &M, &K);
  
//   int nowHeapSize = 1;
//   for(int i = 0; i < N; i++) {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     insertElement(a, b, nowHeapSize);
//   }
//   //printHeap(nowHeapSize);
//   for(int i = 0; i < M; i++) {
//     int command;
//     scanf("%d", &command);
//     if(command == 1) {
//       int a, b;
//       scanf("%d %d", &a, &b);
//       insertElement(a, b, nowHeapSize);
//     } else if(command == 2) {
//       int key, value;
//       scanf("%d %d", &key, &value);
//       int index = searchElement(nowHeapSize, key, K);
//       if(index == -1 || index == -2) continue;
//       heap[index].second = value;
//     } else if(command == 3) {
//       int key;
//       scanf("%d", &key);
//       int index = searchElement(nowHeapSize, key, K);
//       if(index == -1) printf("-1\n");
//       else if(index == -2) printf("?\n");
//       else {
//         printf("%d\n", heap[index].second);
//       }
//     }
//   }
// }

void setValue(map<int, int>& m, int key, int value, int k) {
  auto low = m.lower_bound(key); // 이상
  auto up = m.upper_bound(key); //초과
  auto end = m.end();
  //printf("%d %d\n", lower->first, upper->first);
  if(low != m.begin()) low--;
  if (m.find(key) != m.end()) m[key] = value;
	else {
		if ( ( low == end || low->first < key - k ) && ( up == end || key + k < up->first) ) return;
		else if( low == end  ){
			if (up->first < key + k) m[up->first] = value;
		}
		else if( up == end){
			if (low->first > key - k) m[low->first] = value;
		}
		else {
			if (low == up) m[low->first] = value;
			else if (abs(key - low->first) > abs(key - up->first)) m[up->first] = value;
			else if (abs(key - low->first) < abs(key - up->first)) m[low->first] = value;
		}
	}
  
}

void lookup(map<int, int>& m, int key, int k) {
  auto end = m.end();
	
	if (m.find(key) != m.end()) printf("%d\n", m[key]);
	else {
		auto low = m.lower_bound(key);
		auto up = m.upper_bound(key);
		low--;

		if ( ( low == end || low->first < key - k )  && ( up == end || key + k < up->first ) ) printf("-1\n");
		else if (low == end) {
			if (up->first < key + k) printf("%d\n", m[up->first]);
		}
		else if (up == end) {
			if (low->first > key - k) printf("%d\n", m[low->first]);
		}
		else {
			if (low == up) printf("%d\n", m[low->first]);
			else if (abs(key - low->first) > abs(key - up->first)) printf("%d\n", m[up->first]);
			else if (abs(key - low->first) < abs(key - up->first)) printf("%d\n", m[low->first]);
			else printf("?\n");
		}
	}
}


int main() {
  map<int, int> m;

  int N, M, K;
  scanf("%d %d %d", &N, &M, &K);
  
  for(int i = 0; i < N; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    m[a] = b;
  }
  //printHeap(nowHeapSize);
  for(int i = 0; i < M; i++) {
    int command;
    scanf("%d", &command);
    if(command == 1) {
      int a, b;
      scanf("%d %d", &a, &b);
      m[a] = b;
    } else if(command == 2) {
      int key, value;
      scanf("%d %d", &key, &value);
      setValue(m, key, value, K);
    } else if(command == 3) {
      int key;
      scanf("%d", &key);
      lookup(m, key, K);
    }
  }
}