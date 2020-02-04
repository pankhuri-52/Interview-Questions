// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;  
// Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};  


int compare(Node *list1, Node *list2); 


int main()
{
 int t,n;
 cin>>t;
 char x;
 while(t--)
 {
 cin>>n;
 cin>>x;
  Node *list1 = new Node(x);
    Node *temp=list1;
    for(int i=0;i<n-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
		int m;
		cin>>m;
    cin>>x;
    Node *list2 = new Node(x);
    temp=list2;
    for(int i=0;i<m-1;i++){
			cin>>x;
		temp->next = new Node(x);
		temp=temp->next;
		}
 
    cout << compare(list1, list2)<<endl;
    }
    return 0;
}
// } Driver Code Ends
/* Linked list Node structure
struct Node
{
    char c;
    struct Node *next;
    
    Node(char x){
        c = x;
        next = NULL;
    }
    
};
*/

// Compare two strings represented as linked lists
int compare(Node *list1, Node *list2) 
{
    Node* temp1=list1;
    Node* temp2=list2;
    while(temp1!=NULL && temp2!=NULL && temp1->c==temp2->c){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1!=NULL && temp2!=NULL){
        return (temp1->c>temp2->c)?1:-1;
    }
    if(temp1!=NULL && temp2==NULL)
      return 1;
    if(temp1==NULL && temp2!=NULL)
       return -1;
    return 0;
}
