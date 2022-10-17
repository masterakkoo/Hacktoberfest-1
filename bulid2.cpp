#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};
int search(int in[], int str, int end, int curr)
{
    for (int i = str; i <= end; i++)
    {
        if (curr == in[i])
            return i;
    }
    return -1;
}
Node *solve(int in[], int post[], int str, int end, int n)
{
    static int ind = n;

    if (end < str||end>n)
        return NULL;
    int curr = post[ind];
    Node *node = new Node(curr);
    ind--;
    if (str == end)
        return node;
    int pos = search(in, str, end, curr);
    node->right = solve(in, post, pos + 1, end,n);
    node->left = solve(in, post, str, pos - 1,n);
    return node;
}
void preorder(Node *root)
{
    if(root == NULL)
    {
      return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int n = 5;
    int post[] = {4, 2, 5, 3, 1};
    int in[] = {4, 2, 1, 5, 3};
    int str = 0;
    int end = n - 1;
    Node *root = solve(in,post, str, end, n - 1);
    
    preorder(root);
    return 0;
}