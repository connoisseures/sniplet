#include <iostream>
#include <stack>

using namespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x):val(x),left(NULL), right(NULL){}
};

void dfs_pre_in_order_iterative(TreeNode* root, int order){
        stack<TreeNode*> stk;
        TreeNode* crt=root;
        do{
            while(crt){
                stk.push(crt);
                //preorder
		        if(order==0) cout << crt->val << " ";
                crt=crt->left;
            }
            crt=stk.top();
	        //inorder
	        if(order==1) cout << crt->val << " ";
	        stk.pop();
            crt=crt->right;
        }while(!stk.empty() || crt);
        
}


void dfs_pre_order_iterative(TreeNode* root){
  stack<TreeNode*> stk;
  TreeNode* crt;
  stk.push(root);
  while(!stk.empty()){
    crt=stk.top();
    stk.pop();
    //preorder
    cout << crt->val << " ";
    if(crt->right) stk.push(crt->right);
    if(crt->left)  stk.push(crt->left);
  }
}

int main(int argc, char *argv[]) {
	
	TreeNode* n0 = new TreeNode(0);
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);

		/*
		   0
		/     \
		1      2
		/ \   /  \
		3  4  5   6
		/
		7
		*/

	n0->left = n1;
	n0->right = n2;
	n1->left = n3;
	n1->right = n4;
	n2->left = n5;
	n2->right = n6;
	n3->left = n7;
	n3->right = NULL;
	cout << "preorder" << endl; 
	dfs_pre_in_order_iterative(n0, 0);
	cout << "\ninorder" << endl;
	dfs_pre_in_order_iterative(n0, 1);
	cout << "\npreorder" << endl; 
	dfs_pre_order_iterative(n0);

}
