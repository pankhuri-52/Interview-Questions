#include <iostream>
#include <unordered_map>
using namespace std;
void check(int arr[],int subset[],int m,int n){
    unordered_map<int,int> hm;
    for(int i=0;i<m;i++){
        hm[arr[i]]=1;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(hm[subset[i]]==1){
          flag=1;
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==1)
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t!=0){
	    int m;
	    cin>>m;
	    int n;
	    cin>>n;
	    int arr[m];
	    for(int i=0;i<m;i++){
	        cin>>arr[i];
	    }
	    int subset[n];
	    for(int i=0;i<n;i++){
	        cin>>subset[i];
	    }
	    check(arr,subset,m,n);
	    t--;
	}
	return 0;
}
