#include <iostream>
#include <vector>

using namespace std;

struct schedule{
    long long thread_num;
    long long task_time;
};

long long left_child(long long i){
    return ((2*i)+1);
}

long long right_child(long long i){
    return ((2*i)+2);
}

void siftdown(long long i, vector<schedule> &result){
    long long min_index = i;
    long long l = left_child(i);
    long long r = right_child(i);
    long long n = result.size();

    if(l<n){
        if(result[l].task_time < result[min_index].task_time)
            min_index = l;
        if(result[l].task_time == result[min_index].task_time){
            if(result[l].thread_num < result[min_index].thread_num)
                min_index = l;
        }
    }

    if(r<n){
        if(result[r].task_time < result[min_index].task_time)
            min_index = r;
        if(result[r].task_time == result[min_index].task_time){
            if(result[r].thread_num < result[min_index].thread_num)
                min_index = r;
        }
    }

    if(min_index == i)
        return;
    swap(result[i], result[min_index]);
    siftdown(min_index, result);
}

int main()
{
    long long threads, num_tasks;
    cin>>threads>>num_tasks;
    vector<long long> tasks(num_tasks);
    for(long long i=0; i<num_tasks; i++)
        cin>>tasks[i];
    vector<schedule> result(threads);
    for(long long i=0; i<threads; i++){
        result[i].thread_num = i;
        result[i].task_time = 0;
    }
    for(long long i=(threads/2); i>=0; i--)
        siftdown(i, result);
    for(size_t i=0; i<tasks.size(); i++){
        cout<<result[0].thread_num<<" "<<result[0].task_time<<endl;
        result[0].task_time += tasks[i];
        siftdown(0, result);
    }
    return 0;
}
