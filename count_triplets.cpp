#include <iostream>
using namespace std;
int countTriplets(int arr[],int n,int x){
	int sum;
	int count=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				sum=(arr[i]+arr[j]+arr[k]);
				if(sum<x)
				 count++;
			}
		}
	}
	return count;
}
int main(){
	int arr[] = {5, 1, 3, 4, 7};
        int n = sizeof arr / sizeof arr[0];
        int sum = 12;
        cout << countTriplets(arr, n, sum) << endl;
        return 0;
}
