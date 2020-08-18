#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<long long> p1(200005, 0);
vector<vector<int>> h(2);
long long p=1000000009, x=3;

void precompute_hashes(string str, int n){
    p1[0] = 1;

    //Power vector
    for(int i=1; i<str.length(); i++)
        p1[i] = (p1[i-1] * x) % p;

    h[n].emplace_back(0);
    long long hash1 = 0;
    for(int i=0; i<str.length(); i++){
        hash1 = (hash1 + (str[i]*p1[i])) % p;
        h[n].emplace_back(hash1);
    }
}

pair<int, int> check(int m, string str1, string str2){
    map<long long, int> mp;
    for(int i=m; i<=(str1.length()); i++)
        mp[(((h[0][i]-h[0][i-m]+m)*p1[m-i])%m)] = i-m;
    for(int i=m; i<=(str2.length()); i++){
        long long t = (((h[1][i]-h[1][i-m]+m)*p1[m-i])%m);
        if(mp.find(t) != mp.end())
            return {mp[t], i-m};
    }
    return {-1, -1};
}

int main()
{
    string str1{""}, str2{""};
    while(cin>>str1>>str2){
        h[0].clear();
        h[1].clear();
        precompute_hashes(str1, 0);
        precompute_hashes(str2, 1);
        int l=0, r=min(str1.length(), str2.length());
        int mid, res;
        pair<int, int> pos{0, 0};
        while(l <= r){
            mid=(l+r)/2;
            pair<int, int> tmp = check(mid, str1, str2);
            if(tmp.first != -1){
                res = mid;
                pos = tmp;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        cout<<pos.first<<" "<<pos.second<<" "<<res<<endl;
    }
    return 0;
}
