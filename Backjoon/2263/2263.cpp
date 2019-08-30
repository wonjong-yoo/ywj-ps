#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

// [ ]
void findRootAndDivide(vector<int>& inorder, vector<int>& postorder, int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
  //printf("(%d, %d), (%d, %d)\n", inorderLeft, inorderRight, postorderLeft, postorderRight);
  
  if(inorderLeft > inorderRight) return;
  if(postorderLeft > postorderRight) return;

  int root = postorder[postorderRight];
  printf("%d ", root);
  
  //inorder에서 Root의 위치를 구한다.
  int rootIndexInorder = -1;
  for(int i = inorderLeft; i <= inorderRight; i++) {
    if(inorder[i] == root) {
      rootIndexInorder = i;
      break;
    }
  }
  
  // if(abs(postorderRight - postorderLeft) == 1) {
  //   printf("%d ", postorder[postorderRight - 1]);
  //   return;
  // }
  
  int left = rootIndexInorder - inorderLeft;

  findRootAndDivide(inorder, postorder, inorderLeft, rootIndexInorder - 1, postorderLeft, postorderLeft + left - 1);
  findRootAndDivide(inorder, postorder, rootIndexInorder + 1, inorderRight, postorderLeft + left, postorderRight - 1);

}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> inorder(n);
  vector<int> postorder(n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &inorder[i]);
  }

  for(int i = 0; i < n; i++) {
    scanf("%d", &postorder[i]);
  }

  findRootAndDivide(inorder, postorder, 0, n - 1, 0, n - 1);

}