#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next[2];
		Node(int data){
			this->data=data;
			next[0]=NULL;
			next[1]=NULL;
		}
};
int max_height(Node* root){
	if(root==NULL)
		return 0;
	else{
		int left=max_height(root->next[0]);
		int right=max_height(root->next[1]);
		if(left>right)
			return (left+1);
		else
			return (right+1);
	}
}
Node* construct_binary(int arr[],Node* root,int start,int end){
	if(start>end)
		return NULL;
		root=new Node(arr[start]);
		if(2*start+1<end && arr[2*start+1]!=-1)
			root->next[0]=construct_binary(arr,root->next[0],2*start+1,end);
		if(2*start+2<end && arr[2*start+2]!=-1)
			root->next[1]=construct_binary(arr,root->next[1],2*start+2,end);
	return root;
}
int main(int argc,const char *argv[]){
	int arr[argc];
	int k=0;
	for(int i=1;i<argc;i++){
		arr[k++]=atoi(argv[i]);
	}
	Node* root=construct_binary(arr,root,0,argc-1);
	int height=max_height(root);
	cout<<height;
	return 0;
}
