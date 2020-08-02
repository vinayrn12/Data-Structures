#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node;

class Node {
public:
    int key;
    Node *parent;
    std::vector<Node *> children;

    Node() {
      this->parent = NULL;
    }

    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};

Node bfs(Node node, vector<Node> nodes){
    queue<Node> q;
    q.push(node);
    Node leaf;
    while(!q.empty()){
        leaf = q.front();
        q.pop();
        if(leaf.children.size()){
            for(size_t i=0; i<leaf.children.size(); i++)
                q.push(*(leaf.children[i]));
        }
    }
    return leaf;
}

int compute_height(Node* node){
    if(node->parent == NULL)
        return 1;
    else{
        return 1+compute_height(node->parent);
    }
}

int main() {
  int n;
  std::cin >> n;

  int root;
  std::vector<Node> nodes;
  nodes.resize(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    std::cin >> parent_index;
    if(parent_index == -1)
        root = child_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }

  Node leaf = bfs(nodes[root], nodes);
  int height = compute_height(&leaf);
  cout<<height;
  return 0;
}
