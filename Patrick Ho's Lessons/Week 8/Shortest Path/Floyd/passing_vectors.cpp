#include <iostream>
#include <vector>
using namespace std;

void nochange(vector< vector<int> > graph){

    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            graph[i][j]++;
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }
    cout<<endl;
}

//change
void pass(vector< vector<int> > &graph){
     for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            graph[i][j]++;
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }
    cout<<endl;
}
int main(){

    vector< vector<int> > graph;
    for(int i = 0; i < 10; i++){
        vector<int> a;
        for(int j = 0; j < 5; j++){
            a.push_back(j);
        }graph.push_back(a);
    }

    pass(graph);
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            cout<<graph[i][j]<<' ';
        }cout<<endl;
    }
}
