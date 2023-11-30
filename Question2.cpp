#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node(int val)
        {
            this->val=val;
            left=right=NULL;
        }
};
void display(Node * root)
{
    if(root==NULL) return;
    
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);   
}
void helper(Node* root,queue<Node*>&q)
{
    if(root==NULL) return;
    helper(root->left,q);
    q.push(root);
    helper(root->right,q);
}
int kthSmallest(Node* root, int k) {
    queue<Node*>q;
    helper(root,q);
    while(--k) q.pop();
    return q.front()->val;
}
int main()
{
    Node *a=new Node(40);
    Node *b=new Node(20);
    Node *c=new Node(60);
    Node *d=new Node(15);
    a->left=b;
    a->right=c;
    b->right=d;
    int n=kthSmallest(a,1);
    return 0;
}