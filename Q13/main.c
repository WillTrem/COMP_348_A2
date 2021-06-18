#include <stdio.h>
#include <stdlib.h>
typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode;

typedef struct {
    eltype type;
    union {
        atom a;
        struct _listnode* l;
    };
} element;

typedef struct _listnode {
    element el;
    struct _listnode* next;
} * list;

const element NIL = { .type=LIST, .l=NULL };

element aasel(atom);
element lasel(list);
list cons(element, list);
list append(list, list);
element car(element);
list cdr(element);
list cddr(element);
void free(list);
void print(element);

int main()
{
    printf("Hello World");

    return 0;
}

element aasel(atom a){
    _listnode head = NULL;
    
    element * e = (element *)malloc(sizeof(element));
    e->type = ATOM;
    e->a = a;
    e->l = head;
    return e;
}

element lasel(list l){
    list head = NULL;
    
    element * e = (element *)malloc(sizeof(element));
    e->type = LIST;
    e->a = l;
    e->l = head;
    return e;
}

list cons(element e, list l){
    list head = NULL;
    struct _listnode * newNode = malloc(sizeof(struct _listnode));
    newNode->el = e;
    newNode->next = l;
    return head;
}

list append(list l1, list l2){
    list head = l1;
    struct _listnode * iterator = head;
    while(iterator->next != NULL){
        iterator = iterator->next;
    }
    iterator->next = l2;
    return head;
}

element car(element e){
    if(e.type == ATOM){
        return NIL;
    }
    else{
        return e[0];
    }
}

list cdr(element e){
    if(e.type == ATOM){
        return NULL;
    }
    else{
        struct _listnode * iterator = e[1];
        list l = NULL:
        while(iterator->next != NULL){
            append(l,iterator);
        }
        return l;
    }
}

list cddr(element e){
     if(e.type == ATOM){
        return NULL;
    }
    else{
        struct _listnode * iterator = e[2];
        list l = NULL:
        while(iterator->next != NULL){
            append(l,iterator);
        }
        return l;
    }
}


void lfree(list l){
    struct _listnode * iterator = l[0];
    while(iterator->next != NULL){
        free(iterator);
    }
}

void print(element e){
    if(e.type == ATOM){
        printf(" %c ", e.a);
    }
    else if (e.type == LIST){
        printf("((%c))", e.a);
    }
    else{
        printf("NIL");
    }
}