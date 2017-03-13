#include "BasicTree.h"
#include <string>

/*
	���� Ʈ�� 

	���� ���� Ʈ�� (Complete Binary Tree)
		- �� ������ Ʈ���� ���ʺ��� �������� ä���� �ִ� ���� 
	
	��ȭ ���� Ʈ�� (Full Binary Tree)
		- �� ������ ��� ���� ���̿� ���� 
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
	���ο� ��带 ����
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
	��带 ����
*/
void BinaryTree::destroyNode(LRNode * node)
{
	free(node);
}

/*
	Ʈ���� ����
*/
void BinaryTree::destroyTree(LRNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//	���� ���� Ʈ�� ����
	destroyTree(root->leftChild);

	//	������ ���� Ʈ�� ����
	destroyTree(root->rightChild);

	//	��Ʈ ��� ����
	destroyNode(root);
}

/*
	���� ��ȸ 
	top > left > right
*/
void BinaryTree::preorder(LRNode * node)
{
	if (node == NULL)
	{
		return;
	}
	
	//	��Ʈ ��� ���
	cout << node->data << " ";

	//	���� ���� Ʈ�� ���
	preorder(node->leftChild);

	//	������ ���� Ʈ�� ���
	preorder(node->rightChild);
}

/*
	���� ��ȸ 
	left > top > right
*/
void BinaryTree::inorder(LRNode * node)
{
	if (node == NULL)
	{
		return;
	}

	//	���� ���� Ʈ�� ���
	inorder(node->leftChild);

	//	��Ʈ ��� ���
	cout << node->data << " ";

	//	������ ���� Ʈ�� ���
	inorder(node->rightChild);

}

/*
	���� ��ȸ
	left > right > top
*/
void BinaryTree::postorder(LRNode * node)
{
	if (node == NULL)
	{
		return;
	}

	//	���� ���� Ʈ�� ���
	postorder(node->leftChild);

	//	������ ���� Ʈ�� ���
	postorder(node->rightChild);
	
	//	��Ʈ ��� ���
	cout << node->data << " ";
}

