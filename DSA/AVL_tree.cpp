#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;
       TreeNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
        height = 1; } };
class AVLTree {
private:
    TreeNode* root;
    int getHeight(TreeNode* node) {
        if (node == NULL) {
            return 0; }
        return getHeight(node->left) - getHeight(node->right); }
    int max(int a, int b) {
        return (a > b) ? a : b; } 
    TreeNode* rotateRight(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x; }
    TreeNode* rotateLeft(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y; }
    TreeNode* insertRec(TreeNode* node, int value) {
        if (node == NULL) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        } else {
            return node; // Duplicate values not allowed
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getHeight(node);
        if (balance > 1 && value < node->left->data) {
            return rotateRight(node); }
        if (balance < -1 && value > node->right->data) {
            return rotateLeft(node); }
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node); }
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node); }
        return node; }
public:
    AVLTree() {
        root = NULL; }
    void insert(int value) {
        root = insertRec(root, value); }
    void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return; }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right); }
    void inorder() {
        inorderTraversal(root); } };
int main() {
    AVLTree avl;
    avl.insert(50);   avl.insert(30);   avl.insert(70);   avl.insert(20);   avl.insert(40);
    cout << "Inorder traversal of AVL tree: ";
    avl.inorder();
    cout << endl;
    return 0; 
}

