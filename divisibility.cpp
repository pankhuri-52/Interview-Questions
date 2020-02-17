#include <iostream>
using namespace std;
void divisible(int arr[],int n){
    for(int i=0;i<n;i++){
       if(arr[i]%3==0 && arr[i+1]%3==0){
           arr[i]=arr[i]+arr[i+1];
             for(int j=i+1;j<n;j++){
                 arr[j]=arr[j+1];
             }
             n--;
             i--;
       }
   }
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    divisible(arr,n);
    return 0;
}
