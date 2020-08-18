#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long x1=2, x2=3, p1=1000000009, p2=1000000007;
vector<long long> h1, h2, pow1, pow2;

struct in{
    int s1;
    int s2;
    int length;
};

void compute_hashes(string str){
    h1[0] = 0;
    h2[0] = 0;
    pow1[0] = 1;
    pow2[0] = 1;
    int n = str.length();
    for(int i=1; i<n; i++){
        pow1[i] = (pow1[i-1]*x1) % p1;
        pow2[i] = (pow2[i-1]*x2) % p2;
    }
    for(int i=0; i<n; i++){
        h1[i+1] = (h1[i] + pow1[i]*str[i]) % p1;
        h2[i+1] = (h2[i] + pow2[i]*str[i]) % p2;
    }
}

void compute_diff(int a, int b, int l, int textsize){
    int diff1 = (h1[a+l]+p1 - h1[a]+p1)%p1;
    int diff2 = (h1[b+l]+p1 - h1[b]+p1)%p1;
    diff1 = (diff1 * pow1[b]) % p1;
    diff2 = (diff2 * pow1[a]) % p1;
    if(diff1 != diff2){
        cout<<"No"<<endl;
        return;
    }
    diff1 = (h2[a+l]+p2 - h2[a]+p2)%p2;
    diff2 = (h2[b+l]+p2 - h2[b]+p2)%p2;
    diff1 = (diff1 * pow2[b]) % p2;
    diff2 = (diff2 * pow2[a]) % p2;
    if(diff1 != diff2){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
}

int main()
{
    int n;
    string str;
    getline(cin, str);
    cin>>n;
    vector<in> queries(n);
    for(int i=0; i<n; i++)
        cin>>queries[i].s1>>queries[i].s2>>queries[i].length;
    h1.resize(str.length()+1);
    h2.resize(str.length()+1);
    pow1.resize(str.length());
    pow2.resize(str.length());
    compute_hashes(str);
    for(size_t i=0; i<queries.size(); i++){
        compute_diff(queries[i].s1, queries[i].s2, queries[i].length, str.length());
    }
    return 0;
}

