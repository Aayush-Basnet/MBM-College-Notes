#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL; } };
class BinarySearchTree {
private:
    TreeNode* root;
public:
    BinarySearchTree() {
        root = NULL; }
   void insert(int value) {
        root = insertRec(root, value);
    }
   TreeNode* insertRec(TreeNode* node, int value) {
        if (node == NULL) {
            return new TreeNode(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value); }
        return node; }
    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return; }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
     void inorder() {
        inorderTraversal(root);
    }
};
int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    cout << "Inorder traversal of BST: ";
    bst.inorder();
    cout << endl;
    return 0;
}

