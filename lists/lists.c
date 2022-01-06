#include <stdio.h>
#include <stdlib.h>



struct list{

    int value;
    struct list* link;
};

struct list* swaplist(struct list*);

void printlist(struct list* s){
    struct list* temp = s;
    while(temp!= NULL){
	printf("%d\n", temp->value);
	temp = temp->link;
    }
}

struct list* cons(struct list* l, int n){
    struct list* new;
    new = (struct list*)malloc(sizeof(struct list));
    new->value = n;
    new->link = l;
    return new;

}

void push(struct list* l, int n){
    struct list* new;
    new = (struct list*)malloc(sizeof(struct list));
    new->value = n;
    new ->link = NULL;
    struct list* temp = l;
    while( temp->link!=NULL ){
	temp = temp->link;
    }
    temp->link = new;
}



struct list* filter(struct list* l){
    struct list * temp = l;
    struct list * start = NULL;
    while(temp != NULL){
	if(temp->value > 0)start = cons(start, temp->value);
	temp = temp->link;
    }
     // start -- мусор
     // ДЗ: написать функц free_list
    start = swaplist(start);
    return start;
}

struct list* swaplist(struct list* l){
    struct list *start =NULL;
    struct list *temp;
    while(l!=NULL){
	start = cons(start, l->value);
	temp = l;
	l = l->link;
	free(temp);
    }
    return start;
}


int main(){
    struct list a;
    struct list b;
    struct list c;
    a.value = 10;
    a.link = &b;
    b.value = 3;
    b.link =&c;
    c.value = -3;
    c.link =NULL;
//    printf("%d", a.link->link->value);
    push(&a, 64);
    printlist(filter(&a));
    return 0;
}


// 4556 89 + 8765 *