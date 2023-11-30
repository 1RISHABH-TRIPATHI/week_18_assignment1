#include<iostream>
#include<vector>
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
void rangeSum(Node * root,int &low,int& high,int &sum)
{
    if(root==NULL) return;
    if(root->val>low) rangeSum(root->left,low,high,sum);
    if(root->val>=low && root->val<=high) sum+=root->val;
    if(root->val<high) rangeSum(root->right,low,high,sum);
}
int rangeSumBST(Node* root, int low, int high) 
{
    int sum=0;
    rangeSum(root,low,high,sum);
    return sum;
}
int main()
{
    Node *a=new Node(40);
    Node *b=new Node(20);
    Node *c=new Node(60);
    Node *d=new Node(15);
    Node *e=new Node(35);
    Node *f=new Node(50);
    Node *g=new Node(70);
    Node *h=new Node(10);
    Node *i=new Node(17);
    Node *j=new Node(18);
    Node *k=new Node(38);
    Node *l=new Node(41);
    Node *m=new Node(55);
    Node *n=new Node(65);
    Node *o=new Node(81);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    d->left=h;
    d->right=i;
    e->left=j;
    e->right=k;
    f->left=l;
    f->right=m;
    g->left=n;
    g->right=o;
    int ans=rangeSumBST(a,30,55);
    return 0;
}