
/*
ID: j316chuck
PROG: runround
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
using namespace std;

int myarray[100];

bool runaround(int M){
    Set (myarray, 0);
    string s;
    //cout<<M<<endl;
    while(M!=0){
        s+=(M%10)+'0';
        M=M/10;
    }

    //cout<<s<<endl;
    string a;

    for(int i=s.size()-1; i>=0; i--){
        a+=s[i];
    }

    int index=0;
    int result=0;
    myarray[0]=-1;
    while(index!=-1){
        for(int i=0; i<a.size(); i++){
            //cout<<myarray[i];
            if(myarray[i]!=1){
                break;
            }if(i==a.size()-1){
                result=1;
                break;
            }
        }//cout<<' ';
        if(result!=0){
            index=-1;
            break;
        }
        if(myarray[index]==1){
            index=-1;
            break;
        }else{
            myarray[index]++;
            //cout<<index<<' '<<a[index]-'0';
            index+=((a[index]-'0')%a.size());
            if(index>=a.size()){
                index=index-a.size();
            }
        }

        //cout<<endl;
    }
    if(result==1)
        return true;
    else
        return false;

}
bool notvalid(int M){
    cout<<M<<endl;
    bool valid=true;
    int arr[10];
    Set(arr, 0);

    while(M!=0){
        arr[M%10]++;
        M=M/10;
    }
    if(arr[0]!=0){
        valid=false;
        return valid;
    }
    for(int i=1; i<10; i++){
       if(arr[i]>1){
            valid=false;
            break;
        }
    }
    return valid;
}
int main(){
    Rd("runround.in");
    Wt("runround.out");
    int M;
    cin>>M;
    M++;
    while(1){
        //cout<<M+1<<endl;
        int arr[10];
        Set(arr, 0);
        int K=M;
        while(K!=0){
            arr[K%10]++;
            K=K/10;
        }
        if(arr[0]>0){
            M++;
            continue;
        }
        int rand=0;
        //cout<<arr[9];
        for(int i=1; i<10; i++){
            if(arr[i]>1){
                M++;
                rand=1;
                break;
            }
        }
        if(rand==1)
            continue;
        else if(runaround(M)==true)
            break;
        else
            M++;
    }
    cout<<M<<endl;
}
