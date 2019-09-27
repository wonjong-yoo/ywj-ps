#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// int dp[501][501];
int dp2[501][501];
int sum[502];
int paper[501];
int main() {
  

  // memset(array, 0, sizeof(array[0][0]) * m * n);
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    memset(paper, 0, sizeof(int) * 501);
    // memset(dp, 0, sizeof(int) * 501 * 501);
    memset(dp2, 0, sizeof(int) * 501 * 501);
    int K;
    cin >> K;
    for(int i = 0; i < K; i++) {
      cin >> paper[i];
      //dp2[i][i] = paper[i];
      sum[i + 1] = sum[i] + paper[i];
    }
    // 첫번쨰 부터 시작
    for(int i = 0; i < K - 1; i++) {
      // dp[i][i + 1] = paper[i] + paper[i + 1];
      dp2[i][i + 1] = paper[i] + paper[i + 1];
    }
    int answer = 0;
    // for(int size = 2; size <= K; size++) {
    //   for(int i = 0; i < K - size; i++) {
    //     dp[i][i + size] = min(dp[i][i + size - 1] + paper[i + size], dp[i + 1][i + size] + paper[i]);

    //     //선택할 개수
    //     // for(int k = 1; k <= std::ceil((double)size / 2); k++) {
    //     //   dp[i][i + size] = min(dp[i][i + size], dp[i][i + k] + dp[i + k + 1][i + size]);
    //     // }
    //     cout << i << " ~ " << i + size << " : " << dp[i][i + size] << endl;
    //   }
    // }

    for(int size = 1; size < K; size++) {
      for(int i = 0; i <= K - size; i++) {
        // cout << "A : " << dp[i][i + size - 1] + dp2[i][i + size - 1] + paper[i + size] << endl;
        // cout << "B : " << dp[i + 1][i + size] + dp2[i + 1][i + size] + paper[i] << endl;
        // dp2[i][i + size] = min(dp[i][i + size - 1] + dp2[i][i + size - 1] + paper[i + size], dp[i + 1][i + size] + dp2[i + 1][i + size] + paper[i]);

        dp2[i][i + size] = 987654321;
        // for(int k = 0; k < size; k++) {
        //   cout << "C " << i + k << " :"  << dp2[i][i + k] + dp2[i + k + 1][i + size] << endl;
        //   dp2[i][i + size] = min(dp2[i][i + size], dp2[i][i + k] + dp2[i + k + 1][i + size]);
        // }
        for(int mid = i; mid <= i + size; ++mid) {
          dp2[i][i + size] = min(dp2[i][i + size], dp2[i][mid] + dp2[mid + 1][i + size]);
        }
        dp2[i][i + size] = sum[i + size] - sum[i];
        cout << "=>" <<  i << " ~ " << i + size << " : " << dp2[i][i + size] << endl;
      }
    }
    

    cout << dp2[0][K-1] << "\n";
  }
}