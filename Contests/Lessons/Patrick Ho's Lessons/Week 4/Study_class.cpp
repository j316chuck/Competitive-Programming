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
#include <cstdlib>

using namespace std;

class student{
public:
    string sName;
    int iMathScore;
    int iArtScore;
    int GetAllScore()
    {
    return iMathScore + iArtScore;
    }
};

int main()
{
    student A;

    A.sName ="Chuck";
    A.iMathScore = -100;
    A.iArtScore = -10000;
    printf("total score of A is %d\n", A.GetAllScore());
}
