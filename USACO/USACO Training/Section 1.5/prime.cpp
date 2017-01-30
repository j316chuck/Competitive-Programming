#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int counter=1; //the count for the Nth prime that you are on
		//counter is 1 because I already counted 2
		int check=3; //check is the number that you are evaluating to be prime or not prime
		bool prime;
		while(counter!=N+1){
            prime=true;
			for(int i=2; i<=sqrt(check); i++){
				if(check%i==0){
                    prime=false;
                    break;
				}
			}
            if(prime==true&&counter!=N){
                counter++;
                //cout<<check<<' '<<counter<<endl;

            }
            if(prime==true&&counter==N){
                cout<<check<<endl;
                counter++;
            }
			check++;
		}
}
