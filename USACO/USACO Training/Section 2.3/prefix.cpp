/*
ID: j316chuck
PROG: prefix
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

const double Pi=acos(-1.0);
typedef long long LL;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int arr[200001]; //0 = start //1 = end

int main(){

    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    string s;
    vector<string> mystring;
    while(s!="."){
        cin>>s;
        mystring.push_back(s);
        //cout<<s<<' ';
    }
    mystring.erase(mystring.end());
    string pre, prefix;
    while(cin>>pre){
        prefix+=pre;
    }
    //cin>>prefix;
    //cout<<prefix<<endl;
    /*for(int i = 0; i < mystring.size(); i++){
        for(int j = 0; j < prefix.size()-mystring[i].size()+1; j++){
            for(int k = j; k < j+mystring[i].size(); k++){
                if(mystring[i][k-j] != prefix[k])
                    break;
                if(k == j+mystring[i].size()-1){
                    //cout<<"equal "<<j<<' '<<mystring[i]<<endl;
                    if(j -1 < 0)
                        length = arr[j-1][1] + arr[];

                    arr[j][0] = max(arr[j][0], )
                }
            }
        }
    }*/
    //for(int i = 0; i < mystring.size(); i++)
    //    cout<<mystring[i]<<endl;
    int result = 0;
    for(int i = 0; i < prefix.size(); i++){
        for(int j = 0; j < mystring.size(); j++){
            int a = mystring[j].size();
            int b = i;
            if(b-a+1>= 0){
                //cout<<mystring[j]<<' '<<i<<endl;
                //cout<<i-mystring[j].size()+1 <<endl;
                //cout<<mystring[j]<<' '<<j<<' '<<mystring[j].size()<<' '<<i<<' '<<i-mystring[j].size()+1<<endl;
                for(int k = i-mystring[j].size()+1; k <= i; k++){
                    if(prefix[k]!=mystring[j][k-i+mystring[j].size()-1]){
                        //cout<<i<<' '<<k<<' '<<mystring[j].size()<<' '<<' '<<mystring[j]<<prefix[k]<<' '<<mystring[j][k-i+mystring.size()-1]<<' '<<k-i+mystring.size()-1<<endl;
                        break;
                    }if(k == i && i-mystring[j].size()+1==0){
                        arr[i] = mystring[j].size();
                        //cout<<arr[i]<<' ';
                    }else if(k == i){
                        if(arr[i-mystring[j].size()]!=0){
                            int a = arr[i-mystring[j].size()]+mystring[j].size();
                            arr[i] = max(a, arr[i]);
                            //cout<<arr[i]<<' '<<mystring[j]<<endl;;
                        }
                        //arr[i] = max(arr[i-mystring[j].size()]+mystring[j].size(), arr[i]);
                        //cout<<arr[i]<<' ';
                    }
                }
            }result = max(result, arr[i]);
        }
    }

    cout<<result<<endl;
}
