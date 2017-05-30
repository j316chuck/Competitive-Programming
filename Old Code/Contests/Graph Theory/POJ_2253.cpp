#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

const int MAXN = 1010;
const int INF = 1 << 29;


int main()
{

    int N=100;
   while(1)
   {
       cin>>N;

       if(N==0)
        break;
       vector< pair<int, int> > mygraph;
       double dist[201][201];
        pair<int, int> start;
        cin>>start.first>>start.second;
        pair<int, int> end;
        cin>>end.first>>end.second;

       for(int i=0; i <N-2; i++)
       {
           pair<int, int> random;
           cin>>random.first>>random.second;
           mygraph.push_back(random);
       }
       mygraph.insert(mygraph.begin(), start);
       mygraph.insert(mygraph.end(), end);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
			dist[i][j] = dist[j][i] = INF;
            }
        }

        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
        }
       for(int i=0; i <mygraph.size(); i++)
       {
            for(int j=0; j <mygraph.size(); j++)
            {
                dist[i][j]=sqrt((mygraph[i].first-mygraph[j].first)*(mygraph[i].first-mygraph[j].first)+(mygraph[i].second-mygraph[j].second)*(mygraph[i].second-mygraph[j].second));
            }
       }

       for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
				// relax distance
				dist[i][j]=min(dist[i][j], max(dist[i][k], dist[k][j]));
                }
            }
       }
       double minimum=INF;
       for(int i=0; i<N; i++)
       {
           minimum=min(dist[N-1][i], minimum);
       }
       cout<<minimum<<endl;
   }


}
