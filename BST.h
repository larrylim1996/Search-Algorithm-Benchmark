#pragma once

#include <iostream>

class BSTNode {
public:
	int data;
	BSTNode* left;
	BSTNode* right;


	//BSTNode();
	BSTNode(int data);
	BSTNode* Insertion(BSTNode* root, int data);
	void preOrderTraversal(BSTNode* root);
	BSTNode* deletion(BSTNode* root, int data);
};
/*
BSTNode::BSTNode() {
	this->data = 0;
	this->left = nullptr;
	this->right = nullptr;
}*/

BSTNode::BSTNode(int data) {
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}

BSTNode* BSTNode::Insertion(BSTNode* root, int data) {
	if (root == nullptr) {
		return new BSTNode(data);
		
	}

	if (data > root->data) {
		root->right = Insertion(root->right, data);
	}

	else {
		root->left = Insertion(root->left, data);
	}

	return root;
}

#pragma warning (push)
#pragma warning(disable: WarningCode)

void BSTNode::preOrderTraversal(BSTNode* root) {
	if (root == nullptr) {
		return;
	}
	std::cout << root->data <<" ";

	preOrderTraversal(root->left);
	preOrderTraversal(root->right);

}

#pragma warning(pop)

BSTNode* BSTNode::deletion(BSTNode* root, int data) {
	if (root == nullptr) {
		return root;
	}

	if (root->data > data) {
		root->left = deletion(root->left, data);
	}

	else if (root->data < data) {
		root->right = deletion(root->right, data);
	}

	else {
		if (root->left == nullptr) {
			BSTNode* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			BSTNode* temp = root->left;
			delete root;
			return temp;
		}

		BSTNode* temp = root->right;
		while (temp != nullptr && temp->left != nullptr) {
			temp = temp->left;
		}

		root->data = temp->data;
		root->right = deletion(root->right, temp->data);
	}
	return root;
}
