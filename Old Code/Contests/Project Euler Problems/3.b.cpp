#include <iostream>
using namespace std;

int main()
{
    int j, counter = 0;

    cin>>j;

    for(int a = 2; a < j; a++){

         for(int k = 2 ; k < a ; k++){

            if(a % k == 0){
                counter = counter+1;}

            if(counter == 0){

            if(j % a == 0){
                cout<< a ;}
        }

    counter = 0;
    }

}
}
