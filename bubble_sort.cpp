#include <iostream>
using namespace std;
void bubble_sort(int arr[],int n){
	for(int i=0;i<n;i++){
	   for(int j=i+1;j<n;j++){
		   if(arr[i]>arr[j]){
			   int temp=arr[i];
			   arr[i]=arr[j];
			   arr[j]=temp;
		   }
	   }
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	int k=0;
	for(int i=0;i<n;i++){
	   cin>>arr[i];	
	}
	bubble_sort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
