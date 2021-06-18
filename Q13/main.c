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
//void free(list);
void print(element);
void print2(list);

int main()
{
    element a = aasel('a');
    element b = aasel('b');
    element c = aasel('c');
    element listEl = lasel(cons(b, cons(c,NULL)));
    element d = aasel('d');
    element e = aasel('e');
    list list1 = cons(a, cons(listEl, cons(d, cons(e,NULL))));
    print(lasel(list1));
    printf("\n");
    print(car(lasel(list1)));
    printf("\n");
    print(lasel(cdr(lasel(list1))));
    printf("\n");
    print(car(car(lasel(list1))));

    return 0;
}

element aasel(atom a){
    element e;
    e.type = ATOM;
    e.a = a;
    return e;
}

element lasel(list l){
    element e;
    e.type = LIST;
    //... to be completed
    e.l = l;
    return e;
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

list cons(element e, list l){
    list head = NULL;
    struct _listnode * newNode = malloc(sizeof(struct _listnode));
    newNode->el = e;
    newNode->next = NULL;
    head = newNode;

    return append(head,l);
}

element car(element e){
    if(e.type == ATOM){
        return NIL;
    }
    else{
        return e.l->el;
    }
}

list cdr(element e){
    list l = e.l->next;
    return l;
}

list cddr(element e){
    list l = e.l->el.l;
    return l;
}

void print(element e){
    if(e.type == ATOM){
        printf(" %c ", e.a);
    }
    else if(e.type == LIST){
        if (e.l == NULL){
            printf("NIL");
        }
        else{
            printf("(");
            print(e.l->el);
            print(lasel(e.l->next));
            printf(")");
        }

    }
}

void print2(list l){
    element e = l->el;
    if(e.type == ATOM){
        printf(" %c ", e.a);
        if(l->next != NULL){
            print2(l->next);
        }
    }
    else if(e.type == LIST){
        if (e.l == NULL){
            printf("NIL");
        }
        else{
            printf("(");
            print2(e.l);
            print2(l->next);
            printf(")");
        }

    }
}
