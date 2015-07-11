/*
* main.cpp
*
*  Created on: 2015-7-12
*      Author: haoxiaotian
*/
#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (root == p && root == q) return root;
	if (root->val > p->val && root -> val > q->val){
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (root->val < p->val && root->val < q->val){
		return lowestCommonAncestor(root->right, p, q);
	}
	else{
		return root;
	}

}

int main(){
	TreeNode Tree = TreeNode(4);

	TreeNode Tree1L = TreeNode(2);
	TreeNode Tree1R = TreeNode(5);
	TreeNode Tree2LL = TreeNode(1);
	TreeNode Tree2LR = TreeNode(3);

	Tree.left = &Tree1L;
	Tree.right = &Tree1R;

	Tree1L.left = &Tree2LL;
	Tree1L.right = &Tree2LR;

	cout << lowestCommonAncestor(&Tree, &Tree2LL, &Tree2LR)->val << endl;

	return 0;
}



