#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* prev, *next;
};

struct Node* getNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

struct Node* newNode(struct Node* head,int data){
	 struct Node *p,*temp= (struct Node*)malloc(sizeof(struct Node));
	 temp->data=data;
	 temp->next=NULL;
	 temp->prev=NULL;
	 if(head ==NULL)
	 return temp;
	 p=head;
	 while(p->next!=NULL){
	 p=p->next;}
	 p->next=temp;
	 temp->prev=p;
	 return head; 
}

void printList(struct Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

void sortedInsert(struct Node** head_ref, struct Node* newNode);

int main()
{
    int t;
    cin>>t;
    while(t--){
        struct Node* head = NULL;
	    struct Node* new_node = NULL;
	    int n, tmp, x;
	    cin>>n;
	    while(n--){
	        cin>>tmp;
	        head=newNode(head, tmp);
	    }
	    cin>>x;
	    sortedInsert(&head, getNode(x));
	    printList(head);
	    cout<<'\n';
    }
	return 0;
}
// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
	int data;
	struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
void sortedInsert(struct Node** head_ref, struct Node* newNode)
{
	Node* temp=*head_ref;
	if(temp==NULL || temp->data>newNode->data){
	    newNode->next=*head_ref;
	    *head_ref=newNode;
	} else {
	    Node* curr=temp;
	    while(curr->next!=NULL && curr->data<newNode->data){
	        curr=curr->next;
	    }
	    if(curr->next!=NULL){
	    curr->prev->next=newNode;
	    newNode->next=curr;
	    }
	      if(curr->next==NULL && curr->data<=newNode->data)
	    {
	        curr->next=newNode;
	        newNode=curr->next;
	        newNode->next=NULL;
	    }
	    if(curr->next==NULL && curr->data>newNode->data){
	        curr->prev->next=newNode;
	        newNode->next=curr;
	    }
	    //curr->next=newNode;
	}
}
