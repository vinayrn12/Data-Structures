#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree{
private:
    int n;
    vector<int> key;
    vector<int> left;
    vector<int> right;

public:
    void get_data(){
        cin>>n;
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for(int i=0; i<n; i++)
            cin>>key[i]>>left[i]>>right[i];
    }

    void inorder(int ind){
        if(ind != -1){
            int l = left[ind];
            int r = right[ind];
            inorder(l);
            cout<<key[ind]<<" ";
            inorder(r);
        }
    }

    void preorder(int ind){
        if(ind != -1){
            int l = left[ind];
            int r = right[ind];
            cout<<key[ind]<<" ";
            preorder(l);
            preorder(r);
        }
    }

    void postorder(int ind){
        if(ind != -1){
            int l = left[ind];
            int r = right[ind];
            postorder(l);
            postorder(r);
            cout<<key[ind]<<" ";
        }
    }
};

int main()
{
    Tree t;
    t.get_data();
    t.inorder(0);
    cout<<endl;
    t.preorder(0);
    cout<<endl;
    t.postorder(0);
    cout<<endl;
    return 0;
}
