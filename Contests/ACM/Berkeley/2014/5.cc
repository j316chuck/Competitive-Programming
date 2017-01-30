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

int num_cards(string s){
   if(s[1] == 'T')
        return 1;
    else if(s[1] == 'J')
        return 1;
    else if(s[1] == 'Q')
        return 2;
    else if(s[1] == 'K')
        return 3;
    else if(s[1] == 'A')
        return 4;
    else
        return 1;
}

bool is_penalty(string s){
    if(s[1] == 'J'|| s[1] == 'Q'||s[1] == 'K'|| s[1] == 'A')
        return true;
    else
        return false;
}

int main(){
    /*
    Using Queues to implement
    queue.push_back(s);
    */
    freopen("5.in", "r", stdin);
    //freopen("5.out", "w", stdout);

    string s;
    vector<string> first;
    vector<string> second;

    while(cin>>s){
        second.clear();
        first.clear();
        /*for(int i = 0; i < 26; i++){
            if(i==0){
                first.push_back(s);
                cin>>s;
                second.push_back(s);
                continue;
            }
            cin>>s;
            first.push_back(s);
            cin>>s;
            second.push_back(s);
        }*/
        first.push_back(s);
        for(int i = 0; i < 25; i++){
            cin>>s;
            first.push_back(s);
        }
        for(int i = 0; i < 26; i++){
            cin>>s;
            second.push_back(s);
        }
        //reverse(first.begin(), first.end());
        //reverse(second.begin(), second.end());
        /*for(int i = 0; i < 26; i++)
            cout<<first[i]<<' ';
        cout<<endl;
        cout<<endl;
        for(int i = 0; i < 26; i++)
            cout<<second[i]<<' ';
        cout<<endl;
        cout<<endl;*/

        int turn = 1;
        vector<string> deck;
        int counter1 = 1;
        int counter2 = 0;
        bool penalty = false;
        //cout<<is_penalty(first[0])<<is_penalty(first[1])<<endl;
        //cout<<num_cards(first[0])<<num_cards(first[1])<<endl;

        //three cases
        //1. if you play a penalty: then it becomes penalty time his turn instantly he is penalty
        //2. if you fail to play a penalty when it is penalty it is your turn again you take the cards
        //3. normal play continue adding to deck

        //int iteration = 0;
        while(1){
            if(first.empty() && turn == 1){
                cout<<second.size()<<endl;
                break;
            }else if(second.empty() && turn ==2){
                cout<<first.size()<<endl;
                break;
            }
            /*cout<<"NUMBER "<<iteration++<<endl;
            cout<<"TURN "<<turn<<endl;
            cout<<"SECOND SIZE: "<<second.size()<<" FIRST SIZE: "<<first.size()<<" DECK SIZE: "<<deck.size()<<endl;
            for(int i = 0; i < deck.size(); i++){
                cout<<deck[i]<<' ';
            }cout<<endl;
            cout<<endl;*/
            if(turn == 1){
                while(counter1!=0){
                    if(first.empty())
                        break;
                    else{
                        counter1--;
                        string top = first[0];
                        deck.push_back(top);
                        first.erase(first.begin());

                        if(is_penalty(top)){
                            counter1 = 0;
                            counter2 = num_cards(top);
                            turn = 2;
                            penalty = true;
                        }else if(penalty == true && counter1 == 0){
                            for(int i = 0; i < deck.size(); i++)
                                second.push_back(deck[i]);
                            deck.clear();
                            penalty = false;
                            turn = 2;
                            counter1 = 0;
                            counter2 = 1;
                            break;
                        }else if(penalty == true && counter1 != 0){
                            continue;
                        }else if(penalty == false){
                            counter2 = 1;
                            counter1 = 0;
                            turn = 2;
                        }
                    }
                }
            }else if(turn == 2){
                while(counter2!=0){
                    if(second.empty()){
                        break;
                    }else{
                        counter2--;
                        string top = second[0];
                        deck.push_back(top);
                        second.erase(second.begin());
                        if(is_penalty(top)){
                            counter2 = 0;
                            counter1 = num_cards(top);
                            turn = 1;
                            penalty = true;
                        }else if(penalty == true && counter2 == 0){
                            for(int i = 0; i < deck.size(); i++)
                                first.push_back(deck[i]);
                            deck.clear();
                            penalty = false;
                            turn = 1;
                            counter1 = 1;
                            counter2 = 0;
                            break;
                        }else if(penalty == true  && counter1 != 0){
                            continue;
                        }else if(penalty == false){
                            counter2 = 0;
                            counter1 = 1;
                            turn = 1;
                        }
                    }
                }
            }
        }
    }
    exit(0);
}
