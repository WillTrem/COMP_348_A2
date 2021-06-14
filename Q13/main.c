#include <stdio.h>

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
    return NIL;
}

element lasel(list l){
    return NIL;
}

list cons(element e, list l){
    return l;
}

list append(list l1, list l2){
    return l1;
}

element car(element e){
    return NIL;    
}

list cdr(element e){
    list l;
    return l;
}

list cddr(element e){
    list l;
    return l;
}

void free(list l){
    
}

void print(element e){
    
}