/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* AC
class Solution {
public:

    void isValidBSTUtils(TreeNode *root, int &prev, bool &result) {
        if(!root or !result) return;
        isValidBSTUtils(root->left, prev, result);
        if(prev >= root->val) {
            result = false;
            return;
        }
        prev = root->val;
        isValidBSTUtils(root->right, prev, result);
    }

    bool isValidBST(TreeNode *root) {
        bool result = true;
        int prev = numeric_limits<int>::min();
        isValidBSTUtils(root, prev, result);
        return result;
    }
};
*/

class Solution {
    bool isValidBSTRecur(TreeNode* root, long min, long max) {
        if(!root) return true;
        if(!(root->val > min && root->val < max)) return false;
        return (isValidBSTRecur(root->left, min, root->val) && isValidBSTRecur(root->right, root->val, max));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecur(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
};