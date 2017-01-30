#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct twoguys
{
    int x;
    int y;
};
class compare
{
public:
  bool operator()(twoguys& t1, twoguys &t2 )
  {
      if(t1.x>t2.x) return true;
      if(t1.x==t2.x&&t1.y>t2.y) return true;
      else
        return false;
  }
};

vector<twoguys> random;
int main()
{
    int N;
    cin>>N;
    for(int i = 0; i < N; i++)
    {
        twoguys asd;
        cin>>asd.x>>asd.y;
        random.push_back(asd);
    }

    sort(random.begin(), random.end(), compare);

    for(int i = 0; i < N; i++)
    {
        cout<<random[i].x<<' '<<random[i].y<<endl;
    }
}

