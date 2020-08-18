//Another approach
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int c=1;

struct Node {
  long key;
  long left;
  long right;

  Node() : key(0), left(-1), right(-1) {}
  Node(long key_, long left_, long right_) : key(key_), left(left_), right(right_) {}
};

void inorder(const vector<Node>& tree, long ind, long prev, long min_val, long max_val){
    if(ind == 0 && prev == 0){
        inorder(tree, tree[ind].left, ind, min_val, tree[ind].key-1);
        inorder(tree, tree[ind].right, ind, tree[ind].key, max_val);
    }
    if(ind > 0){
        inorder(tree, tree[ind].left, ind, min_val, (tree[ind].key-1));
        //if(tree[ind].key == tree[tree[prev].left].key){
            if(tree[ind].key >= min_val && tree[ind].key <= max_val){}
            else{
                c=0;
                return;
            }
        inorder(tree, tree[ind].right, ind, tree[ind].key, max_val);
    }
    return;
}

bool IsBinarySearchTree(const vector<Node>& tree, long min_val, long max_val) {
  // Implement correct algorithm here
  if(tree.size() < 2)
    return true;
  inorder(tree, 0, 0, min_val, max_val);
  if(c == 1)
    return true;
  return false;
}

int main() {
  long nodes, min_val = (-2147483647 - 1), max_val = 2147483647;
  cin >> nodes;
  vector<Node> tree;
  for (long i = 0; i < nodes; ++i) {
    long key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree, min_val, max_val)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
