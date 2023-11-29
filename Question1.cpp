#include<iostream>
#include<vector>
#include<math.h>
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
int Maximun_Node(Node *root)
{
    if(root==NULL) return INT8_MIN ;
    return max(root->val,max(Maximun_Node(root->left),Maximun_Node(root->right)));
}
int Minimun_Node(Node *root)
{
    if(root==NULL) return INT8_MAX;
    return min(root->val,min(Minimun_Node(root->left),Minimun_Node(root->right)));
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
    display(a);
    int mx=Maximun_Node(a->right);
    mx=max(a->val,mx);
    int mi=Minimun_Node(a->left);
    mi=min(mi,a->val);
    cout<<endl<<mx<<" "<<mi;
    return 0;
}