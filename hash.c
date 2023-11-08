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
    if(l->head == NULL){
        l->head = (node *)malloc(sizeof(node));
        strcpy(l->head->value , a);
        l->head->next = NULL;
        l->tail = l->head;
        l->len = 1;
    }
    else{
        node *tmp = (node *)malloc(sizeof(node));
        strcpy(tmp->value , a);
        tmp->next = NULL;
        l->tail->next = tmp;
        l->tail = tmp;
        l->len++;
    }
}

void printData(List *l , char a[]){
    if(l->head == NULL){
        printf("List is empty\n");
        return;
    }
    node *tmp = l->head;
    while(tmp != NULL){
        if(strcmp(tmp->value , a) == 0){
            printf("%s\n" , tmp->value);
        }
        tmp = tmp->next;
    }
}

int count(List *l , char a[]){
    int res = 0;
    if(l->head == NULL){
        return res;
    }
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
    if(l->head == NULL){
        printf("List is empty\n");
        return;
    }
    node *tmp = l->head;
    node *prev = NULL;
    while(tmp != NULL){
        if(strcmp(tmp->value , a) == 0){
            if(prev == NULL){
                l->head = tmp->next;
                free(tmp);
                tmp = l->head;
            }
            else{
                prev->next = tmp->next;
                free(tmp);
                tmp = prev->next;
            }
        }
        else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
}