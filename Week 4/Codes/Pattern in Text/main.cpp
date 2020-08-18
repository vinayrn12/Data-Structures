#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long p = 100000000007, x = 2, h1=0, h2=0;

long long polyhash(string pattern){
    long long hash_val = 0;
    for (int i = 0; i<pattern.length(); i++){
        hash_val = (hash_val * x) + pattern[i];
        hash_val %= p;
    }
    return (hash_val);
}

void rabin_carp(string text, string pattern){
    vector<int> result;
    h1 = polyhash(pattern);
    long long power = 1;
    for(size_t i=0; i<pattern.length(); i++)
        power = (power * x)%p;
    for(int i=0; i<text.length(); i++){
        h2 = (h2 * x) + text[i];
        h2 %= p;

        if(i >= pattern.length()){
            h2 = h2 - (power * text[i-pattern.length()]);
            h2 %= p;
            if(h2 < 0)
                h2 += p;
        }

        if(i >= pattern.length()-1 && h1 == h2)
            result.push_back(i-pattern.length()+1);
    }
    for(size_t i=0; i<result.size(); i++)
        cout<<result[i]<<" ";
}

int main()
{
    string pattern{""}, text{""};
    getline(cin, pattern);
    getline(cin, text);
    rabin_carp(text, pattern);
    return 0;
}
