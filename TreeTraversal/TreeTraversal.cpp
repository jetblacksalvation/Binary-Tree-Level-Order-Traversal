// TreeTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>

//comment this out when in leetcode
template <typename Iter>
std::string join(const std::vector<int>& sequence,  std::string separator)
{
    std::string result;
    for (size_t i = 0; i < sequence.size(); ++i) {
        char* buffer = new char[10];
        _itoa_s(sequence[i], buffer,10,10);
        std::string str(buffer);

        result += (str + ((i != sequence.size() - 1) ? separator : ""));

    }
    return result;
}


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
struct LayerNode :public TreeNode{
    LayerNode(const TreeNode& TreeNode, int layer) {
        this->val = TreeNode.val;
        this->layer = layer;

    }
    int layer;
};
int main()
{
    TreeNode* tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    
    std::queue<TreeNode*> _Iterator({tree});
   
    int layer = 1;
    int maxLayer = 0;

    std::vector<LayerNode> LayerNodes;

    if(_Iterator.size() >0)
        LayerNodes.emplace_back(std::move(*_Iterator.front()), 0);

    while (_Iterator.size() > 0) {

        TreeNode* node = _Iterator.front();
        //std::cout << node->val<<", ";
        _Iterator.pop();
        if (node->left != nullptr) {
            _Iterator.push(node->left);
            LayerNodes.emplace_back(std::move(*node->left), layer);

        }
            
            
        if (node->right != nullptr) {
            _Iterator.push(node->right);
            LayerNodes.emplace_back(std::move(*node->right), layer);

        }
        if (node->right == nullptr and node->left == nullptr) {

        }
        else {
            layer++;
        }
    }
    maxLayer = layer;
    std::vector<std::vector<int>> ret_vals;
    for (int x = 0; x < maxLayer; x++) {
        ret_vals.push_back({});
    }
    for (int x = 0; x < maxLayer; x++) {
        std::cout << "[";


        std::vector<int> values;

        for (auto& Nodes : LayerNodes) {
            if (Nodes.layer == x) {
                values.push_back( Nodes.val);
            }
        }
        ret_vals[x] = values;
        std::cout << join<std::vector<int>::iterator>(values, ",")<<"]";//comment out in leetcode

    }
    //return ret_vals//uncomment in leetcode
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
