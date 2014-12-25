/*************************************************************************
  > File Name: utility.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 02:30:34 PM CST
 ************************************************************************/

#include "utility.h"

template <typename T> 
void print1DVector(std::vector<T> v) {
	cout << "sizeof vector:" << v.size() << endl;
	for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
		std::cout << *it << '\t';
	}
	std::cout << std::endl << endl;
}

template <typename T> 
void print2DVector(std::vector<std::vector<T> > v) {
	cout << "sizeof vector:" << v.size() << endl;
	for(typename std::vector<std::vector<T> >::iterator it = v.begin(); it != v.end(); ++it) {
		cout << "sizeof row" << it - v.begin() << ": " << (*it).size() << '\t' << '\t' ;
		for (typename std::vector<T>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt)  
			std::cout << *jt << '\t';
		std::cout << std::endl << endl;
	}
}

template <typename T> 
void print1DArray(T *a, int n) {
	for (int i = 0; i < n; i++)
		std::cout << a[i] << std::endl;
	std::cout << std::endl;
}

void printSinglyLinkedList(ListNode* head) {
	while (head) {
		cout << head->val << '\t';
		head = head->next;
	}
	cout << endl;
}

void deleteSinglyLinkedList(ListNode* head) {
	ListNode *p;
	while (head) {
		p = head;
		head = head->next;
		delete p;
	}
}

ListNode *createSinglyLinkedList() {
	int x;
	ListNode *head = 0, *tail, *node;
	while (cin >> x && x >= 0) {
		node = new ListNode(x);
		if (!head) head = tail = node;
		else {
			tail->next = node;
			tail = tail->next;
		}
	}
	return head;
}

void printBinaryTree(TreeNode *root) {
	if (!root)
		return;
	if (!root->left)
		cout << '#' << ' ';
	else 
		printBinaryTree(root->left);
	cout << root->val << ' '; 
	if (!root->right)
		cout << '#' << ' ';
	else 
		printBinaryTree(root->right);
}

vector<int> serializeBinaryTree(TreeNode *root) {
	vector<int> v;
	if (!root)
		return v;
	queue<TreeNode*> q;
	TreeNode *node;
	q.push(root);
	while (!q.empty()) {
		node = q.front();
		q.pop();
		if (node) {
			v.push_back(node->val);
			q.push(node->left);
			q.push(node->right);
		}
		else 
			v.push_back(INT_MIN);
	}
	while (v[v.size()-1] == INT_MIN)
		v.pop_back();
	return v;
}

