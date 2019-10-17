#include <iostream>
#include <vector>
#include <algorithm>

#define x first
#define y second
using namespace std;

typedef pair<int, int> p;

int dep[40404];
int chk[40404];
int dist[40404];
int dp[40404][20];
vector<p> g[40404];
int n;

void dfs(int now, int d, int c){
	chk[now] = 1;
	dep[now] = d;
	dist[now] = c;
	for(auto i : g[now]){
		int nxt = i.x;
		int cst = i.y;
		if(chk[nxt]) continue;
		dp[nxt][0] = now;
		dfs(nxt, d+1, c+cst);
	}
}

int lca(int u, int v){
	if(dep[u] > dep[v]) swap(u, v);
	int diff = dep[v] - dep[u];
	for(int i=0; diff; i++){
		if(diff & 1) v = dp[v][i];
		diff >>= 1;
	}
	if(u == v) return u;
	for(int i=19; i>=0; i--){
		if(dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	dep[1] = 1, dp[1][0] = 0; chk[1] = 1; dist[1] = 0;
	for(int i=0; i<n-1; i++){
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	dfs(1, 0, 0);
	for(int j=1; j<20; j++){
		for(int i=1; i<=n; i++){
			dp[i][j] = dp[dp[i][j-1]][j-1];
		}
	}

	int m; cin >> m;
	while(m--){
		int a, b; cin >> a >> b;
		int aa = dist[a], bb = dist[b];
		int c = lca(a, b);
		//cout << c << " ";
		int cc = dist[c];
		int res = aa + bb - 2*cc;
		//cout << aa << " " << bb << " " << cc << " ";
		cout << res << "\n";
	}
}