#include <iostream>
using namespace std;
class Node 
{
   public:
    int data;
    Node *lchild = NULL, *rchild = NULL, *next = NULL;
    Node() 
    {
        lchild = rchild = NULL;
    }
    Node(int data)
     {
        this->data = data;
        lchild = rchild = NULL;
    }
    Node *front = NULL, *rear = NULL;
    /*void traverse() 
    {
        Node *temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }*/
    void enqueue(Node *data) 
    {
        if (data == NULL) 
        {
            cout << "Queue Is Full..!!!" << endl;
        } 
        else 
        {
            if (front == NULL) 
            {
                front = data;
                rear = data;
                front->next = NULL;
                rear->next = NULL;
            }
            else 
            {
                rear->next = data;
                rear = data;
                rear->next = NULL;
            }
        }
    }
    Node *dequeue() 
    {
        Node *p;
        p = front;
        front = front->next;
        return p;
    }
    int isEmpty() 
    {
        return front == NULL;
    }
};
class Tree {
   public:
    Node q;
    Node *root = NULL;
    Node *temp = NULL;
    void createTree() {
        int x;
        cout << "Enter the Root Node Data : ";
        cout << endl;
        cin >> x;
        root = new Node(x);
        q.enqueue(root);
        temp = root;
        while (!q.isEmpty()) {
            temp = q.dequeue();
            cout << "Enter the Left Child of " << temp->data << " : ";
            cout << endl;
            cin >> x;
            if (x != -1) 
            {
                Node *lchild = new Node(x);
                temp->lchild = lchild;
                q.enqueue(lchild);
            }
            cout << "Enter the Right Child of " << temp->data << " : ";
            cout << endl;
            cin >> x;
            if (x != -1) 
            {
                Node *rchild = new Node(x);
                temp->rchild = rchild;
                q.enqueue(rchild);
            }
        }
    }
};
/*void preOrder(Node *t) 
{
    if (t != NULL) 
    {
        cout << t->data <<" ";
        preOrder(t->lchild);
        preOrder(t->rchild);
    }
}
void inOrder(Node *t) 
{
    if (t != NULL) 
    {
        inOrder(t->lchild);
        cout << t->data <<" ";
        inOrder(t->rchild);
    }
}
void postOrder(Node *t) 
{
    if (t != NULL) 
    {
        postOrder(t->lchild);
        postOrder(t->rchild);
        cout << t->data <<" ";
    }
}*/
void LevelOrder(Node *t)
{
    
    Node q;
    Node *root  = t;
    cout<<root->data<<" ";
    q.enqueue(root);
    while(!q.isEmpty())
    {
        root = q.dequeue();
        if(root->lchild)
        {
            cout<<root->lchild->data<<" ";
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            cout<<root->rchild->data<<" 1";
            q.enqueue(root->rchild);
        }
    }
}
int main() 
{
    Tree t;
    t.createTree();
    /*cout<<"Preorder : ";
    preOrder(t.root);
    cout<<"\nInorder : ";
    inOrder(t.root);
    cout<<"\nPostorder : ";
    postOrder(t.root);*/
    LevelOrder(t.root);
    return 0;
}
