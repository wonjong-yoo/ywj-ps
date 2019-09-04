#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int add(int targetSet, int x) {
  return targetSet | (1 << x);
}

int remove(int targetSet, int x) {
  return targetSet & ~(1 << x);
}

bool check(int targetSet, int x) {
  return targetSet & (1 << x);
}

int toggle(int targetSet, int x) {
  return targetSet ^ (1 << x);
}

int all(int targetSet, int x = 20) {
  return targetSet | (1 << x) - 1;
}

int empty(int targetSet) {
  return 0;
}

int main() {
  int M;
  scanf("%d", &M);
  int set = 0;
  for(int i = 0; i < M; i++) {
    char order[10];
    int x;
    scanf("%s %d", order, &x);
    x--;
    if(!strcmp(order, "add")) {
      set = add(set, x);
    } else if(!strcmp(order, "remove")) {
      set = remove(set, x);
    } else if(!strcmp(order, "check")) {
      printf("%d\n", check(set, x));
    } else if(!strcmp(order, "toggle")) {
      set = toggle(set, x);
    } else if(!strcmp(order, "all")) {
      set = all(set);
    } else if(!strcmp(order, "empty")) {
      set = empty(set);
    }
  }
}