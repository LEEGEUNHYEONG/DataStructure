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
	���ο� ��� ����
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
	��� ����
*/
void BinarySearchTree::destroyNode(BSTNode * node)
{
	free(node);
}

/*
	Ʈ�� ����
*/
void BinarySearchTree::destroyTree(BSTNode * tree)
{
	if (tree->right != NULL)		//	���� ����� ������ node�� null�� �ƴ� ��� 
	{
		destroyNode(tree->right);	//	���� ����� ������ node�� root�� �Ͽ� ���� Ʈ���� ����
	}
	if (tree->left != NULL)			//	���� ����� ���� node�� null �� �ƴ� ���
	{
		destroyNode(tree->left);	//	���� ����� ���� node�� root�� �Ͽ� ���� Ʈ���� ���� 
	}
	tree->right = NULL;
	tree->left = NULL;
		
	destroyNode(tree);				//	���� ��带 ����
}

/*
	target�� ���� ������ ��带 �˻� ��
*/
BSTNode * BinarySearchTree::searchNode(BSTNode * tree, Data target)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if(tree->data < target)				//	���� ����� data ���� target �� ���� ���� ���, �� target ���� �� ū ��� 
	{
		return searchNode(tree->left, target);	//	���� ����� ������ node�� root�� �Ͽ� ���� Ʈ������ �˻�
	}
	else if (tree->data > target)		//	���� ����� data ���� target �� ���� ū ���, �� target ���� �� ���� ��� 
	{
		return searchNode(tree->right, target);	//	���� ����� ���� node�� root�� �Ͽ� ���� Ʈ������ �˻�
	}
	else
	{
		return NULL;			//	�˻� ����� ���� ��� 
	}
}

/*
	Ʈ�� ���� �ּҰ��� �˻�
*/
BSTNode * BinarySearchTree::searchMinNode(BSTNode * tree)
{
	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->left == NULL)		//	�Ѱܹ��� node�� ���� ��尡 ���ٸ� �ش� ��尡 �ּҰ��� ����
	{
		return tree;
	}
	else
	{
		return searchMinNode(tree->left);	//	�Ѱܹ��� node�� ���� ��忡�� �ּҰ��� �ٽ� �˻�
	}
}

/*
	��带 ����
*/
void BinarySearchTree::insertNode(BSTNode * tree, BSTNode * child)
{
	if (tree->data < child->data)			//	parnet�� child ���� ���� ���
	{
		if (tree->right == NULL)			//	������ ��尡 ��� �ִ� ��� 
		{
			tree->right = child;	
		}
		else
		{
			insertNode(tree->right, child);	//	������ ��带 ��Ʈ�� �Ͽ� ���� Ʈ���� child�� �߰� 
		}
	}
	else if (tree->data > child->data)		//	parent�� child ���� ū ��� 
	{
		if (tree->left == NULL)				//	���� ��尡 ��� �ִ� ��� 
		{
			tree->left = child;	
		}
		else
		{
			insertNode(tree->left, child);	//	���� ��带 ��Ʈ�� �Ͽ� ���� Ʈ���� child�� �߰�
		}
	}
}

/*
	!!!
	target�� ���� ������ node�� ���� 
*/
BSTNode* BinarySearchTree::removeNode(BSTNode * tree, BSTNode * parent, Data target)
{
	BSTNode* removed = NULL;

	if (tree == NULL)
	{
		return NULL;
	}

	if (tree->data > target)		//		����� �����Ͱ� target ���� ū ���, ���� ����� ���� Ʈ������ �˻�
	{
		removed = removeNode(tree->left, tree, target);
	}
	else if (tree->data < target)	//		����� �����Ͱ� target ���� ���� ���, ������ ����� ���� Ʈ������ 
	{
		removed = removeNode(tree->right, tree, target);
	}
	else							//		����� �����Ͱ� target�� ��� 
	{
		removed = tree;

		if (tree->left == NULL && tree->right == NULL)	//	���� ����� ����, ������ ���� ��尡 �������� �ʴ� ��� 
		{
			if (parent->left == tree)					//	���� ��尡 �θ��� ���� ����� ��� 
			{
				parent->left = NULL;
			} 
			else										//	���� ��尡 �θ��� ������ ����� ���
			{
				parent->right = NULL;
			}
		}
		else
		{
			if (tree->left != NULL && tree->right != NULL)	//	���� ����� ���ʰ� ������ ��� ��� �����ϴ� ��� 
			{
				BSTNode* minNode = searchMinNode(tree->right);		//		���� ����� ������ ���� Ʈ������ ���� ���� ���� �˻�
				minNode = removeNode(tree, NULL, minNode->data);	//		���� ���� ���� ������ ��带 ���� �� �� 	
				tree->data = minNode->data;							//		���� ���� ���� ������ ��带 ���� ����� ��ġ�� �̵���Ŵ
			}
			else											//	���� ����� ���ʰ� ������ ��� ��� �����ϴ� ��찡 �ƴ� ��� 
			{
				BSTNode* temp = NULL;								
				if (tree->left != NULL)								//		���� ����� ���� ��尡 NULL �� �ƴϸ� 
				{
					temp = tree->left;								//		���� ���� ��带 temp ���� 
				}
				else												//		���� ����� ���� ��尡 NULL �̶�� 
				{
					temp = tree->right;								//		������ ���� ��带 temp ���� 
				}

				if (parent->left == tree)					//	���� ��尡 �θ� ����� ���� ����� 
				{
					parent->left = temp;					//	���� ����� ���� ��带 �θ� ����� ���� ���� ���� �̵�
				}
				else
				{
					parent->right = temp;					//	���� ����� ���� ��带 �θ� ����� ������ ���� ���� �̵� 
				}
			}
		}
	}
	return removed;
}

/*
	tree�� inorder�� ��� 
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

