#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		/*Node(int data){
			this->data=data;
			next=NULL;
		}*/
};
Node* insertion(Node* head,int new_data){
	Node* temp=head;
	Node* new_node=new Node;
	new_node->data=new_data;
	new_node->next=NULL;
	if(head==NULL)
		return new_node;
	while(temp!=NULL){
		Node* curr=temp;
		Node* Next=temp->next;
		if(Next->data>new_data){
			curr->next=new_node;
			new_node->next=Next;
			break;
		}
		temp=temp->next;
	}
	return head;
}
void print_list(Node* head){
	Node* temp=head;
	if(head==NULL)
		return;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main(int argc,const char *argv[]){
      int n=atoi(argv[1]);
        Node* node[n];
        for(int i=0;i<n;i++){
                node[i]=NULL;
                node[i]=new Node;
        }
        int j=0;
        node[j]->data=atoi(argv[2]);
        node[j]->next=node[j+1];
        j++;
        for(int i=3;i<argc;i++){
                node[j]->data=atoi(argv[i]);
                node[j]->next=node[j+1];
                j++;
        }
        node[n-1]->data=atoi(argv[argc-1]);
        node[n-1]->next=NULL;
        Node* head=node[0];
       Node* head1=insertion(head,9);
        print_list(head1);

    return 0;
}
