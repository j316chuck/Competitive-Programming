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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int main(){

    freopen("5.in", "r", stdin);

    string str;
    while(cin>>str){
        sort(str.begin(), str.end());
        vector<int> myvector;
        bool is_letter[27];
            memset(is_letter, 0, sizeof(is_letter));
        for(int i = 0; i < str.size(); i++){
            myvector.push_back(str[i]+'0'-145);
            is_letter[str[i]+'0'-145] = 1;
        }

        int mem[27][27];
        int result[27];
        memset(result, 0, sizeof(result));
        result[0] = 1;
        mem[0][0] = 1;

        for(int i = 1; i < str.size(); i++){
            for(int j = 0; j <= i ; j++){
                if(j == i){
                    mem[i][j] = 1+result[j-1];
                }else if(j == 0){
                    mem[i][j] = myvector[i]-myvector[j]+2-(i-j);
                }else{
                    mem[i][j] = myvector[i]-myvector[j]+2-(i-j);
                    mem[i][j] += result[j-1];
                }
                //cout<<mem[i][j]<<' '<<i<<' '<<j<<' '<<endl;
                if(j == 0)
                    result[i] = mem[i][j];
                else
                    result[i] = min(result[i], mem[i][j]);
            }
        }
        /*for(int i = 0; i < str.size(); i++){
            for(int j = 0; j <= i; j++){
                cout<<mem[i][j]<<' ';
            }cout<<"    Result: "<<result[i]<<endl;
        }*/
        vector< pair<int, int> > myresult;
        int N = result[str.size()-1];
        int e = str.size()-1;
        int s;
        int i = str.size()-1;

        for(int j = i; j >= 0; j--){
            if(N == mem[i][j]){
                    //cout<<N<<' '<<i<<' '<<j<<endl;
                s = j;
                pair<int, int> a;
                a.first = s, a.second =e;
                myresult.push_back(a);
                e = j-1;
                i = j-1;
                N = result[j-1];
            }
        }

        sort(myresult.begin(), myresult.end());
        string finalresult="[";
        string exclude = "";
        for(int i = 0; i < myresult.size(); i++){
            if(myresult[i].first == myresult[i].second){
                finalresult+=str[myresult[i].first];
            }
            else{
                finalresult+=str[myresult[i].first];
                finalresult+="-";
                finalresult+=str[myresult[i].second];
                //cout<<myresult[i].first<<' '<<myresult[i].second<<endl;
                for(int j = str[myresult[i].first]+'0'-145; j < str[myresult[i].second]+'0'-145; j++){
                    if(is_letter[j]==0){
                        exclude+='a'+j;
                        //cout<<'a'+j<<' '<<j<<endl;
                    }
                }
            }
        }
        finalresult+="|";
        cout<<str<<' '<<finalresult<<exclude<<"]"<<endl;
    }
}
