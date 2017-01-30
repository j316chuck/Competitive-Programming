//#include "contest.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = 2*acos(0.0);

int main(){

    freopen("8.in", "r", stdin);
    double W, L1, R1, L2, R2;
    while(cin>>W>>L1>>R1>>L2>>R2){
        //cout<<W<<endl;
        //cout<<sin(90*PI/180)<<endl;
        //R1 = negative
        //R2 = negative
        //left sensor = 0 right sensor = w
        //sin((L1-R1))
        double initial_left_side = sin((90+R1)*PI/180)*W/sin((L1-R1)*PI/180);
        double initial_right_side = sin((90-L1)*PI/180)*W/sin((L1-R1)*PI/180);
        double initial_x = cos((90-L1)*PI/180) * initial_left_side;
        double initial_y = sin((90-L1)*PI/180) * initial_left_side;

        double second_left_side = sin((90+R2)*PI/180)*W/sin((L2-R2)*PI/180);
        double second_right_side = sin((90-L2)*PI/180)*W/sin((L2-R2)*PI/180);
        double second_x = cos((90-L2)*PI/180) * second_left_side;
        double second_y = sin((90-L2)*PI/180) * second_left_side;

        double x_distance = initial_x-second_x;
        double y_distance = initial_y-second_y;
        if(y_distance <= 0){
            cout<<"Not approaching"<<endl;
        }else{
            printf("Intersects at x=%.2f, t=%.2f\n", initial_x-x_distance*initial_y/y_distance, initial_y/y_distance);
        }
        //cout<<second_x<<second_y<<endl;
        //cout<<second_left_side<<second_right_side<<endl;
        //cout<<initial_x<<' '<<initial_y<<endl;
        //cout<<left_side<<right_side<<endl;
    }
    exit(0);
}

