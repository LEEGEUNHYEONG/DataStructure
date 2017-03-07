#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{	
	BSTNode* tree = createNode(123);
	BSTNode* node = NULL;

	insertNode(tree, createNode(22));
	insertNode(tree, createNode(9918));
	insertNode(tree, createNode(424));
	insertNode(tree, createNode(17));
	insertNode(tree, createNode(3));

	insertNode(tree, createNode(98));
	insertNode(tree, createNode(34));

	insertNode(tree, createNode(760));
	insertNode(tree, createNode(317));
	insertNode(tree, createNode(1));

	inorderPrinter(tree);
	cout << endl;

	cout << "Remove 98 ..." << endl;
	node = removeNode(tree, NULL, 98);
	destroyNode(node);

	inorderPrinter(tree);
	cout << endl;

	cout << "Insert 111 ... " << endl;
	insertNode(tree, createNode(111));

	inorderPrinter(tree);
	cout << endl;

	destroyTree(tree);
}

/*
	새로운 노드 생성
*/
BSTNode * BinarySearchTree::createNode(Data data)
{
	BSTNode *newNode = new BSTNode();
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;

	return newNode;
}

/*
	노드 삭제
*/
void BinarySearchTree::destroyNode(BSTNode * node)
{
	free(node);
}

/*
	트리 삭제
*/
void BinarySearchTree::destroyTree(BSTNode * tree)
{
	if (tree->right != NULL)		//	현재 노드의 오른쪽 node가 null이 아닌 경우 
	{
		destroyNode(tree->right);	//	현재 노드의 오른쪽 node를 root로 하여 하위 트리를 삭제
	}
	if (tree->left != NULL)			//	현재 노드의 왼쪽 node가 null 이 아닌 경우
	{
		destroyNode(tree->left);	//	현재 노드의 왼쪽 node를 root로 하여 하위 트리를 삭제 
	}
	tree->right = NULL;
	tree->left = NULL;
		
	destroyNode(tree);				//	현재 노드를 삭제
}

/*
	target의 값을 가지는 노드를 검색 함
*/
BSTNode * BinarySearchTree::searchNode(BSTNode * tree, Data target)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if(tree->data < target)				//	현재 노드의 data 값이 target 값 보다 작은 경우, 즉 target 값이 더 큰 경우 
	{
		return searchNode(tree->left, target);	//	현재 노드의 오른쪽 node를 root로 하여 하위 트리에서 검색
	}
	else if (tree->data > target)		//	현재 노드의 data 값이 target 값 보다 큰 경우, 즉 target 값이 더 작은 경우 
	{
		return searchNode(tree->right, target);	//	현재 노드의 왼쪽 node를 root로 하여 하위 트리에서 검색
	}
	else
	{
		return NULL;			//	검색 결과가 없는 경우 
	}
}

/*
	트리 내의 최소값을 검색
*/
BSTNode * BinarySearchTree::searchMinNode(BSTNode * tree)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->left == NULL)		//	넘겨받은 node의 왼쪽 노드가 없다면 해당 노드가 최소값을 가짐
	{
		return tree;
	}
	else
	{
		return searchMinNode(tree->left);	//	넘겨받은 node의 왼쪽 노드에서 최소값을 다시 검색
	}
}

/*
	노드를 삽입
*/
void BinarySearchTree::insertNode(BSTNode * tree, BSTNode * child)
{
	if (tree->data < child->data)			//	parnet가 child 보다 작은 경우
	{
		if (tree->right == NULL)			//	오른쪽 노드가 비어 있는 경우 
		{
			tree->right = child;	
		}
		else
		{
			insertNode(tree->right, child);	//	오른쪽 노드를 루트로 하여 하위 트리에 child를 추가 
		}
	}
	else if (tree->data > child->data)		//	parent가 child 보다 큰 경우 
	{
		if (tree->left == NULL)				//	왼쪽 노드가 비어 있는 경우 
		{
			tree->left = child;	
		}
		else
		{
			insertNode(tree->left, child);	//	왼쪽 노드를 루트로 하여 하위 트리에 child를 추가
		}
	}
}

/*
	!!!
	target의 값을 가지는 node를 삭제 
*/
BSTNode* BinarySearchTree::removeNode(BSTNode * tree, BSTNode * parent, Data target)
{
	BSTNode* removed = NULL;

	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->data > target)		//		노드의 데이터가 target 보다 큰 경우, 왼쪽 노드의 하위 트리에서 검색
	{
		removed = removeNode(tree->left, tree, target);
	}
	else if (tree->data < target)	//		노드의 데이터가 target 보다 작은 경우, 오른쪽 노드의 하위 트리에서 
	{
		removed = removeNode(tree->right, tree, target);
	}
	else							//		노드의 데이터가 target인 경우 
	{
		removed = tree;

		if (tree->left == NULL && tree->right == NULL)	//	현재 노드의 왼쪽, 오른쪽 하위 노드가 존재하지 않는 경우 
		{
			if (parent->left == tree)					//	현재 노드가 부모의 왼쪽 노드인 경우 
			{
				parent->left = NULL;
			} 
			else										//	현재 노드가 부모의 오른쪽 노드인 경우
			{
				parent->right = NULL;
			}
		}
		else
		{
			if (tree->left != NULL && tree->right != NULL)	//	현재 노드의 왼쪽과 오른쪽 노드 모두 존재하는 경우 
			{
				BSTNode* minNode = searchMinNode(tree->right);		//		현재 노드의 오른쪽 하위 트리에서 가장 작은 값을 검색
				minNode = removeNode(tree, NULL, minNode->data);	//		가장 작은 값을 가지는 노드를 삭제 한 뒤 	
				tree->data = minNode->data;							//		가장 작은 값을 가지는 노드를 현재 노드의 위치에 이동시킴
			}
			else											//	현재 노드의 왼쪽과 오른쪽 노드 모두 존재하는 경우가 아닌 경우 
			{
				BSTNode* temp = NULL;								
				if (tree->left != NULL)								//		현재 노드의 왼쪽 노드가 NULL 이 아니면 
				{
					temp = tree->left;								//		왼쪽 하위 노드를 temp 노드로 
				}
				else												//		현재 노드의 왼쪽 노드가 NULL 이라면 
				{
					temp = tree->right;								//		오른쪽 하위 노드를 temp 노드로 
				}

				if (parent->left == tree)					//	현재 노드가 부모 노드의 왼쪽 노드라면 
				{
					parent->left = temp;					//	현재 노드의 하위 노드를 부모 노드의 왼쪽 하위 노드로 이동
				}
				else
				{
					parent->right = temp;					//	현재 노드의 하위 노드를 부모 노드의 오른쪽 하위 노드로 이동 
				}
			}
		}
	}
	return removed;
}

/*
	tree를 inorder로 출력 
*/
void BinarySearchTree::inorderPrinter(BSTNode * tree)
{
	if (tree == NULL)
	{
		return;
	}

	inorderPrinter(tree->left);

	cout << tree->data << " ";

	inorderPrinter(tree->right);
}

