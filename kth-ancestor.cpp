// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


int kthAncestor(Node *root, int k, int node);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int k, node;
     cin>>k>>node;
     cout<<kthAncestor(root, k, node)<<"\n";
  }
  return 0;
}// } Driver Code Ends
//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
#include <queue>
void generateNodes(int ancestors[],Node* root){
    ancestors[root->data]=-1;
    queue<Node*> q;
    q.push(root);
    while(q.empty()==false){
        Node* temp=q.front();
        q.pop();
        if(temp->left){
            ancestors[temp->left->data]=temp->data;
            q.push(temp->left);
        }
        if(temp->right){
            ancestors[temp->right->data]=temp->data;
            q.push(temp->right);
        }
    }
}
static int count1=0;
int countNodes(Node* root){
    if(root==NULL)
     return 0;
    
    countNodes(root->left);
    count1++;
    countNodes(root->right);
    
    return count1;
}
int kthAncestor(Node *root, int k, int node)
{
    int n=countNodes(root);
  int ancestors[n+1]={0};
  generateNodes(ancestors,root);
  int count=0;
  while(node!=-1){
      node=ancestors[node];
      count++;
      
      if(count==k)
        break;
  }
  return node;
}

