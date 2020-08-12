#include<iostream>
#include<queue>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        int sum = 0;
        std::queue<TreeNode*> middle;
        if (root) {
            middle.push(root);
            if (root->val <= R && root->val >= L){
                sum += root->val;
            }
        }
        else 
            return 0;
        while (!middle.empty())
        {
            TreeNode *temp = middle.front();
            middle.pop();
            if (temp->left) {
                middle.push(temp->left);
                if (temp->left->val <= R && temp->left->val >= L)
                {
                    sum += temp->left->val;
                }
            }
            if (temp->right) {    
                middle.push(temp->right);
                if (temp->right->val <= R && temp->right->val >= L)
                {
                    sum += temp->right->val;
                }
            }            
        }
        return sum;
    }
};

int main()
{
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(7);
    TreeNode *c = new TreeNode(18);
    TreeNode *d_ab = new TreeNode(5, a, b);
    TreeNode *e_c = new TreeNode(15, NULL, c);
    TreeNode *temp = new TreeNode(10, d_ab, e_c);
    Solution S;
    std::cout << S.rangeSumBST(temp,7,15) << std::endl;
}