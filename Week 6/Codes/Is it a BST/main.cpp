#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tree{
private:
    long long n, c = 1;
    vector<long long> key;
    vector<long long> left;
    vector<long long> right;
public:
    void get_data(){
        cin>>n;
        if(n == 0){
            cout<<"CORRECT";
            exit(0);
        }
        key.resize(n);
        left.resize(n);
        right.resize(n);
        for(long long i=0; i<n; i++)
            cin>>key[i]>>left[i]>>right[i];
    }

    long long get_c(){
        return c;
    }

    void inorder(long long ind, long long min_val, long long max_val){
        if(ind != -1){
            long long l = left[ind];
            long long r = right[ind];
            inorder(l, min_val, key[ind]);
            if(key[ind] > min_val && key[ind] < max_val){}
            else{
                c=0;
                return;
            }
            inorder(r, key[ind], max_val);
        }
    }
};

int main()
{
    Tree t;
    long long min_val = (-2147483647 - 1), max_val = 2147483647;
    t.get_data();
    t.inorder(0, min_val, max_val);
    if(t.get_c() == 0)
        cout<<"INCORRECT";
    else
        cout<<"CORRECT";
    return 0;
}
