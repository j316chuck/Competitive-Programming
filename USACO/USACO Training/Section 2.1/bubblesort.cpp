#include <iostream>
using namespace std;

int main(){
    int arr[10];
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>arr[i];

    for(int i=0; i<N; i++){
       for(int k=0; k<N; k++){
            if(arr[k]>arr[k+1]){
                    int temp=arr[k];
                    arr[k]=arr[k+1];
                    arr[k+1]=temp;

                }
        }
   }
   for(int i=0; i<N; i++)
    cout<<arr[i];
}
