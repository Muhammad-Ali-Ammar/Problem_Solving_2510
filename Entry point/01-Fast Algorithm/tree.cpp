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

/************************************************************************************* */

/**
 * traveseInOrder  
 */
void traveseInOrder(TreeNode* root){

  if(root == nullptr) return ; 
  traveseInOrder(root->left);
  cout<<root->val<<"  ";
  traveseInOrder(root->right);
}

/************************************************************************************* */

/**
 * travesePreOrder  
 */
void travesePreOrder(TreeNode* root){

  if(root == nullptr) return ; 
  cout<<root->val<<"  ";
  travesePreOrder(root->left);
  travesePreOrder(root->right);
}

/************************************************************************************* */
/**
 * travesePostOrder  
 */
void travesePostOrder(TreeNode* root){

  if(root == nullptr) return ; 
  
  travesePostOrder(root->left);
  travesePostOrder(root->right);
  cout<<(char)root->val<<"  ";

}

/************************************************************************************* */
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

/************************************************************************************* */
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

/************************************************************************************* */
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

/************************************************************************************* */
/**
 * get Last Node Using   
 */
int lastNodeNas= INT_MIN;
void getLastNodeUsingDFS(TreeNode* root){
  static int curLevel = -1;
  static int maxLevel = -1; 

  if(root == nullptr) return ;  // enpy Tree ... 


  if(root->left==nullptr && root->right==nullptr){ // do leaf
    curLevel++;
    if(curLevel>=maxLevel){
      maxLevel = curLevel;
      lastNodeNas = root->val;
    }
    return ;
  }

    // process 1 
    curLevel++;
    if(curLevel>=maxLevel){
      maxLevel = curLevel;
      lastNodeNas = root->val;
    }
    //go left 
    getLastNodeUsingDFS(root->left);
    // process 2 
    curLevel--;
    // go right 
     getLastNodeUsingDFS(root->right);
    // process 3
    curLevel--;

}

/************************************************************************************* */
/**
 * get Last Node Using   bfs
 */
int getLastNodeUsingBFS(TreeNode* root){

  int ans = INT_MIN;
  if(!root) return ans;
  deque<TreeNode*> dq;
  dq.push_back(root);

  while(dq.empty() == false){

    int n = dq.size();
    ans = dq.back()->val;
    for(int i = 0; i<n; ++i){
      
      if(dq.front()->left) dq.push_back(dq.front()->left);
      if(dq.front()->right) dq.push_back(dq.front()->right);
      dq.pop_front();
    }
  }
  return ans;
}


/*******************************************************************************/

int main() {
  org_root = addBinaryTreeNode(new TreeNode(1));
  org_root = addBinaryTreeNode(new TreeNode(2));
  org_root = addBinaryTreeNode(new TreeNode(3));
  org_root = addBinaryTreeNode(new TreeNode(4));
  org_root = addBinaryTreeNode(new TreeNode(5));


  cout<<getLastNodeUsingBFS(org_root)<<endl;
  return 0;
}
