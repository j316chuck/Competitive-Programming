#include <iostream>
#include <vector>
using namespace std;

int func(int *parent){
    parent[0]++;
    cout<<parent[0]<<endl;
    return 1;
}
int change(int parent[]){
    parent[0]++;
    cout<<parent[0]<<endl;
    return 1;
}
int change(vector<int> parent){
    parent[0]++;

}

int main(){

    int parent[4] = {1, 2, 3, 4};
    func(parent);
    cout<<parent[0]<<endl;
    change(parent);
    cout<<parent[0]<<endl;

    vector<int> p;
    p.push_back(1);
    change(p);
    cout<<p[0]<<endl;
}

