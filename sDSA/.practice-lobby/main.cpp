#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> levelOrderResult(1);
      queue<TreeNode*> qq;
      qq.push(root);

      int level = 0;
      TreeNode* levelLimit = root;

      while(!qq.empty()){
        TreeNode* currNode = qq.front(); qq.pop();
        levelOrderResult[level].push_back(currNode->val);

        if(currNode == levelLimit){
          level++;
          levelOrderResult.resize(levelOrderResult.size()+1);
        }
      }
    }
};
