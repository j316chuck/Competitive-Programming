/*ID: j316chuck
PROG: checklist
LANG: C++
*/

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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define pii pair<int, int>

using namespace std;

/*int find(int parent[], int i){
    if(parent[i]==-1){
        return i;
    }return find(parent, parent[i]);
}
void Union(int parent[], int x, int y){
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}*/

vector<int> pset(1000);
void initset(int size){
    pset.resize(size);
    for(int i = 0; i < size; i++){
        pset[i] = i;
    }
}
int findset(int i){
    return (pset[i] == i) ? i : (pset[i] = findset(pset[i]));
}
void unionset(int i, int j){
    pset[findset(i)] = findset(j);
}
bool issameset(int i, int j){
    return findset(i) == findset(j);
}

int numofset(){
    set<int> temp;
    for(int i = 0; i < pset.size(); i++){
        temp.insert(pset[i]);
    }
    return temp.size();
}
int sizeofset(int j){
    zazaint counter = 0;
    for(int i = 0; i < pset.size(); i++){
        if(pset[j] == pset[i]){
            counter++;
        }
    }
    return counter;
}
int main(){
    initset(3);
    cout<<findset(1)<<endl;
    //num of disjoint sets = add one line numdisjointsets--;

    //Rd("checklist.in");
    //Wt("checklist.out");
    //cout<<"3 is "<<(3==0 ? "even": "odd")<<endl;
}

