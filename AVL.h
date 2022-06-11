#include<bits/stdc++.h>
#define COUNT 10
using namespace std;
struct DAPAN{
	int id;
	char dan[50];
};
struct NODE{
	DAPAN data;
	NODE *left;
	NODE *right;
};
typedef NODE *Tree;
NODE *insert(NODE *t, DAPAN x);
int treeLevel(NODE *t);
bool checkAvl(NODE *t);
NODE *turnRight(NODE *a);
NODE *turnLeft(NODE *a);
NODE *updateTreeAvl(NODE *t);

void print2DUtil(struct NODE *root, int space);
void print2D(struct NODE *root);
