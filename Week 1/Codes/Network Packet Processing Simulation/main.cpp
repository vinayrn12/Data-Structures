#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct packet{
    int arrival;
    int process;
};

int main()
{
    int line_size, n;
    cin>>line_size;
    cin>>n;
    vector<packet> packets(n);
    for(int i=0; i<n; i++)
        cin>>packets[i].arrival>>packets[i].process;
    deque<int> finish_time;
    vector<int> result;
    int i;
    for(i=0; i<line_size; i++){
        if(i < n){
            if(i>0){
                result.push_back(max(result[i-1]+packets[i].arrival, finish_time.back()));
                finish_time.push_back(finish_time.back()+packets[i].process);
            }
            else{
                finish_time.push_back(packets[i].arrival+packets[i].process);
                result.push_back(packets[i].arrival);
            }

        }
    }

    for( ; i<n; i++){
        while((! finish_time.empty()) && finish_time.front() <= packets[i].arrival)
            finish_time.pop_front();

        if(finish_time.empty()){
            result.push_back(packets[i].arrival);
            finish_time.push_back(result[i]+packets[i].process);
        }
        else if(finish_time.size() < line_size && (! finish_time.empty())){
            result.push_back(finish_time.back());
            finish_time.push_back(finish_time.back()+packets[i].process);
        }
        else{
            result.push_back(-1);
        }
    }

    for(size_t j=0 ; j<result.size(); j++){
        cout<<result[j]<<endl;
    }

    return 0;
}
