#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Brackets{

    Brackets(char type, int pos)
    :type{type}, pos{pos}{}

    char type;
    int pos;
};

int error(stack<char> braces){
    int c=0;
    while(! braces.empty()){
        c++;
        braces.pop();
    }
    return c;
}

 bool check(char type, Brackets b){
    char top = b.type;
    if(type==')' && top=='(')
        return true;
    else if(type=='}' && top=='{')
        return true;
    else if(type==']' && top=='[')
        return true;
    return false;
}

int main(){
    string code;
    getline(cin, code);
    stack<Brackets> braces;
    for(size_t i=0; i<code.size(); i++){
        if(code[i]=='(' || code[i]=='{' || code[i]=='[')
            braces.push(Brackets(code[i], i+1));
        if(code[i]==')' || code[i]=='}' || code[i]==']'){
            if(braces.empty()){
                cout<<i+1;
                exit(0);
            }
            else{
                if(check(code[i], braces.top()))
                    braces.pop();
                else{
                    cout<<i+1;
                    exit(0);
                }
            }
        }
    }
    if(braces.empty())
        cout<<"Success";
    else{
        Brackets top=braces.top();
        cout<<top.pos;
    }
    return 0;
}
