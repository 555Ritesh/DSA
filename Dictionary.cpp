
#include <iostream>
using namespace std;
class node
{

public:
    string keyword;
    string meaning;
    node *left;
    node *right;
};
class BST
{
    node *root;
public:
BST()
{
    root=NULL;
}

    node* insert(node* root,string key,string m){
        if(root==NULL){
            root=new node();
            root->keyword=key;
            root->meaning=m;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        if(key<root->keyword){
            root->left=insert(root->left,key,m);
            return root;
        }
        else{
           root->right=insert(root->right,key,m); 
           return root;
        }
    }
    node* create(node* root){
        string k;
        string M;
        cout<<"Enter the keyword(if not enter NO)"<<endl;
        cin>>k;
        cout<<"Enter the meaning:"<<endl;
        cin>>M;
        while(k!="NO" && M!="NO"){
            root=insert(root,k,M);
            cout<<"Enter the keyword(if not enter NO)"<<endl;
            cin>>k;
            cout<<"Enter the meaning:"<<endl;
            cin>>M;
        }
        return root;
    }
     void inOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout<<root->keyword<<":"<<root->meaning<<" ";
        inOrder(root->right);
    }
     node* search(node *root, string keyW)
    {

        if (root == NULL)
            return NULL;
        if (root->keyword == keyW)
            return root;

        if (root->keyword < keyW)
            return search(root->right, keyW);

        else
        {

            return search(root->left, keyW);
        }
    }
   void update(node* root){
            
            node* p;
            string k;
            string m;
            string nMeaning;
            cout<<"Enter key to update :"<<endl;
            cin>>k;
            p=search(root, k);
            if (p == NULL)
                cout << "\nElement not present in BST";
            else
            {
                cout<<"Enter NEW MEANING : "<<endl;
                cin>>nMeaning;
                p->meaning=nMeaning;
            }
   }
    
    void menu()
    {
        int ch;
         while(1)
         {
        cout << "\nEnter a choice:1.Create 2.Display3.Update4.Exit";
        cin >> ch;
        switch (ch)
        {
        case 1:
            root=create(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            update(root);
            break;
        case 4:
            exit(1);
        }
    }
    }
};
int main(){
    BST b;
    b.menu();
    return 0;
   
}