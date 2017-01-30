#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char str[] = "almost every programmer should know memset!";
    memset(str, '-', 6);
    printf("%s \n", str);
    memset(str, '0', sizeof(str));
    printf("Decimals: %d %s %f", 100, "aslkdj", 1.23);
    //cout<<"hello"<<endl;
    int i;

    string str1, str2;
    char s[256], s2[258];
    scanf("%s %s", &s, &s2);
    scanf("%d", &i);
    printf("%s %s %d", s, s2, i);
    //printf("%d", i);
}




