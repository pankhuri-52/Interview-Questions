#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
};

void sortedInsert(struct node** head_ref, int data);

void append(struct node** headRef, int newData)
{
	struct node* new_node = new node(newData);
	struct node *last = *headRef;
	
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)last = last->next;
	last->next = new_node;
}

void printList(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<' ';
		temp = temp->next;
	}
	cout<<endl;
}

/* Drier program to test count function*/
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct node* head = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, k);
	    }
	    cin>>k;
	    sortedInsert(&head, k);
	    printList(head);
	}
	return 0;
}
// } Driver Code Ends
/*
structure of the node of the list is as
struct node
{
	int data;
	struct node* next;
	
	node(int x){
	    data = x;
	    next = NULL;
	}
};
*/
void sortedInsert(struct node** head_ref, int data)
{
    node* new_node=new node(data);
    node* temp=*head_ref;
    if(temp==NULL || temp->data>data){
        new_node->next=*head_ref;
        *head_ref=new_node;
    } else {
        node* curr=*head_ref;
        while(curr->next!=NULL && curr->next->data<data){
            curr=curr->next;
        }
        new_node->next=curr->next;
        curr->next=new_node;
    }
}

