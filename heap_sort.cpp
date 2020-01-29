#include <iostream>
using namespace std;
void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void heap_sort(int arr[],int i,int n){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i){
		swap(&arr[largest],&arr[i]);
		heap_sort(arr,largest,n);
	}
}
void heapify(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		heap_sort(arr,i,n);
	}
	for(int i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heap_sort(arr,0,i);
	}

}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	heapify(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
