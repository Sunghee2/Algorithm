#include <iostream>
using namespace std;

struct Tree {
    char val;
    Tree *left;
    Tree *right;

    Tree(char c) {
        val = c;
        left = NULL;
        right = NULL;
    }
};

Tree* findTree(Tree *root, char val) {
    // Tree *root;
    if(root == NULL) return NULL;
    if(val == root -> val) return root;
    else {
        if(findTree(root -> left, val) == NULL) findTree(root -> right, val);
    }
    // else {
    //     findTree(root -> left, val);
    //     findTree(root -> right, val);
    // }
}

void createTree(Tree *root, char root_val, char left_val, char right_val) {
    if(root == NULL) {
        root = new Tree(root_val);
        root -> left = (left_val == '.')? NULL : new Tree(left_val);
        root -> right = (right_val == '.')? NULL : new Tree(right_val);
    } else {
        Tree *t = findTree(root, root_val);
        t -> left = (left_val == '.')? NULL : new Tree(left_val);
        t -> right = (right_val == '.')? NULL : new Tree(right_val);
    }
}

void preorder(Tree *root) {
    if(root != NULL) {
        cout << root -> val;
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(Tree *root) {
    if(root != NULL) {
        inorder(root -> left);
        cout << root -> val;
        inorder(root -> right);
    }
}

void postorder(Tree *root) {
    if(root != NULL) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> val;
    }
}

int main() {
    int n;
    cin >> n;

    Tree *tree;
    while(n-- > 0) {
        char val, left, right;
        cin >> val >> left >> right;

        createTree(tree, val, left, right);
    }

    preorder(tree);
    inorder(tree);
    postorder(tree);
}