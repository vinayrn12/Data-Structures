#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

int m = 10000000;
vector<string> hash_book(m, "");

void add_number(long long number, string name){
    hash_book[number] = name;
}

void del_number(long long number){
    hash_book[number] = "";
}

void find_number(long long number){
    string result = hash_book[number];
    if(result == "")
        cout<<"not found"<<endl;
    else
        cout<<result<<endl;
}

int main()
{
    int n;
    cin>>n;
    cin>>ws;
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
                if(instructions[i][k] == ' ')
                    break;
                number+=instructions[i][k];
            }
            ++k;
            for(; k<instructions[i].length(); k++){
                name+=instructions[i][k];
            }
            add_number(stoll(number), name);
        }
        else if(op == "find"){
           size_t k=5;
            for(; k<instructions[i].length(); k++){
                number+=instructions[i][k];
            }
            find_number(stoll(number));
        }
        else if(op == "del"){
            size_t k=4;
            for(; k<instructions[i].length(); k++){
                number+=instructions[i][k];
            }
            del_number(stoll(number));
        }
    }
    return 0;
}
