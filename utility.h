/*************************************************************************
  > File Name: utility.h
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Mon 15 Dec 2014 02:30:41 PM CST
 ************************************************************************/
#ifndef _UTILITY_H_
#define _UTILITY_H_
#include "CPP.h"
using namespace std;
template<typename T> 
void print1DVector(std::vector<T> v);

template<typename T> 
void print2DVector(std::vector<std::vector<T> > v);

template<typename T> 
void print1DArray(T *a, int n);

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void printSinglyLinkedList(ListNode *head); 

void deleteSinglyLinkedList(ListNode *head); 

ListNode *createSinglyLinkedList(); 

#include "utility.tpp"

#endif
