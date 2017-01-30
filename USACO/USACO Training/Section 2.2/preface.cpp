/*ID: j316chuck
PROG: preface
LANG: C++
 */

#include <iostream>
#include <cstdio>
#include <algorithm>


#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define MAX 1001
using namespace std;

int mem[3501][7];
int total[7];


int main(){

    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    int N;
    cin>>N;

    for(int i = 1; i <= 3500; i++){
        mem[i][6] += ((i+100)/1000); //1000
        if(i % 1000 >= 400 && i % 1000 < 900) //500
            mem[i][5]++;
        if((i % 500)/100 == 1||(i % 500)/100 == 2|| (i % 500)/100 == 3)
           mem[i][4]+=((i % 500)/100); //100
        if((i % 500)/100 == 4)
            mem[i][4]+=1;
        if(i % 100 >= 90)
            mem[i][4]+=1;
        if(i % 100 >= 40 && i % 100 < 90)
            mem[i][3]+=1;
        if((i % 50)/10 == 1||(i % 50)/10 == 2||(i % 50)/10  == 3)
            mem[i][2]+=(i % 50)/10;
        if (i % 50 >= 40)
            mem[i][2]++;
        if(i % 10 == 9)
            mem[i][2]++;
        if(i % 10 == 4|| i % 10 == 5 || i % 10 == 6||i % 10 == 7 || i % 10 == 8)
            mem[i][1]++;
        if(i % 5 == 1|| i % 5 == 2 || i %5 ==3 )
            mem[i][0]+=( i % 5);
        if(i % 5 == 4)
            mem[i][0]++;
    }

    for(int i = 1; i <= N; i++){
        for(int k = 0; k < 7; k++){
            total[k] += mem[i][k];
        }
    }

    for(int i = 0; i < 7; i++){
        if(total[i] == 0)
            continue;
        else{
            if (i == 0)
                cout<<"I "<<total[i]<<endl;
            else if (i == 1)
                cout<<"V "<<total[i]<<endl;
            else if (i == 2)
                cout<<"X "<<total[i]<<endl;
            else if (i == 3)
                cout<<"L "<<total[i]<<endl;
            else if (i == 4)
                cout<<"C "<<total[i]<<endl;
            else if (i == 5)
                cout<<"D "<<total[i]<<endl;
            else if (i == 6)
                cout<<"M "<<total[i]<<endl;
        }
    }
}
