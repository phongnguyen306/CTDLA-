#include <iostream>
using namespace std;

struct MH
{
	string MAMH;
	string TENMH;
	int STCLT;
	int STCTH;
};

struct DanhSachMonHoc
{
	MH data;
	struct DanhSachMonHoc* leftChild;
	struct DanhSachMonHoc* rightChild;
	int height;
};

int max(int a, int b);

int height(struct DanhSachMonHoc* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

struct DanhSachMonHoc* newNode(MH data)
{
	DanhSachMonHoc* node = new DanhSachMonHoc;
	node->data = data;
	node->leftChild = NULL;
	node->rightChild = NULL;
	node->height = 1;
	return (node);
}

struct DanhSachMonHoc* rightRotate(struct DanhSachMonHoc* y)
{
	struct DanhSachMonHoc* x = y->leftChild;
	struct DanhSachMonHoc* T2 = x->rightChild;
	x->rightChild = y;
	y->leftChild = T2;
	y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
	x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
	return x;
}

struct DanhSachMonHoc* leftRotate(struct DanhSachMonHoc* x)
{
	struct DanhSachMonHoc* y = x->rightChild;
	struct DanhSachMonHoc* T2 = y->leftChild;
	y->leftChild = x;
	x->rightChild = T2;
	x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
	y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
	return y;
}

int getBalance(struct DanhSachMonHoc* N)
{
	if (N == NULL)
		return 0;
	return height(N->leftChild) - height(N->rightChild);
}

DanhSachMonHoc* insertDanhSachMonHoc(DanhSachMonHoc* node, MH data)
{
	if (node == NULL)
		return (newNode(data));

	if (data.MAMH < node->data.MAMH)
		node->leftChild = insertDanhSachMonHoc(node->leftChild, data);

	else if (data.MAMH > node->data.MAMH)
		node->rightChild = insertDanhSachMonHoc(node->rightChild, data);

	else
		return node;

	node->height = 1 + max(height(node->leftChild), height(node->rightChild));

	int balance = getBalance(node);
	if (balance > 1 && data.MAMH < node->leftChild->data.MAMH)
		return rightRotate(node);

	if (balance < -1 && data.MAMH > node->rightChild->data.MAMH)
		return leftRotate(node);

	if (balance > 1 && data.MAMH > node->leftChild->data.MAMH)
	{
		node->leftChild = leftRotate(node->leftChild);
		return rightRotate(node);

	}

	if (balance < -1 && data.MAMH < node->rightChild->data.MAMH)
	{
		node->rightChild = rightRotate(node->rightChild);
		return leftRotate(node);
	}

	return node;
}

struct DanhSachMonHoc* minValueNode(struct DanhSachMonHoc* node)
{
	struct DanhSachMonHoc* current = node;
	while (current->leftChild != NULL)
		current = current->leftChild;

	return current;
}

DanhSachMonHoc* TimKiemTheoMAMH(DanhSachMonHoc* root, string MAMH) 
{
  	if (root == nullptr) 
	{
    	return nullptr;
  	}

  	if (MAMH == root->data.MAMH) 
	{
    	return root;
  	} 
	else if (MAMH < root->data.MAMH) 
	{
    	return TimKiemTheoMAMH(root->leftChild, MAMH);
  	} 
	else 
	{
    	return TimKiemTheoMAMH(root->rightChild, MAMH);
  	}
}

void printTree(DanhSachMonHoc* root) {
	if (root != NULL) {
		cout << root->data.MAMH << " " << root->data.TENMH << " " << root->data.STCLT << " " << root->data.STCTH << endl;
		printTree(root->leftChild);
		printTree(root->rightChild);
	}
}

// int main()
// {
//     //du lieu test
// 	MH mh1, mh2, mh3, mh4;
// 	mh1.MAMH = "01"; mh1.STCLT = 1; mh1.STCTH = 2; mh1.TENMH = "Toan";
// 	mh2.MAMH = "02"; mh1.STCLT = 2; mh1.STCTH = 2; mh1.TENMH = "Toangt";
// 	mh3.MAMH = "03"; mh1.STCLT = 3; mh1.STCTH = 3; mh1.TENMH = "Toancc";
// 	mh4.MAMH = "04"; mh1.STCLT = 4; mh1.STCTH = 2; mh1.TENMH = "Toancc2";

// 	DanhSachMonHoc *root = NULL;
// 	root = insertDanhSachMonHoc(root, mh1);
// 	root = insertDanhSachMonHoc(root, mh2);
// 	root = insertDanhSachMonHoc(root, mh3);
// 	root = insertDanhSachMonHoc(root, mh4);
	
// 	printf("AVL Tree: ");
//    	printTree(root);

//    	return 0;
// }