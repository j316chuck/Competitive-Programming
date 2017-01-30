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
#include <cstdlib>
using namespace std;
//using vector to solve the problem

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)

class my_vote{
public:
    string name;
    int count;
    /*
    bool operator < (const my_vote &a) const
    {
        return count>a.count;
    }
    */
     bool operator < (const my_vote &a) const
    {
        return count<a.count;
    }

};

int main()
{
    freopen("Vote_Count.in","r",stdin);
    int N;
    cin>>N;
    map<string,int> myMap;

    string name;

    for(int i = 0 ; i < N; i++){
        cin>>name;
        myMap[name]= 0;
    }

    int k;
    cin>>k;
    int count;
    double total = 0;

    for(int i = 0; i < k; i++)
    {
        cin>>name>>count;
        map<string,int>::iterator itr = myMap.find(name);
        if(itr!=myMap.end())
        {
            (*itr).second=(*itr).second+count;
            total = total +count;
        }
    }

/*
    vector<my_vote> myVoteArray;
    map<string,int>::iterator itr= myMap.begin();
    for(; itr!=myMap.end();itr++)
    {
        my_vote a;
        a.name = (*itr).first;
        a.count = (*itr).second;
        myVoteArray.push_back(a);
    }
    sort(myVoteArray.begin(),myVoteArray.end());
*/

priority_queue<my_vote> myVoteQ;
    /*int Maximum = myVoteArray[0].count;
    cout<<myVoteArray[0].name<<' '<<(myVoteArray[0].count/total)*100<<'\n';
    for(int i = 1; i < myVoteArray.size(); i++)
    {
        if(Maximum!=myVoteArray[i].count)
        {
            break;
        }

        cout<<myVoteArray[i].name<<' '<<(myVoteArray[i].count/total)*100<<'\n';

    }

    */


map<string,int>::iterator itr= myMap.begin();
    for(; itr!=myMap.end();itr++)
    {
        my_vote a;
        a.name = (*itr).first;
        a.count = (*itr).second;
        myVoteQ.push(a);
    }
    my_vote a = myVoteQ.top();
    int theMaxCnt = a.count;

    cout<<a.name<<' '<<(theMaxCnt/total)*100<<'\n';
    myVoteQ.pop();

    while(!myVoteQ.empty())
    {
        my_vote b=myVoteQ.top();
        if(b.count != theMaxCnt)
        {
            break;
        }
       cout<<a.name<<' '<<(theMaxCnt/total)*100<<'\n';
    }
}

