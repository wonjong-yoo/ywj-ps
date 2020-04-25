#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long makeTree(int start, int end, int node, vector<long long>&input, vector<long long>& segmentTree) {
  if(start == end) {
    segmentTree[node] = input[start];
    return input[start];
  }
  
  int mid = (start + end) / 2;
  long long left = makeTree(start, mid, node * 2 + 1, input, segmentTree);
  long long right = makeTree(mid + 1, end, node * 2 + 2, input, segmentTree);


  segmentTree[node] = left + right;
  return left + right;
}

long long searchTree(int i, int j, int start, int end, int node, vector<long long>&input, vector<long long>& segmentTree) {
  if(end < i ||start > j) return 0;
  if(start >= i && end <= j) return segmentTree[node];

  int mid = (start + end) / 2;
  long long left = searchTree(i, j, start, mid, node * 2 + 1, input, segmentTree);
  long long right = searchTree(i, j, mid + 1, end, node * 2 + 2, input, segmentTree);
  // cout << "start : " << start << ", end : " << end << endl;
  // cout << "node INdex : " << node << "sum : " << left + right << endl;
  return left + right;
}

void printVector(vector<long long>& v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

long long dfs(long long newItem, int findNodeIndex, int start, int end, int nodeIndex, vector<long long>& segmentTree) {
  if(start == end && start == findNodeIndex) {
    long long diff = newItem - segmentTree[nodeIndex];
    segmentTree[nodeIndex] = newItem;
    return diff;
  } else if(start == end) return 0;

  int mid = (start + end) / 2;
  long long r;
  if(findNodeIndex >= start && findNodeIndex <= mid) {
    r = dfs(newItem, findNodeIndex, start, mid, nodeIndex * 2 + 1, segmentTree);
  } else {
    r = dfs(newItem, findNodeIndex, mid + 1, end, nodeIndex * 2 + 2, segmentTree);
  }

  segmentTree[nodeIndex] += r;
  return r;
}

int main() {
  cin.tie(NULL);
  cin.sync_with_stdio(false);
  int N, M, K;
  cin >> N >> M >> K;

  vector<long long> input(N);
  vector<long long> segmentTree(4 * N, -1);

  for(int i = 0; i < N; i++) {
    cin >> input[i];
  }

  // 세그먼트 트리를 만든다.
  makeTree(0, N - 1, 0, input, segmentTree);


  //printVector(segmentTree);

  for(int q = 0; q < M + K; q++) {

    long long A, B, C;
    cin >> A >> B >> C;

    if(A == 1) {
      dfs(C, B - 1, 0, N - 1, 0, segmentTree);
      //printVector(segmentTree);
    } else if(A == 2) {
      cout << searchTree(B - 1, C - 1, 0, N - 1, 0, input, segmentTree) << "\n";
    }
  }
}