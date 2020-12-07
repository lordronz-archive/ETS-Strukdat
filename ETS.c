#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int num;
    struct node *next;
} node;

// inisialisasi node head, node yang akan selalu berada diawal
node* head = NULL;

void addNode(int num) {
    node* newNode = malloc(sizeof(node));
    newNode->num = num;
    newNode->next = NULL;
    node* temp = head;
    if(temp) {
	while(temp->next) {
	    temp = temp->next;
	}
	temp->next = newNode;
    }
    else {
	head = newNode;
    }
}

void printNode() {
    node* temp = head;
    while(temp) {
	printf("%d ", temp->num);
	temp = temp->next;
    }
    printf("\n");
}

int countNode() {
    int cnt = 0;
    node* temp = head;
    while(temp) {
	++cnt;
	temp = temp->next;
    }
    return cnt;
}

int countTotalData() {
    int tot = 0;
    node* temp = head;
    while(temp) {
	tot += temp->num;
	temp = temp->next;
    }
    return tot;
}

void printMinNode() {
    node* temp = head;
    int min;
    if(temp) {
	min = temp->num;
	while(temp) {
	    temp = temp->next;
	    min = temp && (temp->num < min) ? temp->num : min;
	}
	printf("Node Terkecil yang ada di list : %d\n", min);
    }
    else {
	printf("List kosong !\n");
    }
}

void delMaxNode() {
    node* temp = head;
    node* prev = NULL;
    node* prevMax = NULL;
    node* delNode = NULL;
    bool maxIsHead = false;
    int max = -696969;
    int deletedNum = -1;
    while(temp) {
	if(temp == head && temp->num > max) {
	    maxIsHead = true;
	    delNode = temp;
	    max = temp->num;
	}
	else if(temp->num > max) {
	    max = temp->num;
	    prevMax = prev;
	    delNode = temp;
	    maxIsHead = false;
	}
	prev = temp;
	temp = temp->next;
    }
    if(maxIsHead && delNode) {
	head = head->next;
	deletedNum = delNode->num;
	delNode->next = NULL;
	free(delNode);
    }
    else if(delNode && prevMax) {
	prevMax->next = delNode->next;
	deletedNum = delNode->num;
	delNode->next = NULL;
	free(delNode);
    }
}

int main(void) {
    addNode(8);
    addNode(8);
    addNode(4);
    addNode(4);
    addNode(7);
    addNode(6);
    printNode();
    printf("Jumlah Node = %d\n", countNode());
    printMinNode();
    delMaxNode();
    printNode();
    printf("Total jumlah angka dalam list = %d\n", countTotalData());
    return 0;
}
