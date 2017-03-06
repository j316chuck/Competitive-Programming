#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class node{

public:
    char root;
    vector<node> branches;

};

void DFS(node n){

    cout<<n.root<<endl;
    for(int i = 0; i < n.branches.size(); i++){
        DFS(n.branches[i]);
    }

}
int main(){

    node a, b, c, d, e;
    a.root = 'a';
    b.root = 'b';
    c.root = 'c';
    d.root = 'd';
    e.root = 'e';

    b.branches.push_back(d);
    b.branches.push_back(e);
    a.branches.push_back(b);
    a.branches.push_back(c);

    //recursive solution
    DFS(a);

    //iterative solution
    stack<node> mystack;

    mystack.push(a);

    while(!mystack.empty()){
        node top = mystack.top();
        mystack.pop();
        cout<<top.root<<endl;
        for(int i = top.branches.size()-1; i >= 0; i--){
            mystack.push(top.branches[i]);
        }
    }
    queue<node> Queue;

    Queue.push(a);
    while(!Queue.empty()){
        node top = Queue.front();
        Queue.pop();
        cout<<top.root<<endl;
        for(int i = 0; i < top.branches.size(); i++){
            Queue.push(top.branches[i]);
        }
    }
    //bfs solution
}



