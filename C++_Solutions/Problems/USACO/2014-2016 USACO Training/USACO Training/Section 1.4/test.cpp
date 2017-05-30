#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class two
{
public:
    int x;
    int y;
    bool operator < (const two &a) const
    {
        return x<a.x;
    }

};
vector<two> random;
int main()
{
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        two asd;
        cin>>asd.x>>asd.y;
        random.push_back(asd);
    }

    sort(random.begin(), random.end());

    for(int i = 0; i < N; i++)
    {
        cout<<random[i].x<<' '<<random[i].y<<endl;
    }
}
