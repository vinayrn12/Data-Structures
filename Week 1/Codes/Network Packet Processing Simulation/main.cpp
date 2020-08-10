#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct packet{
    long long  arrival;
    long long process;
};

int main()
{
    long long line_size, n;
    cin>>line_size;
    cin>>n;
    vector<packet> packets(n);
    for(long long i=0; i<n; i++)
        cin>>packets[i].arrival>>packets[i].process;
    deque<long long> finish_time;
    vector<long long> result(n);
    long long i;
    for(i=0; i<n; i++){
        while((! finish_time.empty()) && finish_time.front() <= packets[i].arrival)
            finish_time.pop_front();

        if(finish_time.size() >= line_size){
            result[i]=-1;
        }
        else{
            if(finish_time.empty())
                result[i]=packets[i].arrival;
            else
                result[i]=max(packets[i].arrival, finish_time.back());
        }

        finish_time.push_back(result[i]+packets[i].process);

    }

    if(result.empty())
        cout<<" ";
    else
        for(size_t i=0 ; i<result.size(); i++){
            cout<<result[i]<<endl;
        }

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct packet{
    long long  arrival;
    long long process;
};

int main()
{
    long long line_size, n;
    cin>>line_size;
    cin>>n;
    vector<packet> packets(n);
    for(long long i=0; i<n; i++)
        cin>>packets[i].arrival>>packets[i].process;
    deque<long long> finish_time;
    vector<long long> result(n);
    long long i;
    for(i=0; i<n; i++){
        while((! finish_time.empty()) && finish_time.front() < packets[i].arrival)
            finish_time.pop_front();

        if(finish_time.size() >= line_size)
            result[i]=-1;
        else{
            if(finish_time.empty())
                result[i]=packets[i].arrival;
            else
                result[i]=max(packets[i].arrival, finish_time.back());
        }
        finish_time.push_back(result[i]+packets[i].process);
    }



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

    for(size_t j=0 ; j<result.size(); j++){
        cout<<result[j]<<endl;
    }

    return 0;
}*/

