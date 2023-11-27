#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char value[100];
    struct node *next;
};
typedef struct node node;

struct List{
    node *head;
    node *tail;
    int len;
};
typedef struct List List;

void addData(List *, char *);
void printData(List * , char *);
int count(List *, char *);
int hash(char *);
void deleteData(List *, char *);


#endif