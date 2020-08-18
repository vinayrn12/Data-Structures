#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

size_t p = 1000000007, x = 263;
vector<vector<string>> hash_book;

long long hash_function(string s, int m) {
	long long hash = 0;
    for (int i = s.length() - 1; i >= 0; --i)
        hash = (hash * x + (int)s[i]) % p;
    return (hash % m);
}

void add_name(string name, int m){
   size_t hash_index = hash_function(name, m);
   auto it = find(begin(hash_book[hash_index]), end(hash_book[hash_index]), name);
   if(it == end(hash_book[hash_index]))
      hash_book[hash_index].push_back(name);
}

void del_name(string name, int m){
   size_t hash_index = hash_function(name, m);
   auto it = find(begin(hash_book[hash_index]), end(hash_book[hash_index]), name);
   if(it != end(hash_book[hash_index]))
        hash_book[hash_index].erase(it);
}

void find_name(string name, int m){
   size_t hash_index = hash_function(name, m);
   auto it = find(begin(hash_book[hash_index]), end(hash_book[hash_index]), name);
   if(it != end(hash_book[hash_index]))
        cout<<"yes"<<endl;
   else
        cout<<"no"<<endl;
}

void check_list(long long number, int m){
   auto it = hash_book[number].rbegin();
   while(it != hash_book[number].rend()){
        cout<<*it<<" ";
        it++;
   }
   cout<<endl;
}

int main()
{
    int n, m;
    cin>>m>>n;
    cin>>ws;
    hash_book.resize(m);
    vector<string> instructions(n);
    for(int i=0; i<n; i++)
        getline(cin, instructions[i]);
    for(size_t i=0; i<instructions.size(); i++){
        string op{""}, number{""}, name{""};
        size_t j = 0;
        for(; j<instructions[i].length(); j++){
            if(instructions[i][j] == ' ')
                break;
            op+=instructions[i][j];
        }
        if(op == "add"){
            size_t k=4;
            for(; k<instructions[i].length(); k++){
                name+=instructions[i][k];
            }
            add_name(name, m);
        }
        else if(op == "find"){
           size_t k=5;
            for(; k<instructions[i].length(); k++){
                name+=instructions[i][k];
            }
            find_name(name, m);
        }
        else if(op == "check"){
           size_t k=6;
            for(; k<instructions[i].length(); k++){
                number+=instructions[i][k];
            }
            check_list(stoll(number), m);
        }
        else if(op == "del"){
            size_t k=4;
            for(; k<instructions[i].length(); k++){
                name+=instructions[i][k];
            }
            del_name(name, m);
        }
    }
    return 0;
}
