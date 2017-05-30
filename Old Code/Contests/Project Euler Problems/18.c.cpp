#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> myprime;
    myprime.push_back(2);
    for(int i=1; i<1000; i++){
        int carry=0;
        for(int k=myprime.size()-1; k>=0; k--){
            if(myprime[k]>=5){
                myprime[k]=(2*myprime[k]+carry)%10;
                carry=1;
            }else{
                myprime[k]=(2*myprime[k]+carry)%10;
                carry=0;
            }
        }
        if(carry==1){
            myprime.insert(myprime.begin(), 1);
        }
    }
    /*for(int i=0; i<myprime.size(); i++){
        cout<<myprime[i];
    }*/
    int sum=0;
    for(int i=0; i<myprime.size(); i++){
        sum+=myprime[i];
    }
    cout<<sum<<endl;
}
