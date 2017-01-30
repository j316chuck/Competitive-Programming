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

bool isdiagonal(int x, int y, int xi, int yi){
    if(x-xi == y-yi){
        return true;
    }else if (x-xi == yi-y){
        return true;
    }return false;
}

bool isvertical(int x, int y, int xi, int yi){
    if(x-xi == 0|| y-yi == 0){
        return true;
    }
    return false;
}

int main(){

    freopen("734D.in", "r", stdin);
    int n, xi, yi;
    cin>>n>>xi>>yi;
    vector< pair<int, int> > positions;
    for(int i = 0; i < 8; i++){
        positions.push_back(make_pair(INT_MAX, INT_MAX));
    }

    for(int i = 0; i < n; i++){
        char pp;
        int x, y;
        cin>>pp>>x>>y;
        bool d = isdiagonal(x, y, xi, yi);
        //cout<<d<<endl;
        bool v = isvertical(x, y, xi, yi);
        //cout<<v<<endl;
        if(pp == 'B'){
            if(d){
                if(x > xi && y > yi){

                }else if(x > xi && y < yi){
                    postions[]
                }
            }
        }else if(pp == 'R'){
            if(v){

            }
        }
    }

}
