#include "AVL.h"
#define COUNT 10
using namespace std;
typedef NODE *Tree;
NODE *insert(NODE *t, DAPAN x){
	if (t == NULL){
		NODE *temp = new NODE;
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} else{
		if (x.id < t->data.id){
			t->left = insert(t->left, x);
		} else{
			t->right = insert(t->right, x);
		}
	}
	
}
int treeLevel(NODE *t){
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->left), treeLevel(t->right));
}
bool checkAvl(NODE *t){
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
	return checkAvl(t->left) && checkAvl(t->right);
}
NODE *turnRight(NODE *a){
	NODE *b = a->left;
	NODE *d = b->right;
	a->left = d;
	b->right = a;
	return b;
}
NODE *turnLeft(NODE *a){
	NODE *b = a->right;
	NODE *c = b->left;
	a->right = c;
	b->left = a;
	return b;
}
/*void printTree(Tree t){
	if (t != NULL){
		printTree(t->left);
		cout << t->data.id << " ";
		if (t->left != NULL) cout <<t->left->data.id << " ";
		if (t->right != NULL) cout << t->right->data.id << " ";
		cout << endl;
		printTree(t->right);
	}
}*/
void print2DUtil(struct NODE *root, int space)
{
    
    if (root == NULL)
        return;
 
    
    space += COUNT;
 
    
    print2DUtil(root->right, space);
 
 
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data.id);

    print2DUtil(root->left, space);
}


void print2D(struct NODE *root)
{
   print2DUtil(root, 0);
}
NODE *updateTreeAvl(NODE *t){
	if (abs(treeLevel(t->left) - treeLevel(t->right)) > 1){
		if (treeLevel(t->left) > treeLevel(t->right)){
			NODE *p = t->left;
			if (treeLevel(p->left) >= treeLevel(p->right)){
				t = turnRight(t);
			} else{
				t->left = turnLeft(t->left);
				t = turnRight(t);
			}
		} else {
			NODE *p = t->right;
			if (treeLevel(p->right) >= treeLevel(p->left)){
				t = turnLeft(t);
			} else{
				t->right = turnRight(t->right);
				t = turnLeft(t);
			
			}
		}	
	}
	if (t->left != NULL) t->left = updateTreeAvl(t->left);
	if (t->right != NULL) t->right = updateTreeAvl(t->right);
	return t;
}
void deleteTree(NODE* t)
{
    if (t == NULL) return;
 
    deleteTree(t->left);
    deleteTree(t->right);
    
    delete t;
}
