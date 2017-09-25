#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
typedef struct nodes {
	int *nodes;
	int start_node;
	int special_node;
	char *rule;
}NODE; //define struct nodes = NODE
void movevalue(NODE * x, int *length) {
	int result = 0;
	printf("%d ", x->nodes[x->start_node]);
	if (x->start_node == 0) {
		if (abs(x->nodes[(*length) - 1] - x->nodes[x->start_node]) < abs(x->nodes[x->start_node] - x->nodes[x->start_node + 1]))
			result= 1;
	} //start_node exists in the first
	else if (x->start_node == (*length)-1) {
		if (abs(x->nodes[x->start_node-1] - x->nodes[x->start_node]) < abs(x->nodes[x->start_node] - x->nodes[0]))
			result = 2;
		else 
			result = 3;
	} //start_node exists in the end
	else {
		if (abs(x->nodes[x->start_node - 1] - x->nodes[x->start_node]) < abs(x->nodes[x->start_node] - x->nodes[x->start_node + 1]))
			result = 4;
	} //start_node exists in the middle
	for (int i = x->start_node; i < (*length) - 1; i++) {
		x->nodes[i] = x->nodes[i + 1];
	}
	(*length)--;
	switch (result) {
		case 1:
			x->start_node = (*length) - 1;
			break;
		case 2:
			x->start_node = (*length) - 1;
			break;
		case 3:
			x->start_node = 0;
			break;
		case 4:
			x->start_node -= 1;
	} //move start_node position
} //movevalue function end(move to left or right)
int enter(NODE *x,int * length) {
	if (strcmp(x->rule, "jump") == 0) {
		for (int i = x->special_node; i < 8; i++) {
			x->nodes[i] = x->nodes[i + 1];
		}
		if (x->special_node < x->start_node)
			(x->start_node) -= 1;
		(*length)--;
	}
	if (strcmp(x->rule, "swap") == 0) {
		if (x->nodes[x->special_node] >= 10)
			x->nodes[x->special_node] = (x->nodes[x->special_node]) % 10 * 10 + (x->nodes[x->special_node]) / 10;
	}
} //enter function end(jump or swap)
int main(void) {
	int arr[9];
	struct nodes xyz;
	char temp[10]; //jump or swap character
	int length = 9;
	srand(time(NULL)); //real random
	for (int i = 0; i < 9; i++) {
		arr[i] = rand() % 99 + 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j])
				i--;
		}
	}
	for (int i = 0; i < 9; i++)
		printf("%d ", arr[i]);
	printf("\n");
	xyz.rule = temp;
	xyz.nodes = arr;
	scanf("%d %d", &xyz.start_node, &xyz.special_node);
	scanf("%s", temp);
	(xyz.start_node)--;
	(xyz.special_node)--;
	enter(&xyz,&length);
	while (length)
		movevalue(&xyz, &length);
	printf("\n");
} //main function end