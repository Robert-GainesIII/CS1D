// C++ program to create a Complete Binary tree from its Linked List 
// Representation 
#include <iostream> 
#include <string> 
#include <queue> 
using namespace std; 
  
// Linked list node 
struct ListNode 
{ 
    int data; 
    ListNode* next; 
}; 
  
// Binary tree node structure 
struct BinaryTreeNode 
{ 
    int data; 
    BinaryTreeNode *left, *right; 
}; 
  
// Function to insert a node at the beginning of the Linked List 
void push(struct ListNode** head_ref, int new_data) 
{ 
    // allocate node and assign data 
    struct ListNode* new_node = new ListNode; 
    new_node->data = new_data; 
  
    // link the old list off the new node 
    new_node->next = (*head_ref); 
  
    // move the head to point to the new node 
    (*head_ref)    = new_node; 
} 
  
// method to create a new binary tree node from the given data 
BinaryTreeNode* newBinaryTreeNode(int data) 
{ 
    BinaryTreeNode *temp = new BinaryTreeNode; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// converts a given linked list representing a complete binary tree into the 
// linked representation of binary tree. 
void convertList2Binary(ListNode *head, BinaryTreeNode* &root) 
{ 
    // queue to store the parent nodes 
    queue<BinaryTreeNode *> q; 
  
    // Base Case 
    if (head == NULL) 
    { 
        root = NULL; // Note that root is passed by reference 
        return; 
    } 
  
    // 1.) The first node is always the root node, and add it to the queue 
    root = newBinaryTreeNode(head->data); 
    q.push(root); 
  
    // advance the pointer to the next node 
    head = head->next; 
  
    // until the end of linked list is reached, do the following steps 
    while (head) 
    { 
        // 2.a) take the parent node from the q and remove it from q 
        BinaryTreeNode* parent = q.front(); 
        q.pop(); 
  
        // 2.c) take next two nodes from the linked list. We will add 
        // them as children of the current parent node in step 2.b. Push them 
        // into the queue so that they will be parents to the future nodes 
        BinaryTreeNode *leftChild = NULL, *rightChild = NULL; 
        leftChild = newBinaryTreeNode(head->data); 
        q.push(leftChild); 
        head = head->next; 
        if (head) 
        { 
            rightChild = newBinaryTreeNode(head->data); 
            q.push(rightChild); 
            head = head->next; 
        } 
  
        // 2.b) assign the left and right children of parent 
        parent->left = leftChild; 
        parent->right = rightChild; 
    } 
} 
  
// Utility function to traverse the binary tree after conversion 
void inorderTraversal(BinaryTreeNode* root) 
{ 
    if (root) 
    { 
        inorderTraversal( root->left ); 
        cout << root->data << " "; 
        inorderTraversal( root->right ); 
    } 
} 

void printPostorder(BinaryTreeNode* node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    printPostorder(node->left); 
  
    // then recur on right subtree 
    printPostorder(node->right); 
  
    // now deal with the node 
    cout << node->data << " "; 
} 

void printPreorder(BinaryTreeNode* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left);  
  
    /* now recur on right subtree */
    printPreorder(node->right); 
}  

int height(BinaryTreeNode* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}

void printGivenLevel(BinaryTreeNode* root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}

void printLevelOrder(BinaryTreeNode* root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
}  


  
// Driver program to test above functions 
int main() 
{ 

    cout << "Assigment 4 CS1D Mondays/Wednesdays" << endl;
    cout << "Due Date: September 30, 2019" << endl;
    cout << "Description: Implement a binary tree using an array, vector or linked list." << endl
         << "Perform the in-order, post-order, pre-order, breadth-first traversals."<< endl
         << "In addition to the traversals, print out the binary tree by level.\n"
         << "Show the parent-child relationship for all the nodes of the tree." << endl << endl;
    int data[] = {19, 13, 888, 109, 55, 118, 89, 33, 1001, 18, 44, 88, 12, 24, 49, 7, 25, 59, 28};
	struct ListNode* head = NULL;
    push(&head, 28);
    push(&head, 59);
    push(&head, 25);
    push(&head, 7);
    push(&head, 49);
    push(&head, 24);
    push(&head, 12);
    push(&head, 88);
    push(&head, 44);
    push(&head, 18);
    push(&head, 1001);
    push(&head, 33);
    push(&head, 89);
    push(&head, 118);
    push(&head, 55);
    push(&head, 109);
    push(&head, 888);
    push(&head, 13);
    push(&head, 19);
    // create a linked list shown in above diagram  
  
    BinaryTreeNode *root; 
    convertList2Binary(head, root); 
  
    cout << "Inorder Traversal of the constructed Binary Tree is: \n"; 
    inorderTraversal(root); 
    cout << endl << "Post Order: \n";
    printPostorder(root);
    cout << endl << "Pre order:  \n";
    printPreorder(root);
    cout << endl << "By Level: \n";
    printLevelOrder(root);

    return 0; 
}