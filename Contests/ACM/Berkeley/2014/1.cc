//#include "contest.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

char int_to_upper[]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z'};
int main(){

    freopen("1.in", "r", stdin);

    string s, part_1;

    while(getline(cin, s) && getline(cin, part_1)){
        //cout<<s<<' '<<part<<endl;
        s.erase(s.size()-1);
        int str[2500];
        int part[2500];
        for(int i = 0; i < part_1.size(); i++){
            if(part_1[i] == ' '){
                part[i] = 0;
            }else{
                part[i] = part_1[i]-'A'+1;
            }
            //cout<<part[i]<<' ';
        }//cout<<endl;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                str[i] = 0;
            }else{
                str[i] = s[i] - 'A'+ 1;
            }
        }
        vector<int> diff;
        for(int i = 0; i < part_1.size()-1; i++){
            diff.push_back(part[i+1]-part[i]);
            cout<<diff[i]<<' ';
        }cout<<endl;

        vector<int> word_diff;
        for(int i = 0; i < part_1.size()-1; i++){
            word_diff.push_back(str[i+1]-str[i]);
            //cout<<word_diff[i]<<' ';
        }//cout<<endl;
        if(word_diff == diff){
            //diff = for part of string
            //word_diff = for whole string
            int difference = part[0]-str[0];
            //if()
            for(int i = 0; i < s.size(); i++){
                str[i] = (str[i] + difference + 27) %27;
                //cout<<str[i]<<' ';
            }//cout<<endl;
            for(int i = 0; i <s.size(); i++){
                if(str[i] == 0)
                    cout<<' ';
                else
                    cout<<int_to_upper[str[i]-1];
            }cout<<'.'<<endl;
        }else{
            for(int i = 1; i < s.size()-part_1.size()+1; i++){
                word_diff.erase(word_diff.begin());
                word_diff.push_back(str[i+part_1.size()-1]-str[i+part_1.size()-2]);
                /*for(int i = 0; i < word_diff.size(); i++){
                    cout<<word_diff[i]<<' ';
                }cout<<endl;*/
                if(word_diff == diff){
                    /*for(int k = 0; k < word_diff.size(); k++){
                        cout<<word_diff[k]<<' ';
                    }cout<<endl;*/
                    //cout<<i<<endl;
                    //cout<<str[i]<<endl;
                    int difference = part[0]-str[i];
                    //if()
                    //cout<<s[i+2]<<s[i+3]<<s[i+4]<<endl;
                    //cout<<difference<<' '<<i<<endl;
                    for(int k = 0; k < s.size(); k++){
                        str[k] = (str[k] + difference + 27) %27;
                        //cout<<str[i]<<' ';
                    }//cout<<endl;
                    for(int k = 0; k <s.size(); k++){
                        if(str[k] == 0)
                            cout<<' ';
                        else
                            cout<<int_to_upper[str[k]-1];
                    }cout<<'.'<<endl;
                    break;
                }
            }
        }

        //cout<<'B'-'A' +1 <<endl;
        //cout<<s[19]-' '<<endl;
        /*for(int i = 0; i < part.size()-1; i++){
            diff[i] = part[i+1]-part[i];
        }
        for(int i = 0; i < part.size()-1; i++){

        }
        for(int i = 0; i < ){

        }*/
    }
    exit(0);
}
