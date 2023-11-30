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
Node * helper(vector<int>&v,int lo,int hi)
{
    if(lo>hi) return NULL;
    int mid=lo+(hi-lo)/2;
    Node* temp=new Node(v[mid]);
    temp->left=helper(v,lo,mid-1);
    temp->right=helper(v,mid+1,hi);
    return temp;
}
void convertVector(Node* root,vector<int>&v)
{
    if(root==NULL) return;
    convertVector(root->left,v);
    v.push_back(root->val);
    convertVector(root->right,v);
}
Node* balanceBST(Node* root) {
    vector<int>v;
    convertVector(root,v);
    int n=v.size();
    return  helper(v,0,n-1);
}
int main()
{
    Node *a=new Node(40);
    Node *b=new Node(20);
    Node *c=new Node(60);
    Node *d=new Node(15);
    Node *e=new Node(35);
    a->right=b;
    b->right=c;
    c->right=d;
    d->right=e;
    Node *root=balanceBST(a);
    return 0;
}