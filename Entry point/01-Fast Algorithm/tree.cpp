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

/**
 * isSameTree 
 */
 bool isSameTree(TreeNode* p, TreeNode* q) {
     
     if(p == nullptr && q == nullptr) return true;
     if(p == nullptr || q == nullptr ) return false;
     if(p->val != q->val) return false;  // process 1 
     bool okLeft = isSameTree(p->left, q->left);
     bool okRight = isSameTree(p->right, q->right);
     return okLeft & okRight;
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

/************************************************************************************* */
/**
 * calculate the decendants of each node 
 */
int printDecendantsofEachNode(TreeNode* root){

  if(!root) return 0;
  if(root->left == nullptr && root->right == nullptr){
    cout<<"The decendants of "<<root->val <<" is zero" <<endl;
    return 1; 
  }

  int numberOfDecends = printDecendantsofEachNode(root->left) + printDecendantsofEachNode(root->right);
  cout<<"The decendants of "<<root->val <<" is " <<numberOfDecends<<endl;
  return numberOfDecends + 1;

}


TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    
  unordered_map <int,TreeNode*> mp;
  map <int,bool> check;

  for(auto v : descriptions){

    TreeNode* parent = mp.count(v[0])? mp[v[0]] : new TreeNode(v[0]);
    mp[v[0]] = parent;

     TreeNode* child = mp.count(v[1])? mp[v[1]] : new TreeNode(v[1]);
    mp[v[1]] = child;
    check[v[1]] = true;

    if(v[2]) parent->left = child;
    else parent->right = child;
       
  }
  int ans = 0;
  for(auto v : descriptions){
    if(check.count(v[0])) {
      ans = v[0];
      break;
    }
  }

  return mp[ans];

}

/************************************************************************************* */
/************************************************************************************* */
/******************************** BST Part******************************************** */
/************************************************************************************* */
/************************************************************************************* */
/************************************************************************************* */

/************************************************************************************* */
/**
 * get min of BST
 */

int getMinOfBst(TreeNode* root){

  if(!root) return INT_MAX;
  if(root->left == nullptr ){
    return root->val;
  }

  return getMinOfBst(root->left);

}

/************************************************************************************* */
/**
 * isBST
 */

 // min, max
pair<int,int> isBST(TreeNode* root, bool& ans){

  if(!root) return {INT_MAX, INT_MAX};
  if(root->left == nullptr && root->right == nullptr ){
    return {root->val, root->val};
  }

  auto leftValues = isBST(root->left, ans);
  auto rightValues = isBST(root->right, ans);

  ans &= (root->val >= leftValues.second && root->val<rightValues.first);
  return {leftValues.first, rightValues.second};

}
/*******************************************************************************/

int main() {
  org_root = addBinaryTreeNode(new TreeNode(50));
  org_root = addBinaryTreeNode(new TreeNode(40));
  org_root = addBinaryTreeNode(new TreeNode(60));
  org_root = addBinaryTreeNode(new TreeNode(30));
  org_root = addBinaryTreeNode(new TreeNode(45));
  org_root = addBinaryTreeNode(new TreeNode(41));

  bool ans = true; 
  isBST(org_root, ans);

  cout<<ans<<endl;

  return 0;
}
