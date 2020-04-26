//
//  main.cpp
//  FlattenBinaryTree
//
//  Created by adeeb mohammed on 27/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>


// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;
  BinaryTree(int value);
};


// non optimized method
// function for getting the non optimized nodes.
void getNodesInOrder(BinaryTree *node,
              std::vector<BinaryTree*> &nodes){
    if(node != NULL){
        getNodesInOrder(node->left, nodes);
        nodes.push_back(node);
        getNodesInOrder(node->right, nodes);
    }
}

BinaryTree *flattenBinaryTree(BinaryTree *root) {
    std::vector<BinaryTree*> nodes;
    getNodesInOrder(root, nodes);
    for(int i = 0 ; i < nodes.size()-1; i++){
        BinaryTree *leftNode = nodes.at(i);
        BinaryTree *rightNode = nodes.at(i+1);
        leftNode->right = rightNode;
        rightNode->left = leftNode;
    }
    return nodes.at(0);
}

int main(int argc, const char * argv[]) {
    std::cout << "Flatten Binary Tree. Inorder traversal\n";
    return 0;
}
