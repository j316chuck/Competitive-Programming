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

class road{
public:
    int speed;
    double s_x;
    double s_y;
    double e_x;
    double e_y;
};

class bus{
public:
    int num;
    double x;
    double y;
};

vector<road> myroads;
vector<bus> mybus;

double d(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

/*void binarysearch (bus &a){

    double original_x = a.x;
    double original_y = a.y;
    double distance = 100000;
    double s_x, s_y, e_y, e_x, m_x, m_y, top, bottom, middle;
    for(int i = 0; i < myroads.size(); i++){
        s_x = myroads[i].s_x;
        s_y = myroads[i].s_y;
        e_y = myroads[i].e_y;
        e_x = myroads[i].e_x;
        m_x = (s_x + e_x)/2;
        m_y = (e_y + s_y)/2;
        top = d(s_x, s_y, original_x, original_y);
        bottom = d(e_x, e_y, original_x, original_y);
        middle = d(m_x, m_y, original_x, original_y);
        while(top != bottom ){
            if(i == 4){
                printf("top_x: %f top_y: %f bottom_x: %f bottom_y: %f\n", s_x, s_y, e_x, e_y);
                printf("top: %f bottom: %f middle: %f\n", top, bottom, middle);
            }
            if(top > bottom){
                s_x = m_x;
                s_y = m_y;
            }else if(top < bottom){
                e_x = m_x;
                e_y = m_y;
            }
            m_x = (s_x + e_x)/2;
            m_y = (e_y + s_y)/2;
            top = d(s_x, s_y, original_x, original_y);
            bottom = d(m_x, m_y, original_x, original_y);
            middle = d(e_x, e_y, original_x, original_y);

        }
        //cout<<"i: "<<i<<" middle: "<<middle<<"m_x: "<<m_x<<" m_y: "<<m_y<<endl;
        if(middle < distance){
            distance = middle;
            a.num = i;
            a.x = m_x;
            a.y = m_y;
        }
    }
}*/


double slope(double x1, double y1, double x2, double y2){
    return (y1-y2)/(x1-x2);
}
/*void closest(bus &a){
    double original_x = a.x;
    double original_y = a.y;
    double point_x, point_y;
    double distance = 10000;
    double dis;
    double m_x;
    double m_y;
    for(int i = 0; i < myroads.size(); i++){
        if(myroads[i].s_x-myroads[i].e_x!=0){
            double s = slope(myroads[i].s_x, myroads[i].s_y, myroads[i].e_x, myroads[i].e_y);
            //cout<<s<<endl;
            double perpendicular_s = -1/s;
            double x1 = s*(myroads[i].s_x) + original_x/s + original_y-myroads[i].s_y;
            x1 = x1*s/(s*s+1);
            double y1 = s*(x1-myroads[i].s_x) + myroads[i].s_y;
            cout<<i<<' '<<x1<<' '<<y1<<endl;

            double d1 = d(original_x, original_y, myroads[i].s_x, myroads[i].s_y);
            double d2 = d(original_x, original_y, myroads[i].e_x, myroads[i].e_y);
            if((myroads[i].s_x < x1 && myroads[i].e_x < x1) || (myroads[i].s_x > x1 && myroads[i].e_x > x1)){
                    if(d1 < d2){
                        m_x = myroads[i].s_x;
                        m_y = myroads[i].s_y;
                        dis = d1;
                    }else{
                        m_x = myroads[i].e_x;
                        m_y = myroads[i].e_y;
                        dis = d2;
                    }
            }else{
                dis = d(original_x, original_y, x1, y1);
                m_x = x1;
                m_y = y1;
            }
            if(distance > dis){
                distance = dis;
                a.x = m_x;
                a.y = m_y;
                a.num = i;
            }
        }
    }
}*/



int main(){

    freopen("3.in", "r", stdin);
    int N, B;
    cin>>N>>B;
    double pos_x, pos_y;
    cin>>pos_x>>pos_y;
    double start_x, start_y;
    road a, b;
    for(int i = 0; i <= N; i++){
        if(i == 0){
            cin>>a.s_x>>a.s_y;
        }else if(i < N){
            double x, y; int speed;
            cin>>speed>>x>>y;
            a.e_x = x;
            a.e_y = y;
            a.speed = speed;
            myroads.push_back(a);
            a.s_x = x;
            a.s_y = y;
        }else{
            cin>>a.speed>>a.e_x>>a.e_y;
            myroads.push_back(a);
        }
    }

    for(int i = 0; i < B; i++){
        int B_x, B_y;
        cin>>B_x>>B_y;
        bus b;
        b.num = -1;
        b.x = B_x, b.y = B_y;
        mybus.push_back(b);
    }
    /*for(int i = 0; i < mybus.size(); i++){
        cout<<mybus[i].num<<' '<<mybus[i].x<<' '<<mybus[i].y<<endl;
    }
    for(int i = 0; i < myroads.size(); i++){
        cout<<myroads[i].s_x<<' '<<myroads[i].s_y<<' '<<myroads[i].speed<<endl;
    }*/
    for(int i = 0; i < mybus.size(); i++){
        closest(mybus[i]);
        cout<<mybus[i].num<<' '<<mybus[i].x<<' '<<mybus[i].y<<endl;
    }
    bus your_pos;
    your_pos.x = pos_x;
    your_pos.y = pos_y;
    your_pos.num = -1;
    //binarysearch(your_pos);
    closest(your_pos);
    //cout<<your_pos.x<<' '<<your_pos.y<<' '<<your_pos.num<<endl;

    vector<int> result;

    /*for(int i = 0; i < mybus.size(); i++){
        double num = mybus[i].num;
        double res = 0;

        if(num > your_pos.num){
            continue;
        }else if(num < your_pos.num){
            double startx = mybus[i].x;
            double starty = mybus[i].y;
            double endx = myroads[num].e_x;
            double endy = myroads[num].e_y;
            while(num < your_pos.num){
                res+=(d(startx, starty, endx, endy)/myroads[num].speed);
                //cout<<i<<' '<<res<<' '<<startx<<' '<<starty<<' '<<endx<<' '<<endy<<myroads[num].speed<<endl;

                num++;
                startx = myroads[num].s_x;
                starty = myroads[num].s_y;
                endx = myroads[num].e_x;
                endy = myroads[num].e_y;
            }
            cout<<res<<endl;
            //cout<<num<<' '<<your_pos.num<<endl;
        }
        if(num == your_pos.num){
            //cout<<"Hi"<<endl;
            if(mybus[i].num == your_pos.num){
                if(d(mybus[i].x, mybus[i].y, myroads[num].s_x, myroads[num].s_y) < d(your_pos.x, your_pos.y, myroads[num].s_x, myroads[num].s_y))
                    res+=d(mybus[i].x, mybus[i].y, your_pos.x, your_pos.y);
            }else{
                res+=d(myroads[num].s_x, myroads[num].s_y, your_pos.x, your_pos.y)/myroads[num].speed;
            }
        }
        //cout<<res<<endl;
        if(res != 0)
            result.push_back(res+0.5);
    }
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++)
        cout<<result[i]<<endl;
    */
}
