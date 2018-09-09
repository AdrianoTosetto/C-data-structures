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

int main(int argc, char const *argv[])
{
	PtABPNode root = PtABPNodeCreate(10);
	PtABPNode left = PtABPNodeCreate(5);
	PtABPNode right = PtABPNodeCreate(15);

	root->left = left;
	root->right = right;

	PtABPNode lleft = PtABPNodeCreate(4);
	root->left->left = lleft;

	assert (ABPHeight(root) == 3);
	assert (ABPSize(root) == 4);
	return 0;
}