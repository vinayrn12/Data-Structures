#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_tables = 0;

struct query{
    int source;
    int destination;
};

void makeset(int i, vector<int> &parent, vector<int> &rank1){
    parent[i] = i;
    rank1[i] = 0;
}

int find_parent(int i, vector<int> &parent){
    if(i != parent[i])
        parent[i] = find_parent(parent[i], parent);
    return parent[i];
}

void union1(int i, int j, vector<int> &parent, vector<int> &tables, vector<int> &rank1){
    int i_id = find_parent(i, parent);
    int j_id = find_parent(j, parent);

    if(i_id == j_id)
        return;

    if(rank1[i_id] > rank1[j_id]){
        tables[i_id] += tables[j_id];
        if(max_tables < tables[i_id])
            max_tables = tables[i_id];
        tables[j_id] = 0;
        parent[j_id] = i_id;
    }
    else{
        parent[i_id] = j_id;
        tables[j_id] += tables[i_id];
        if(max_tables < tables[j_id])
            max_tables = tables[j_id];
        tables[i_id] = 0;
        if(rank1[i_id] == rank1[j_id])
            rank1[j_id] += 1;
    }
}

int main()
{
    int num_tables, num_queries;
    cin>>num_tables>>num_queries;
    vector<int> tables(num_tables);
    vector<query> queries(num_queries);
    for(int i=0; i<num_tables; i++){
        cin>>tables[i];
        if(max_tables < tables[i])
            max_tables = tables[i];
    }
    for(int i=0; i<num_queries; i++)
        cin>>queries[i].source>>queries[i].destination;
    vector<int> parent(num_tables);
    vector<int> rank1(num_tables);
    // Solution
    for(size_t i=0; i<tables.size(); i++)
        makeset(i, parent, rank1);
    for(size_t i=0; i<queries.size(); i++){
        union1(queries[i].source - 1, queries[i].destination - 1, parent, tables, rank1);
        cout<<max_tables<<endl;
    }
    //
    return 0;
}
