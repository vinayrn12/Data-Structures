#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    stack<int> s;
    int n;
    int max_ele=-999999;
    cin>>n;
    cin>>ws;
    vector<string> instruction(n);
    for(int i=0; i<n; i++){
        getline(cin, instruction[i]);
    }
    for(size_t i=0; i<instruction.size(); i++){
        if(instruction[i][0]=='p' && instruction[i][1]=='u' && instruction[i][2]=='s' && instruction[i][3]=='h'){\
            string num{""};
            for(size_t j=5; j<instruction[i].size(); j++)
                num += instruction[i][j];
            int ele = stoi(num);
            if(s.empty()){
                s.push(ele);
                max_ele = ele;
            }
            else{
                if(ele > max_ele){
                    s.push((2*ele)-max_ele);
                    max_ele = ele;
                }
                else{
                    s.push(ele);
                }
            }
        }
        if(instruction[i][0]=='p' && instruction[i][1]=='o' && instruction[i][2]=='p'){
           int top = s.top();
           s.pop();
           if(top > max_ele){
                max_ele = (2*max_ele)-top;
           }
        }
        if(instruction[i][0]=='m' && instruction[i][1]=='a' && instruction[i][2]=='x')
            cout<<max_ele<<endl;
    }
    return 0;
}
