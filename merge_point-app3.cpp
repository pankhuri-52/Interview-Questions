#include <iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			next=NULL;
		}
};
int length(Node* head){
        Node* temp=head;
        int count=0;
        while(temp!=NULL){
                count++;
                temp=temp->next;
        }
        return count;
}
int getIntersectionNode(Node* head1,Node* head2){
	int m=length(head1);
	int n=length(head2);
	if(m>n){
		int d=m-n;
		for(int i=0;i<d;i++){
			head1=head1->next;
		}
	}
	if(n>m){
		int d=n-m;
		for(int i=0;i<d;i++){
			head2=head2->next;
		}
	}
	while(head1!=NULL && head2!=NULL){
		if(head1==head2){
			return head1->data;
			break;
		}
		head1=head1->next;
		head2=head2->next;
	}
}
int main(){
	 Node* newNode;
    Node* head1 = new Node(10);

    Node* head2 = new Node(3);

    newNode = new Node(6);
    head2->next = newNode;

    newNode = new Node(9);
    head2->next->next = newNode;

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    cout << "The node of intersection is " << getIntersectionNode(head1, head2);
}
