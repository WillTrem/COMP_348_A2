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
    /*element * e = (element *)malloc(sizeof(element));
    e->type = ATOM;
    e->a = a;
    e->l = NIL;
    */
    element e;
    e.type = ATOM;
    e.a = a;
    // initialization of *list here...
    //e.l = l;
    return e;
}

element lasel(list l){
    element e;
    e.type = LIST;
    //... to be completed
    return e;
}

list cons(element e, list l){
    /*
    Something like...
    
    element tail = lasel(l);
    e.l = tail;
    list newList;
    newList.el = e;
    newList.next = tail;
    return newList;
    */
    return l;
}

list append(list l1, list l2){
    /*
    Something like...
    list newList;
    newList.el = lasel(l1);
    newList.next = l2;
    return newList;
    */
    return l1;
}

element car(element e){
    if(e.type == ATOM){
        return NIL;
    }
    else{
        //... to be completed
        return NIL;
    }
}

list cdr(element e){
    //... to be completed
    list l; // to be removed; here just for return-statement
    return l;
}

list cddr(element e){
    //... to be completed
    list l; // to be removed; here just for return-statement
    return l;
}

void free(list l){
    //... to be completed
}

void print(element e){
    //... to be completed
}