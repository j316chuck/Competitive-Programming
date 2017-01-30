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

long long lower_palindrome(string limit, bool less_left, bool first_iter){
    /*long long total = 9;
    if(limit == "0")
        return 1;
    for(int i = 1; i < limit.length(); i++){
        total *= pow(10, (i-1)/2)
    }*/
    int upper = limit[0] - '0';
    int lower = limit[limit.size()-1] - '0';
    if(limit.size() == 2){
        /*int negative = 0;
        if (first_iter){
            negative = -1;
        }*/
        if(less_left == true){
            if(upper > lower){
                return upper; //+ negative;
            }else{
                return upper + 1;// + negative;
            }
        }else{
            if(upper >= lower){
                return upper;// + negative;
            }else{
                return upper;// + 1 + negative;
            }
        }
    }else if(limit.size() == 1){
        if(less_left == true){
            return upper+1;
        }else{
            return upper;
        }
    }else{
        if(first_iter == true){
            return (upper-1) * pow(10, (limit.size()-1)/2) +
            lower_palindrome(limit.substr(1, limit.size()-2), upper <= lower, false);
        }else{
            return upper * pow(10,(limit.size()-1)/2) +
            lower_palindrome(limit.substr(1, limit.size()-2), upper <= lower, false);
        }
    }
}

bool is_palindrome(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] != s[s.size()-i-1]){
            return false;
        }
    }
    return true;
}

/*int edge(string s){
    if(s.size()== 1)
        return s[0]-'0'+1;
    if(s.size() == 2){
        return
    }
}*/
int main(){

    freopen("2.in", "r", stdin);
    string s1, s2;
    //cout<<is_palindrome("12");
    while(cin>>s1>>s2){
        long long l_bound = 0;
        //if(s1.size() <= 2)
        l_bound =lower_palindrome(s1, s1[0]-'0' <= s1[s1.size()-1]-'0', true);
        //else{
        if(is_palindrome(s1))
            l_bound--;
        //   l_bound = lower_palindrome(s1, s1[0]-'0' <= s1[s1.size()-1]-'0', true);
        if(s1.size() > 4 && s1[s1.size()-1] == '0')
            l_bound--;

        long long u_bound = 0;
        u_bound = lower_palindrome(s2, s2[0]-'0' <= s2[s2.size()-1]-'0', true);
        if(s2.size() > 4 && s2[s2.size()-1] == '0')
            u_bound--;

        long long total = 0;
        for(int i = s1.size(); i < s2.size(); i++){
            total+= 9*pow(10, (i-1)/2);
        }
        //if(s1== "0")
         //   total+=1;
        //cout<<total<<' ';
        total+=u_bound;
        //cout<<total<<' ';
        total-=l_bound;
        cout<<total<<' '<<l_bound<<' '<<u_bound<<endl;
    }

}
