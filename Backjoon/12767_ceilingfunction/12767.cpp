#include <iostream>
#include <queue>
#include <utility>
#include <set>

using namespace std;

class Item {
  public:
    int num;
    Item* left;
    Item* right;
    Item(int num) {
      this->num = num;
      left = nullptr;
      right = nullptr;
    }
};

class BinarySearchTree {
  private:
    Item* root;
  public:
    BinarySearchTree() {
      root = nullptr;
    }
    void insert(int a) {
      if(root == nullptr) {
        root = new Item(a);
        return;
      }
      Item* now = root;
      while(now != nullptr) {
        if(now->num > a) {
          if(now->left == nullptr) {
            now->left = new Item(a);
            break;
          }
          now = now->left;
        } else {
          if(now->right == nullptr) {
            now->right = new Item(a);
            break;
          }
          now = now->right;
        }
      }
      now = new Item(a);
    }

    string toString() {
      string s;
      Item* now = root;
      queue<pair<Item*, int>> q;
      q.push({now, 1});
      while(!q.empty()) {
        Item* now = q.front().first;
        int index = q.front().second;
        q.pop();
        for(int i = s.length(); i < index - 1; i++) {
          s += "0";
        }
        s += "1";

        if(now->left != nullptr) {
          q.push({now->left, 2 * index});
        }
        if(now->right != nullptr) {
          q.push({now->right, 2 * index + 1});
        }
      }
      return s;
    }

};

int main() {
  int n, k;
  cin >> n >> k;
  set<string> answerSet;
  for(int i = 0; i < n; i++) {
    BinarySearchTree bst;
    for(int j = 0; j < k; j++) {
      int a;
      cin >> a;
      bst.insert(a);
    }
    string s = bst.toString();
    answerSet.insert(s);
  }
  cout << answerSet.size() << endl;
}