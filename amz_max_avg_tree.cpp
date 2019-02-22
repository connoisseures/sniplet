/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

struct NodeResult {
    int sum;
    int cnt;
    NodeResult(int s = 0, int c = 0): sum(s), cnt(c) {}
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        if (!root) return root;
        TreeNode* max_sub_root = NULL;
        NodeResult MaxResult;
        helper(root, max_sub_root, MaxResult);
        return max_sub_root;
    }
    
    NodeResult helper(TreeNode* root, TreeNode* &max_sub_root, NodeResult &MaxResult) {
       if (!root) return NodeResult();
       NodeResult left = helper(root->left, max_sub_root, MaxResult);
       NodeResult right = helper(root->right, max_sub_root, MaxResult);
       int sum = left.sum + right.sum + root->val;
       int cnt = left.cnt + right.cnt + 1;
       NodeResult crt = NodeResult(sum, cnt);
       if (MaxResult.sum * cnt <= sum * MaxResult.cnt) {
           max_sub_root = root;
           MaxResult = crt;
       }
       return crt;
    }
};
