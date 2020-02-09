// Link on task -> https://www.codewars.com/kata/57e5279b7cf1aea5cf000359
#include <iostream>
#include <algorithm>
using namespace std;

struct bintree_node {
    bintree_node* left = NULL;
    bintree_node* right = NULL;
    int value = 0;
};

int maxSum(bintree_node* root)
{
    if (root == NULL)
        return 0;

    return root->value + max(maxSum(root->left), maxSum(root->right));
}

int main()
{
    bintree_node root;

    root.left = new bintree_node;
    root.left->value = 15;

    root.left->right = new bintree_node;
    root.left->right->value = 25;

    root.right = new bintree_node;
    root.right->value = 30;

    cout << boolalpha << "Test -> " << (maxSum(&root) == 40);

    return 0;
}