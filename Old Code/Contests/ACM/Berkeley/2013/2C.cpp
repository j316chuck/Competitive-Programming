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
//#include <contest.h>

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

class grid{
public:
    int number;
    int direction;
    int x;
    int y;
    //int preset;
};
//N*x + y + 1;
int N;
vector< vector<grid> > mygraph;
//north = 0 northeaast = 1

bool check(int x, int y){
    //cout<<x<<y<<endl;
    if (x >= 0 && x < N && y >= 0 && y <N){
        //cout<<"hello"<<endl;
        return true;
    }
    return false;
}
int next_y(int dir){
    if(dir == 0||dir == 4){
        return 0;
    }else if(dir == 1|| dir == 2|| dir == 3){
        return 1;
    }else if(dir == 5|| dir == 6|| dir == 7){
        return -1;
    }
}
int next_x(int dir){
    if(dir == 7 || dir == 0 || dir == 1){
        return -1;
    }else if(dir == 2 || dir == 6){
        return 0;
    }else if(dir == 3 || dir == 4 || dir ==5){
        return 1;
    }
}

void Recurse(grid a, int counter){
    if(counter == N * N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<mygraph[i][j].number<<' ';
            }cout<<endl;
        }
        return;
    }
    //cout<<counter<<endl;
    /*if(counter == 12 && a.x == 4 && a.y == 1 &&mygraph[4][2].number==11){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout<<mygraph[i][j].number<<' ';
            }cout<<endl;
        }
    } */   /*for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout<<mygraph[i][j].number<<' ';
        }cout<<endl;
    }*/

    int x = a.x, y = a.y;
    //cout<<"x: "<<x<<" y: "<<y<<endl;
    //cout<<"counter: "<<counter<<" number: "<<mygraph[x][y].number<<" direction: "<<mygraph[x][y].direction<<endl;
    //cout<<x<<y<<endl;
    while(check(x, y) == true){
      //   cout<<"x: "<<x<<" y: "<<y<<endl;
    //cout<<"counter: "<<counter<<" number: "<<mygraph[x][y].number<<" direction: "<<mygraph[x][y].direction<<endl;
        x += next_x(a.direction);
        y += next_y(a.direction);
        if(check(x,y) == true){
            //cout<<x<<' '<<y<<endl;
            //counter+=1;

            if(mygraph[x][y].number == 0){
                mygraph[x][y].number = counter+1;
                Recurse(mygraph[x][y], counter+1);
                mygraph[x][y].number = 0;
            }else if(mygraph[x][y].number == counter+1){
                Recurse(mygraph[x][y], counter+1);
            }/*else if(mygraph[x][y].number!= counter){
                return;
            }*/
        }
    }
    //return;
}

int main(){
    freopen("2.in", "r", stdin);
    //freopen("2.out", "w", stdout);

    /*char words[1000];
    while(scanf("%999s", words)){
        //mygraph.clear();
        string str(words);
        if(str == "0"){
            //cout<<str<<endl;
            break;
        }
        else{*/
    string s;
    while(s!="0"){
            cin>>s;
            //cout<<str<<endl;
            mygraph.clear();
            //cin>>N;
            //cout<<N<<endl;
            N = atoi(s.c_str());
            //cout<<N<<endl;
            grid start;
            for(int i = 0; i < N; i++){
                vector<grid> random;
                for(int j = 0; j < N; j++){
                    grid a;
                    cin>>a.number>>a.direction;
                    a.x = i;
                    a.y = j;
                    if(i == 0 && j == 0){
                        start = a;
                    }
                    random.push_back(a);
                }mygraph.push_back(random);
            }
            /*for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    cout<<mygraph[i][j].number<<' '<<mygraph[i][j].direction<<' ';
                }cout<<endl;
            }*/

            Recurse(start, 1);
    }

}
