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


int main()
{
    map<string, double> value;

    int N;
    string name;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        cin>>name;
        value[name]= 0;

    }

    int M;
    cin>>M;

    double votes;

    for(int i = 0; i < M; i++)
    {
        cin>>name;
        cin>>votes;
        map<string, double>::iterator itr=value.find(name);
            if (itr == value.end())
            {
               continue;
            }
            else
            {
                value[(*itr).first]= votes+(*itr).second;
            }

    }

    map<string,double>::iterator it = value.begin();
    int sum = 0;
    while(it!= value.end())
    {
       sum += (*it).second;
       it++;
    }
    //cout<<sum<<endl;

    type var = (*itr).second;
   for(map<string, double>::iterator itr = thing.begin(); itr != thing.end(); itr++)
    {
        if((*iter).second < ((*iter)+1).second)
        {
            maximum = ((*iter)+1).second;
        }
        iter++;

    }

    /*


   vector<pair<double, string> > newthing;
vector<pair<string, double> > to_sort(value.begin(), value.end());

for (int i = 0; i < to_sort.size(); i++) {
        newthing.push_back(vector<pair<double, string> >(to_sort[i].second, to_sort[i].first));
}
sort(newthing.begin(), newthing.end());



   cout << newthing.first << " " << newthing.second << "\n";

    /*it = value.begin();
    int length = value.size();
    sort((*it).second,  (*it).second+length, myComp);

   /* map<string,double>::iterator iter=value.begin();
    int maximum = 0;
    maximum = (*iter).second;


    for(int i = 0; i < total; i++)
    {
        if((*iter).second < (*(iter+1)). second)
        {

        }
        iter++;
    }
    */

}

