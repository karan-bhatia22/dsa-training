#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
struct Node {
    Node * left;
    Node * right;
    int data;
};

struct Tree {
    Node * root;

    Tree(){
        root = NULL;
    }
    void insert(int val)
    {
        if(root == NULL) // tree is empty
        {
            root = new Node();
            root->left = NULL;
            root->right = NULL;
            root->data = val;
        }
        else 
        {
            queue<Node*> q;  // queue to maintain order of nodes in inorder traversal fashion

            q.push(root);
            while(!q.empty())
            {
                Node* temp = q.front();

                if(temp -> left == NULL) // if the left child is empty then there is a spot to insert data
                {
                    temp->left = new Node();
                    temp->left->left = NULL;
                    temp->left->right = NULL;
                    temp->left->data = val;
                    return;
                } 
                else// if the left child is not null then push it to queue and pop the front
                {
                    q.push(temp->left);
                    q.pop();
                }
                if(temp->right == NULL) // if right child is empty the spot to insert data
                {
                    temp->right = new Node();
                    temp->right->left = NULL;
                    temp->right->right = NULL;
                    temp->right->data = val;
                    return;
                }
                else // else push the right child into the queue and pop the front
                {
                    q.push(temp->right);
                    q.pop();
                }
            }

        }
    }

    void preorder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            cout<<root->data<<' ';
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            inorder(root->left);
            cout<<root->data<<' ';
            inorder(root->right);
        }
    }
    void postorder(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        else
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<' ';
        }
    }


    void invert(Node * root)
    {
        if(root == NULL) // if no tree then return
        {
            return;
        }
        invert(root->left); //invert the left subtree
        invert(root->right); //invert the right subtree
        //now exchange left and right subtrees
        Node* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
};
int main()
{
    Tree t;
    int i;
    for(i = 0; i < 5; i ++)
    {
        t.insert(i);
    }
    cout<<"Pre-order traversal before inverting\n";
    t.preorder(t.root);
    cout<<'\n';

    t.invert(t.root);

    cout<<"Pre-order traversal after inverting\n";
    t.preorder(t.root);
    cout<<'\n';
    return 0;
}