/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution 
{
public:
    static void printTree(TreeNode* node, int depth=0)
    {
	if (!node)
	{
	    return;
	}
	printTree(node->left, depth+1);
	std::cout << node->val << " depth: " << depth << " " << node <<std::endl;
	printTree(node->right,depth+1);

    }
    
    static TreeNode* copyTree(TreeNode* node)
    {
	if (!node)
	{
	    return nullptr;
	}
	TreeNode* copy = new TreeNode(*node);
	copy->left = copyTree(node->left);
	copy->right = copyTree(node->right);
	return copy;
    }

    static std::vector<TreeNode*> permuteTree(TreeNode* head, int n)
    {
	std::vector<TreeNode*> nodes;
	TreeNode* tree = head;
	TreeNode* newTree = new TreeNode(n);
	newTree->left=tree;
	nodes.push_back(newTree);
	size_t inc = 0;
	
	while (tree)
	{
	    TreeNode* bottomTree = tree->right;
	    tree->right = nullptr;
	    newTree = copyTree(head);
	    tree->right = bottomTree;
	    TreeNode* newTreeRight = newTree;
	    for (size_t i=0; i!=inc; ++i) {
		newTreeRight=newTreeRight->right;
	    }
	    newTreeRight->right = new TreeNode(n);
	    newTreeRight->right->left = bottomTree;
	    tree = tree->right;
	    
	    ++inc;
	    nodes.push_back(newTree);
	}
	return nodes;
    }
    
    std::vector<TreeNode*> generateTrees(int n)
    {
	std::vector<TreeNode*> nodes;
        if (n==1)
        {
            nodes.push_back(new TreeNode(1));
            return nodes;
        }
        auto subTrees = generateTrees(n-1);
        for (auto subTree : subTrees)
        {
	    auto temp = permuteTree(subTree, n);
	    nodes.insert(nodes.end(), temp.begin(), temp.end());
        }
        return nodes;
    }
};


//int main(int argc, char** argv)
//{
//    Solution solution;
//    
//    auto trees = solution.generateTrees(1);
//    for (const auto& sub : trees)
//    {
//	Solution::printTree(sub);
//	std::cout << std::endl;
//    }
//    
//    return 0;
//}
