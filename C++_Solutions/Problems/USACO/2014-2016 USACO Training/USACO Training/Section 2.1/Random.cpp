#include <iostream>
using namespace std;

int main(){
    int myarray[100];
    int N=10;
    for(int i=0; i<2; i++){
        for(int k=0; k<2; k++){
            for(int j=0; j<2; j++){
                for(int l=0; l<2; l++){
                    cout<<i<<' '<<k<<' '<<j<<' '<<l<<endl;

                    for(int m=0; m<N; m++){
                        myarray[m]=1;
                    }
                    if(i==1){
                        for(int m=0; m<N; m++){
                            if(myarray[i]==1)
                                myarray[i]=0;
                            else if(myarray[i]==0)
                                myarray[i]=1;
                        }
                    }
                    if(k==1){
                        for(int m=0; m<N; m++){
                            if(m%2==0){
                                if(myarray[i]==1)
                                    myarray[i]=0;
                                else if(myarray[i]==0)
                                    myarray[i]=1;
                            }
                        }
                    }
                    if(j==1){
                        for(int m=0; m<N; m++){
                            if(m%2==1){
                                if(myarray[i]==1)
                                    myarray[i]=0;
                                else if(myarray[i]==0)
                                    myarray[i]=1;
                            }
                        }
                    }
                    if(l==1){
                        for(int m=0; m<N; m++){
                            cout<<myarray[i];
                            if(m%3==0){
                                if(myarray[i]==1)
                                    myarray[i]=0;
                                else if(myarray[i]==0)
                                    myarray[i]=1;
                            }
                            cout<<myarray[i]<<' ';
                        }//cout<<endl;
                    }
                    cout<<endl;
                }
            }
        }
    }
}
