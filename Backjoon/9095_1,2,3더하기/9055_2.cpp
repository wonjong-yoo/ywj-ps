#include <cstdio>
 
int main(void){
    int testcase;
    scanf("%d", &testcase);
    while (testcase--){
        int Dp[15] = {};
        Dp[0] = 1;
        int K;
        scanf("%d", &K);
 
        for (int i = 1; i <= K; i++){
                
            if (i-1>=0)
                Dp[i] += Dp[i - 1];
            if (i - 2 >= 0)
                Dp[i] += Dp[i - 2];
            if (i - 3 >= 0)
                Dp[i] += Dp[i - 3];
        }
 
        printf("%d\n", Dp[K]);
 
    }


}
