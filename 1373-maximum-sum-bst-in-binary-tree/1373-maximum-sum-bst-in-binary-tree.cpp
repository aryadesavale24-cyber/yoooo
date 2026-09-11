class NodeValue {
public:
    int maxnode, minnode;
    int sum;
    int maxSum;

    NodeValue(int minnode, int maxnode, int sum, int maxSum) {
        this->minnode = minnode;
        this->maxnode = maxnode;
        this->sum = sum;
        this->maxSum = maxSum;
    }
};

class Solution {
public:

    NodeValue f(TreeNode* root) {

        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0, 0);
        }

        auto left = f(root->left);
        auto right = f(root->right);

        if (left.maxnode < root->val &&
            right.minnode > root->val) {

            int sum = left.sum + right.sum + root->val;

            return NodeValue(
                min(root->val, left.minnode),
                max(root->val, right.maxnode),
                sum,
                max(sum, max(left.maxSum, right.maxSum))
            );
        }

        return NodeValue(
            INT_MIN,
            INT_MAX,
            0,
            max(left.maxSum, right.maxSum)
        );
    }

    int maxSumBST(TreeNode* root) {
        return f(root).maxSum;
    }
};