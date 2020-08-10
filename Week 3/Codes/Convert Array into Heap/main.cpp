#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;
vector<int> res;

int left_child(int i){
    return ((2*i)+1);
}

int right_child(int i){
    return ((2*i)+2);
}

void siftDown(int i){
    int min_index=i;
    int l = left_child(i);
    int r = right_child(i);

    if(l<n && arr[l] < arr[min_index])
        min_index = l;
    if(r<n && arr[r] < arr[min_index])
        min_index = r;

    if(min_index == i)
        return;
    res.push_back(i);
    res.push_back(min_index);
    swap(arr[i], arr[min_index]);
    siftDown(min_index);
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        arr.emplace_back(temp);
    }
    for(int i=(n/2); i>=0; i--)
        siftDown(i);
    cout<<(res.size()/2)<<endl;
    for(size_t i=0; i<res.size(); i+=2)
        cout<<res[i]<<" "<<res[i+1]<<endl;
    return 0;
}
