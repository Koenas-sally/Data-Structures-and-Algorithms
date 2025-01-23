#include <iostream>
using namespace std;

//Definition of a Tree Node
class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST{
public:
    TreeNode* root;
    BST() : root(nullptr) {}

    //Insert a value into the BST
    void insert(int key){
        root = insertRec(root, key);
    }

    TreeNode* insertRec(TreeNode* node, int key){
        if(node == nullptr){
            return new TreeNode(key);
        }
        if(key < node->val){
            node->left = insertRec(node->left, key);
        }
        else{
            node->right = insertRec(node->right, key);
        }
        return node;
    }

    //Search for a value in the BST
    TreeNode* searchNode(TreeNode* node, int key){
        if (node == nullptr || node->val == key) {
            return node;
        }
        if (key > node->val ) {
            return searchNode(node->right, key);
        }
        return searchNode(node->left, key);
    }
    
    //Find the minimum value in the BST
    TreeNode* minValueNode(TreeNode* node){
        TreeNode* current = node;
        while(current && current->left != nullptr){
            current = current->left;
        }
        return current;
    }

    //Delete a value from the BST
    TreeNode* deleteNode(TreeNode* node, int key){
        if(node == nullptr) return node;
        if(key < node->val){
            node->left = deleteNode(node->left, key);
        }else if(key > node->val){
            node->right = deleteNode(node->right, key);
        }else{   
            if(node->left == nullptr){// node with only one child or no child
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }else if(node->right == nullptr){
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(root->right);// node with two children: Get the inorder successor// (smallest in the right subtree)
            node->val = temp->val;//copy the inorder successor's data to this node
            node->right = deleteNode(root->right, temp->val);//delete the inorder successofr
        }
        return node;
    }

    //Find the maximum value in the BST
    TreeNode* maxValueNode(TreeNode* node){
        TreeNode* current = node;
        while(current && current->right != nullptr){
            current = current->right;
        }
        return current;
    }

    //Preorder Traversal
    void preOrder(TreeNode* node){
        if(node){
            cout << node->val << " " << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    //Inorder Traversal
    void inOrder(TreeNode* node){
        if(node){
            inOrder(node->left);
            cout << node->val << " " << endl;
            inOrder(node->right);
        }
    }

    //Postorder Traversal
    void postOrder(TreeNode* node){
        if(node){
            postOrder(node->left);
            postOrder(node->right);
            cout << node->val << " " << endl;
        }
    }


};