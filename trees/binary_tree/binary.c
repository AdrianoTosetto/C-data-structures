#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int32_t i32;
typedef uint32_t ui32;

typedef struct abpnode *PtABPNode;

struct abpnode
{
	PtABPNode left;
	PtABPNode right;
	int element;
};

size_t node_size = sizeof (struct abpnode);

PtABPNode PtABPNodeCreate(int e) {
	PtABPNode Node;

	if ((Node = (PtABPNode) malloc(node_size)) == NULL) return NULL;

	Node->element = e;
	Node->right = NULL;
	Node->left  = NULL;

	return (Node);
}

void PtABPNodeDestroy(PtABPNode node) {

}

/*
	how many elements
*/

ui32 ABPSize(PtABPNode root) {
	if (root == NULL) return 0;
	else return ABPSize(root->left) + ABPSize(root->right) + 1;
}

ui32 ABPHeight(PtABPNode root) {
	ui32 lHeight, rHeight;

	if (root == NULL) return 0;

	lHeight = ABPHeight(root->left);
	rHeight = ABPHeight(root->right);

	if (lHeight  > rHeight)
		return lHeight + 1;
	else
		return rHeight + 1;
}

PtABPNode KMinRec(PtABPNode root, ui32 pk) {
	ui32 nleft = ABPSize(root);

	if (pk == nleft + 1) return root;

	if (pk <= nleft) 
		return KMinRec(root->left, pk);
	else
		return KMinRec(root->right, pk-nleft-1);
}

#define SIZE(node) ABPSize(node)

PtABPNode ABPMin(PtABPNode root, ui32 k) {
	if (k < 1 || SIZE(root) <  k) return NULL;
	else
		return KMinRec(root, k); 
}

PtABPNode ABPMinE(PtABPNode root) {
	return ABPMin(root, 1);
}

#define NEXT(node, e) \
	(*node).element > e ? node->left : node->right

void ABPDeleteRep(PtABPNode *root, int e) {

	PtABPNode deleteNode = *root;
	while (deleteNode != NULL && (*deleteNode).element != e) {

		/*if ((*deleteNode).element > e) 
			deleteNode = deleteNode->left;
		else
			deleteNode = deleteNode->right;*/
		deleteNode = NEXT(deleteNode, e);
	}

	printf("%d\n", deleteNode->element);
}

int main(int argc, char const *argv[])
{
	PtABPNode root = PtABPNodeCreate(10);
	PtABPNode left = PtABPNodeCreate(5);
	PtABPNode right = PtABPNodeCreate(15);

	root->left = left;
	root->right = right;

	PtABPNode lleft = PtABPNodeCreate(4);
	root->left->left = lleft;
	ABPDeleteRep(&root, 4);
	//assert (ABPHeight(root) == 3);
	//assert (ABPSize(root) == 4);
	return 0;
}