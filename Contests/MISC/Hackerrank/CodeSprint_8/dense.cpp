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

int main(){

    freopen("dense.in", "r", stdin);

    int n;
    cin >> n;
    vector<int> scores;
    int score;
    int prev_score = -1;
    for(int scores_i = 0;scores_i < n;scores_i++){
        cin >> score;
        if(score == prev_score){
            continue;
        }
        prev_score = score;
        scores.push_back(score);
    }
    int m;
    cin >> m;
    vector<int> alice;
    int a;
    for(int alice_i = 0;alice_i < m;alice_i++){
       cin >> a;
       alice.push_back(a);
    }
    // your code goes here
    reverse(scores.begin(), scores.end());
    int s = scores.size()+1;
    int counter = 0;
    int pos = 0;
    for(int i = 0; i < m; i++){
        counter += alice[i];
        for(int j = pos; j < scores.size(); j++){
            if(scores[j] > counter){
                cout<<s<<endl;
                pos = j;
                break;
            }else if(scores[j] == counter){
                pos = j;
                cout<<--s<<endl;
                break;
            }else{
                pos++;
                s--;
                continue;
            }
        }
        if(pos == scores.size()){
            cout<<1<<endl;
        }
    }
    return 0;
}
