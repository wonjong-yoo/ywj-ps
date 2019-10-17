#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[4001];
int b[4001];
int c[4001];
int d[4001];

int main() {
  int N;
  scanf("%d", &N);


  for(int i = 0; i < N; i++) {
    scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
  }

  vector<int> abSum;
  vector<int> cdSum;
  
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      abSum.push_back(a[i] + b[j]);
      cdSum.push_back(c[i] + d[j]);
    }
  }
  sort(cdSum.begin(), cdSum.end());
  long long ans = 0;

  for(int iter : abSum) {
    auto e = equal_range(cdSum.begin(), cdSum.end(), -iter);
    ans += e.second - e.first;
  }

  printf("%lld\n", ans);

}