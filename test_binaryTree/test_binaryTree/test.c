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

//ǰ��
void PrevOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//����
void InOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}
//����
void PostOrder(BTNode* root) {
	if (root == NULL) {
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}
//����ڵ����
int TreeSize(BTNode* root) {
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}
//����Ҷ�ӽڵ�ĸ���
int TreeLeafSize(BTNode* root) {
	// �����ǰ�ڵ�Ϊ�գ�����0
	if (root == NULL) return 0;
	// �����ǰ�ڵ���Ҷ�ӽڵ㣨û���ӽڵ㣩������1
	if (root->left == NULL && root->right == NULL) return 1;
	// �ݹ��������������������Ҷ�ӽڵ����������
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
//�������Ĳ��������������ȱ���)
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
	//��ʼ��������
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
	//������ȱ���
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	//����ڵ����
	printf("TreeSize:%d\n", TreeSize(A));
	printf("TreeSize:%d\n", TreeSize(B));
	//����Ҷ�ӽڵ����
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	//�������
	LevelOrder(A);
	return 0;
}