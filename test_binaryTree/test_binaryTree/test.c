#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "Queue.h"

typedef char BTDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;

//前序
void PrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//中序
void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//后序
void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
//计算节点个数
int TreeSize(BTNode* root) {
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//计算叶子节点的个数
int TreeLeafSize(BTNode* root) {
	// 如果当前节点为空，返回0
	if (root == NULL) return 0;
	// 如果当前节点是叶子节点（没有子节点），返回1
	if (root->left == NULL && root->right == NULL) return 1;
	// 递归计算左子树和右子树的叶子节点数，并相加
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//二叉树的层序遍历（广度优先遍历)
void LevelOrder(BTNode* root) {
	Queue q;
	QueueInit(&q);
	if (root)QueuePush(&q,root);
	while (!QueueEmpty(&q)) {
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left) {
			QueuePush(&q, front->left);
		}
		if (front->right) {
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestory(&q);
}

int main() {
	//初始化二叉树
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->data = 'A';
	A->left = NULL;
	A->right = NULL;
	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
	B->data = 'B';
	B->left = NULL;
	B->right = NULL;
	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->data = 'C';
	C->left = NULL;
	C->right = NULL;
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->data = 'D';
	D->left = NULL;
	D->right = NULL;
	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->data = 'E';
	E->left = NULL;
	E->right = NULL;
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	//深度优先遍历
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	//计算节点个数
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeSize:%d\n", TreeSize(B));
	//计算叶子节点个数
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	//层序遍历
	LevelOrder(A);
	return 0;
}