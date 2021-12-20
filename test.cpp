#include <iostream>
#include <string>
#include <queue>

#include "treeParser.hpp"

std::string bfsTravelsal(TreeNode* root) {
    std::string result = "[";
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        if (node == nullptr) {
            result += "null,";
        } else {
            result += std::to_string(node->val) + ",";
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        }
    }
    if (result == std::string("[null,")) {
        return "[]";
    }
    result[result.size()-1] = ']';
    return result;
}

int test(std::string& rawString) {
    TreeNode* root = nullptr;
    int status = parseLeetCodeBinaryTree(rawString, &root);
    if (status != 0) {
        return status;
    }
    std::string result = bfsTravelsal(root);
    cleanTreeNode(root);
    if (result != rawString) {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "input:  " << rawString << std::endl;
        std::cout << "output: " << result << std::endl;
    }
    return result == rawString ? 0 : -1;
}

std::string testcase[] = {
    "[]",
    "[1]",
    "[1,null,2,3]",
    "[5,1,4,null,null,3,6]",
    "[1,3,null,null,2]",
    "[3,1,4,null,null,2]",
    "[1,2,5,3,4,null,6]",
    "[1,2,5,3,4,null,6,null,null,null,7]",
    "[5,4,8,11,null,13,4,7,2,null,null,null,1]",
    "[1,null,2,null,3,null,4,null,5,null,6]"
};

int main() {
    int status = 0;
    for (int i = 0; i < sizeof(testcase)/sizeof(testcase[0]); i++) {
        status += test(testcase[i]);
    }
    std::cout << "----------------------" << std::endl;
    std::cout << "test fail (" << -status << "/" << sizeof(testcase)/sizeof(testcase[0]) << ")" << std::endl;
    return 0;
}
