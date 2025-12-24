#include <bits/stdc++.h>

using namespace std;

/************** Hereeeeeeeee  ***************/
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

TreeNode* org_root = nullptr;

/**************** start Implementation *********************** */
/**
 * addBinaryTreeNode : is for adding note 
 */
queue<TreeNode**> quu;
TreeNode* addBinaryTreeNode(TreeNode* newNode) {
  if (org_root == nullptr) {
    org_root = newNode;
    quu.push(&(org_root->left));
    quu.push(&org_root->right);
    return org_root;
  }

  *(quu.front()) = newNode;
  quu.pop();

  if (newNode != nullptr) {
    quu.push(&newNode->left);
    quu.push(&newNode->right);
  }
  return org_root;
}

/************************************************************************************* */

/**
 * calculate depth 
 */
int calculateDepth_ByNodesNumbers(TreeNode* root){

  if(root == nullptr) return 0;
  if(root->right == nullptr && root->left == nullptr) return 1;

  return 1+ max(calculateDepth_ByNodesNumbers(root->right), calculateDepth_ByNodesNumbers(root->left));
}


/**
 * traveseInOrder  
 */
void traveseInOrder(TreeNode* root){

  if(root == nullptr) return ; 
  traveseInOrder(root->left);
  cout<<root->val<<"  ";
  traveseInOrder(root->right);
}

/**
 * travesePreOrder  
 */
void travesePreOrder(TreeNode* root){

  if(root == nullptr) return ; 
  cout<<root->val<<"  ";
  travesePreOrder(root->left);
  travesePreOrder(root->right);
}


/**
 * travesePostOrder  
 */
void travesePostOrder(TreeNode* root){

  if(root == nullptr) return ; 
  
  travesePostOrder(root->left);
  travesePostOrder(root->right);
  cout<<(char)root->val<<"  ";

}

/**
 * eulerTraverse  
 */
void eulerTraverse(TreeNode* root){

  if(root == nullptr) return ; // if empty
  if(root->right == nullptr && root->left == nullptr){

    // it's leaf 
    cout<<(char)root->val<<"  ";
    return ;
  }

  cout<<root->val<<"  ";
  eulerTraverse(root->left);
  cout<<root->val<<"  ";
  eulerTraverse(root->right);
  cout<<root->val<<"  ";

}

/**
 * eulerTraverseToPrintExprsion 
 */
void eulerTraverseToPrintExprsion(TreeNode* root){

  if(root == nullptr) return ; // if empty
  if(root->right == nullptr && root->left == nullptr){
    
    // it's leaf 
    cout<<root->val;
    return ;
  }

  cout<<"(";
  eulerTraverseToPrintExprsion(root->left);
  cout<<root->val;
  eulerTraverseToPrintExprsion(root->right);
  cout<<")";

}

/**
 * traverseBFS  
 */
void traverseBFS(TreeNode* root){

  // phase one --> push root 
  if(root == nullptr) return ; 
  queue<TreeNode*> qu;
  qu.push(root);

  while(qu.empty() == false){

    int curLevel = qu.size();
    for(int i = 0; i<curLevel;++i){

      auto curNode = qu.front();
      qu.pop();

      cout<<(char)curNode->val<<" ";

      if(curNode->left) qu.push(curNode->left);
      if(curNode->right) qu.push(curNode->right);
    }
  }


}


/*******************************************************************************/

int main() {
  org_root = addBinaryTreeNode(new TreeNode('*'));
  org_root = addBinaryTreeNode(new TreeNode('a'));
  org_root = addBinaryTreeNode(new TreeNode('b'));

  org_root = addBinaryTreeNode(nullptr);
  org_root = addBinaryTreeNode(nullptr);

  eulerTraverseToPrintExprsion(org_root);
  return 0;
}
