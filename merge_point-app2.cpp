#include <iostream>
#include <set>
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
	int count=0;
	Node* temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}
int getIntersectionNode(Node* head1,Node* head2){
	int m=length(head1);
	int n=length(head2);
	set<Node*> addresses;
	for(int i=0;i<n;i++){
		addresses.insert(head2);
		head2=head2->next;
	}
	for(int i=0;i<m;i++){
		if(addresses.find(head1)!=addresses.end()){
			return head1->data;
			break;
		}
		head1=head1->next;
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
    int temp=getIntersectionNode(head1,head2);
    cout << "The node of intersection is " <<temp;
}
