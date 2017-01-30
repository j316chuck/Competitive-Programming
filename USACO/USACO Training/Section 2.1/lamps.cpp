/*
ID: j316chuck
PROG: lamps
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

int arr[16];
int myarray[102];
int mygraph[16][102];
int main(){
    Rd("lamps.in");
    Wt("lamps.out");
    int N, C;
    cin>>N>>C;
    int a,b;
    int check[102];

    memset(check, -1, sizeof(check));
    //memset(mygraph, -1, sizeof(mygraph));
    while(a!=-1){
        cin>>a;
        check[a-1]=1;
    }
    while(b!=-1){
        cin>>b;
        check[b-1]=0;
    }


    for(int i=0; i<2; i++){
        for(int k=0; k<2; k++){
            for(int j=0; j<2; j++){
                for(int l=0; l<2; l++){
                    //cout<<i<<' '<<k<<' '<<j<<' '<<l<<endl;
                    for(int m=0; m<N; m++)
                        myarray[m]=1;

                    if(i==1){
                        for(int m=0; m<N; m++){
                            if(myarray[m]==1)
                                myarray[m]=0;
                            else if(myarray[m]==0)
                                myarray[m]=1;
                        }
                    }
                    if(k==1){
                        for(int m=0; m<N; m++){
                            if(m%2==0){
                                if(myarray[m]==1)
                                    myarray[m]=0;
                                else if(myarray[m]==0)
                                    myarray[m]=1;
                            }
                        }
                    }
                    if(j==1){
                        for(int m=0; m<N; m++){
                            if(m%2==1){
                                if(myarray[m]==1)
                                    myarray[m]=0;
                                else if(myarray[m]==0)
                                    myarray[m]=1;
                            }
                        }
                    }
                    if(l==1){
                        for(int m=0; m<N; m++){
                            //cout<<myarray[i];
                            if(m%3==0){
                                if(myarray[m]==1)
                                    myarray[m]=0;
                                else if(myarray[m]==0)
                                    myarray[m]=1;
                            }
                            //cout<<myarray[]<<' ';
                        }//cout<<endl;
                    }
                    for(int m=0; m<N; m++){
                        mygraph[i*8+k*4+j*2+l][m]=myarray[m];
                        //cout<<mygraph[i*8+k*4+j*2+l][m];
                        //if(i*8+k*4+j*2+l==8)
                            //cout<<mygraph[i*8+k*4+j*2+l][m];
                    }//cout<<endl;
                }
            }
        }
    }
    /*for(int i=0; i<16; i++){
       for(int k=0; k<N; k++){
            cout<<mygraph[i][k];
        }
        cout<<endl;
    }*/
   for(int i=0; i<16; i++){
       for(int k=0; k<N; k++){
            if(check[k]==-1)
                continue;
            else if(check[k]==1&&mygraph[i][k]!=1){
                arr[i]=-1;
            }else if(check[k]==0&&mygraph[i][k]==1){
                arr[i]=-1;
            }
        }
   }
    //for(int i=0; i<16; i++)
        //cout<<arr[i];

    //cout<<endl;
    vector<string> answer;
   for(int i=0; i<16; i++){
        int sum;
        if(i==15)
            sum=4;
        if(i==0)
            sum=0;
        if(i==1||i==2||i==4||i==8)
            sum=1;
        if(i==14||i==13||i==11||i==7)
            sum=3;
        if(i==3||i==5||i==6||i==9||i==10||i==12)
            sum=2;

        if(arr[i]==0 && sum > C){
            arr[i]=-1;
        }
        if(arr[i]==0 && (C-sum)%2!=0)
            arr[i]=-1;
        if(arr[i]==0){
            string rand;
            for(int k=0; k<N; k++){
                rand+=mygraph[i][k]+'0';
            }
            answer.push_back(rand);
        }
   }

   for(int i=0; i<answer.size(); i++){
        for(int k=i+1; k<answer.size(); k++){
            if(answer[i].substr(0,10)==answer[k].substr(0,10)){
                answer.erase(answer.begin()+i);
            }
        }
   }
   /*vector< pair<unsigned long long, string> > myanswer;
   for(int i=0; i<answer.size(); i++){
        unsigned long long j=0;
        for(int k=0; k<answer[0].size(); k++){
            if(answer[i][k]=='1'){
                j+=pow(2,answer[0].size()-k-1);
            }
        }
        pair<unsigned long long, string> rand;
        rand.first=j;
        rand.second=answer[i];
        myanswer.push_back(rand);
   }
   sort(myanswer.begin(), myanswer.end());*/
    for(int i=0; i<answer.size(); i++){
       for(int k=0; k<answer.size()-1; k++){
            if(answer[k].compare(answer[k+1])>0){
                swap(answer[k], answer[k+1]);
            }

        }
   }
   for(int i=0; i<answer.size(); i++)
        cout<<answer[i]<<endl;
    if(answer.size()==0)
        cout<<"IMPOSSIBLE"<<endl;
}
    /*for(int i=0; i<16; i++)
        cout<<arr[i];*/




    /*
    party rand;
                    for(int m=0; m<N; m++){
                        cout<<myarray[m]<<' ';
                        if(m==N-1)
                            cout<<endl;
                        rand.arr[m]=myarray[m];
                    }
                    rand.sum=i+j+k+l;
                    mygraph.push_back(rand);
    /*for(int i=0; i<16; i++){
        for(int k=0; k<N; i++){
            cout<<mygraph[i].arr[k]<<' ';
        }
        cout<<"sum: "<<mygraph[i].sum<<endl;
    }*/

