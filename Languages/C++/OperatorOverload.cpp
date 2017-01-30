#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
using namespace std;

class mycomp
{
public:
    int one;
    int two;

    bool operator < (const mycomp &a) const
    {
        if(a.one>one) return true;
        if(a.one<one) return false;
        if(a.two>two) return true;
        if(a.two<two) return false;
    }

};
vector<mycomp> mygraph;
int main(){

    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int a, b;
        cin>>a>>b;
        mycomp rand;
        rand.one=a;
        rand.two=b;
        mygraph.push_back(rand);
    }
    sort(mygraph.begin(), mygraph.end());
    for(int i=0; i<N; i++){
        cout<<mygraph[i].one<<' '<<mygraph[i].two<<endl;
    }
}


//http://stackoverflow.com/questions/4421706/operator-overloading/4421715#4421715
