void reverse(){
   Node* curr=head;
   Node* Prev=NULL;
   Node* Next=NULL;
   while(curr!=NULL){
      Prev=curr->next;
      curr->next=Next;
      Prev=curr;
      curr=Next;
   }
   head=Prev;
}
