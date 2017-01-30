#include <iostream>
#include <vector>
using namespace std;

vector<int> A1;
int G(vector<int> A){
    A[0] = 3;
    return 1;
}

int main(){
    A1.push_back(0);
    G(A1);
    cout<<A1[0]<<endl;
}
