#include "BasicTree.h"
#include <string>

/*
	이진 트리 

	완전 이진 트리 (Complete Binary Tree)
		- 잎 노드들이 트리의 왼쪽부터 차곡차곡 채워져 있는 형태 
	
	포화 이진 트리 (Full Binary Tree)
		- 잎 노드들이 모두 같은 깊이에 존재 
*/
BinaryTree::BinaryTree()
{
	cout << "Binary Tree" << endl;

	LRNode * A = createNode('A');	
	LRNode * B = createNode('B');
	LRNode * C = createNode('C');
	LRNode * D = createNode('D');
	LRNode * E = createNode('E');
	LRNode * F = createNode('F');
	LRNode * G = createNode('G');

	A->leftChild = B;
	B->leftChild = C;
	B->rightChild = D;

	A->rightChild = E;
	E->leftChild = F;
	E->rightChild = G;

	cout << "preorder : ";
	preorder(A);
	cout << endl;

	cout << "inorder : ";
	inorder(A);
	cout << endl;

	cout << "postorder : ";
	postorder(A);
	cout << endl;

	destroyTree(A);
}

/*
	새로운 노드를 생성
*/
LRNode * BinaryTree::createNode(NodeData nodeData)
{
	LRNode* newNode = (LRNode*)malloc(sizeof(LRNode));
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->data = nodeData;

	return newNode;
}

/*
	노드를 해제
*/
void BinaryTree::destroyNode(LRNode * node)
{
	free(node);
}

/*
	트리를 해제
*/
void BinaryTree::destroyTree(LRNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//	왼쪽 하위 트리 해제
	destroyTree(root->leftChild);

	//	오른쪽 하위 트리 해제
	destroyTree(root->rightChild);

	//	루트 노드 해제
	destroyNode(root);
}

/*
	전위 순회 
	top > left > right
*/
void BinaryTree::preorder(LRNode * node)
{
	if (node == NULL)
	{
		return;
	}
	
	//	루트 노드 출력
	cout << node->data << " ";

	//	왼쪽 하위 트리 출력
	preorder(node->leftChild);

	//	오른쪽 하위 트리 출력
	preorder(node->rightChild);
}

/*
	중위 순회 
	left > top > right
*/
void BinaryTree::inorder(LRNode * node)
{
	if (node == NULL)
	{
		return;
	}

	//	왼쪽 하위 트리 출력
	inorder(node->leftChild);

	//	루트 노드 출력
	cout << node->data << " ";

	//	오른쪽 하위 트리 출력
	inorder(node->rightChild);

}

/*
	후위 순회
	left > right > top
*/
void BinaryTree::postorder(LRNode * node)
{
	if (node == NULL)
	{
		return;
	}

	//	왼쪽 하위 트리 출력
	postorder(node->leftChild);

	//	오른쪽 하위 트리 출력
	postorder(node->rightChild);
	
	//	루트 노드 출력
	cout << node->data << " ";
}

