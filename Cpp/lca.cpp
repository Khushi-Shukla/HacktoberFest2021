#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

bool getPath(Node* root, Node* target, vector<Node*>& path){
    if(root==NULL)
        return false;
    
    path.push_back(root);
    if(root==target)
        return true;
    
    if(getPath(root->left, target, path) || getPath(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}

Node* LCA(Node* root, Node* p, Node* q){
    vector<Node*> path1, path2;
    if(root==NULL)
    return NULL;

    if(!getPath(root, p, path1) || !getPath(root, q, path2))
    return NULL;

    int pc=0;
    for(pc=0;pc<path1.size() && pc<path2.size();pc++){
        if(path1[pc]!=path2[pc])
            break;
    }
    return path1[pc-1];
}

Node* LCA2(Node* root, Node* p, Node* q) {
       if(root==NULL)
           return NULL;
        if(root==p || root==q)
            return root;
        Node* leftLCA = LCA2(root->left, p, q);
        
        Node* rightLCA = LCA2(root->right, p, q);
        if(leftLCA && rightLCA)
            return root;
        if(leftLCA) 
            return leftLCA;
        return rightLCA;
    }

    /*
            2
          /   \
         4     3
       /  \   /  \
      5    6  7   9
       \
        13
        /
       101

    */

    int main(){
    Node* root=new Node(2);
    root->left=new Node(4);
    root->right=new Node(3);
    root->left->left=new Node(5);
    root->left->right=new Node(6);
    root->left->left->right=new Node(13);
    root->left->left->right->left=new Node(101);

    root->right->left=new Node(7);
    root->right->right=new Node(9);

    
    Node* ans1= LCA(root, root->left->right,  root->left->left->right);
    //Node* ans2=LCA2(root, root->left,  root->right);
    
    if(ans1==NULL )
    cout<<"Lowest Common Ancestor doesn't exist"<<endl;
    else
    cout<<"LCA: "<<ans1->data<<endl;
    return 0;
}
