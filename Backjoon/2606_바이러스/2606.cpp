#include <cstdio>

int computer[101];

int Find(int i) {
  if(computer[i] == i) return i;
  else return computer[i] = Find(computer[i]);
}

void Union(int a, int b) {
  int aParent = Find(a);
  int bParent = Find(b);
  //printf("a : %d, b : %d\n", aParent, bParent);
  if(aParent != bParent) {
    if(aParent == 1) computer[bParent] = aParent;
    else if(bParent == 1) computer[aParent] = bParent;
    else computer[bParent] = aParent;
  }
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  
  for(int i = 1; i <= N; i++) {
    computer[i] = i;
  }

  for(int i = 0; i < M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    Union(a, b);
  }
  
  int answer = 0;
  for(int i = 2; i <= N; i++) {
    if(Find(i) == 1) answer++; 
  }


  printf("%d\n", answer);
}