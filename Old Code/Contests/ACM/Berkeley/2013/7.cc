//#include "contest.h"
#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int mem[14][14][14][14];
int total[14][14][14][14];

int eval(string s, int pos){
    if(pos == -1)
        return 0;
    else if(s[pos] == 'T')
        return 10;
    else if(s[pos] == 'J')
        return 11;
    else if(s[pos] == 'Q')
        return 12;
    else if(s[pos] == 'K')
        return 13;
    else if(s[pos] == 'A')
        return 1;
    else
        return s[pos]-'0';
}

string one, two, three, four;

int Recurse(int a, int b, int c, int d){
    if(mem[a][b][c][d]!=-1)
        return mem[a][b][c][d];
    else{
        int maximum = -1;
        if(a>0){
            mem[a-1][b][c][d] = Recurse(a-1, b, c, d);
            int score = total[a-1][b][c][d] - mem[a-1][b][c][d] + eval(one, a-1);
            maximum = max(score, maximum);
        }if(b>0){
            mem[a][b-1][c][d] = Recurse(a, b-1, c, d);
            int score = total[a][b-1][c][d] - mem[a][b-1][c][d] + eval(two, b-1);
            maximum = max(score, maximum);
        }if(c>0){
            mem[a][b][c-1][d] = Recurse(a, b, c-1, d);
            int score = total[a][b][c-1][d] - mem[a][b][c-1][d] + eval(three, c-1);
            maximum = max(score, maximum);
        }if(d>0){
            mem[a][b][c][d-1] = Recurse(a, b, c, d-1);
            int score = total[a][b][c][d-1] - mem[a][b][c][d-1] + eval(four, d-1);
            maximum = max(score, maximum);
        }
        mem[a][b][c][d] = maximum;
        return mem[a][b][c][d];
    }
}

int main(){

    freopen("7.in", "r", stdin);
    int counter = 0;
    /*for(int i = 0; i <= 2; i++){
        for(int j = 0; j <= 2; j++){
            for(int k = 0; k <=2; k++){
                for(int l = 0; l <=2; l++){
                    cout<<total[i][j][k][l]<<' '<<i<<' '<<j<<' '<<k<<' '<<l<<endl;;
                }
            }
        }
    }*/
    while(cin>>one>>two>>three>>four){
        counter++;
        memset(mem, -1, sizeof(mem));
        memset(total, 0, sizeof(mem));

        int length = one.length();
        mem[0][0][0][0] = 0;
        /*mem[1][1][0][0] = max(eval(one, 0), eval(two, 0));
        mem[1][0][1][0] = max(eval(one, 0), eval(three, 0));
        mem[1][0][0][1] = max(eval(one, 0), eval(four, 0));
        mem[0][1][1][0] = max(eval(two, 0), eval(three, 0));
        mem[0][1][0][1] = max(eval(two, 0), eval(four, 0));
        mem[0][0][1][1] = max(eval(three, 0), eval(four, 0));
        mem[1][0][0][0] = eval(one, 0);
        mem[0][1][0][0] = eval(two, 0);
        mem[0][0][1][0] = eval(three, 0);
        mem[0][0][0][1] = eval(four, 0);*/


        for(int i = 0; i <= length; i++){
            for(int j = 0; j <= length; j++){
                for(int k = 0; k <= length; k++){
                    for(int l = 0; l <= length; l++){
                        if(i!=0){
                            total[i][j][k][l]=(total[i-1][j][k][l] + eval(one, i-1));
                        }else if(j!=0){
                            total[i][j][k][l]=(total[i][j-1][k][l] + eval(two, j-1));
                        }else if(k!=0){
                            total[i][j][k][l]=(total[i][j][k-1][l] + eval(three, k-1));
                        }else if(l!=0){
                            total[i][j][k][l]=(total[i][j][k][l-1] + eval(four, l-1));
                        }
                    }
                }
            }
        }
        //cout<<Recurse(length, length, length, length);
        printf("Deal %d: First player wins %d out of %d\n", counter, Recurse(length, length, length, length), total[length][length][length][length]);
    }
    exit(0);
}
