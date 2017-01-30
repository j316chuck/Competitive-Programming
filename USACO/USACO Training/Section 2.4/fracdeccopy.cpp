/*
USER: jack.ne1
LANG: C++
TASK: fracdec
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#define CODE_WORKS true
using namespace std;
ifstream in("fracdec.in");
ofstream out("fracdec.out");

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

void output(string answer){
    if(answer.length() <= 76) out << answer << endl;
    else{
        for(int i = 0; i < answer.length(); i += 76){
            out << answer.substr(i, 76) << endl;
        }
    }
}

int main(){
    int N, D;
    in >> N >> D;
    int R[D];
    memset(R, -1, sizeof(R));

    bool cont = true;
    int n = N % D;
    int r = n % D;
    R[r] = 0;
    string fraction = "";
    while(cont){
        fraction += convertInt(r * 10 / D);
        r = r * 10 % D;
        if(r == 0){
            output(convertInt(N / D) + "." + fraction);
            return 0;
        }
        if(R[r] != -1) cont = false;
        else R[r] = fraction.length();
    }
    fraction = fraction.substr(0, R[r]) + "(" + fraction.substr(R[r], fraction.length()) + ")";
    if(fraction.substr(fraction.length() - 3, 3) == "(0)") fraction = fraction.substr(0, fraction.length() - 3);
    output(convertInt(N / D) + "." + fraction);
}
