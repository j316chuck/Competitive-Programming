#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    class student{
    public:
    string cName;
    int ild;
    int iMathScore;
    };

    student studentA;
    studentA.cName ="Tom";
    studentA.ild = 1;
    studentA.iMathScore = 100;

    student classAstudent[100];
    int iTop score = classAstudent[5].iMathScore;
    if(classAstudent[5].ild==1)
    {
        printf("Name = %s\n", classAstudent[5].cName.c_str());
    }
}
