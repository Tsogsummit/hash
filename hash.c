#include "DS.h"

int hash(char a[]){
    int res = 0;
    for(int i = 0 ; a[i] != '\0' ; i++){
        res += a[i];
    }
    while(res > 9){
        int k = res;
        int sum = 0;
        while(k > 0){
            sum += k % 10;
            k /= 10;
        }
        res = sum;
    }
    return res;
}

void addData(List *l , char a[]){
    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->value , a);
    newNode->next = NULL;
    if(l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    }else{
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

void printData(List *l , char a[]){
    node *tmp = l->head;
    while(tmp != NULL){
        printf("%s\n" , tmp->value);
        tmp = tmp->next;
    }
}

int count(List *l , char a[]){
    int res = 0;
    node *tmp = l->head;
    while(tmp != NULL){
        if(strcmp(tmp->value , a) == 0){
            res++;
        }
        tmp = tmp->next;
    }
    return res;
}

void deleteData(List *l , char a[]){
    node *tmp = l->head;
    node *prev = NULL;
    while(tmp != NULL){
        if(strcmp(tmp->value , a) == 0){
            if(prev == NULL){
                l->head = tmp->next;
            }else{
                prev->next = tmp->next;
            }
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}