//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node *h1 = node1, *h2 = node2;
        Node *prev = NULL;
        
        while(h1 && h2){
            if(h1->data <= h2->data){
                prev = h1;
                h1 = h1->next;
            }
            else{
                Node *currNode = h2;
                h2 = h2->next;
                
                if(prev == NULL){
                    node1 = currNode;
                }
                else{
                    prev->next = currNode;
                }
                
                currNode->next = h1;
                prev = currNode;
            }
        }
        
        if(h2){
            if(prev == NULL){
                node1 = h2;
            }
            else{
                prev->next = h2;
            }
            h2 = NULL;
        }
        
        if(!node1){
            return NULL;
        }
        
        prev = NULL;
        Node *nextptr = node1->next;
        
        while(nextptr){
            node1->next = prev;
            prev = node1;
            node1 = nextptr;
            nextptr = nextptr->next;
        }
        
        node1->next = prev;
        return node1;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends
