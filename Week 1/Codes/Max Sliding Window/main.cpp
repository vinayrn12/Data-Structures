#include <iostream>
#include <vector>
#include <limits>
#include <deque>

using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<int> packets;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        packets.push_back(temp);
    }
    int m;
    cin>>m;
    deque<int> window;

    int i;
    for(i=0; i<m; i++){
        while((! window.empty()) && packets[i] >= packets[window.back()])
            window.pop_back();
        window.push_back(i);
    }

    for( ; i<n; i++){
        cout<<packets[window.front()]<<" ";

        while((! window.empty()) && window.front() <= i-m)
            window.pop_front();

        while((! window.empty()) && packets[i] >= packets[window.back()])
            window.pop_back();
        window.push_back(i);
    }

    cout<<packets[window.front()];

    return 0;
}
