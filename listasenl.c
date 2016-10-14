#include <stdio.h>

struct node {
    int val;
    struct nodo *next;

};

struct node* crear(int i[]){
    int tam = sizeof *i , c = 0;
    struct node *p, *n, *prev;
    p = malloc(sizeof(struct node));
    p -> val = i[c];
    prev = p ;

    for(c = 1; c < tam; c++){
        n = malloc(sizeof(struct node));
        n -> val = i[c];
        prev -> next = n;
        prev = n;
    }
    prev -> next = NULL;
    return p;
}

void prinl(struct node *p){
    printf("[ ");
    while (p -> next != NULL){
        printf("%d , ",p -> val);
        p = p -> next;
    }
    printf("%d ] \n",p -> val);
    return;
}

struct node* delval(struct node *ch,int v){
    if(ch -> val == v){
        struct node *temp ;
        temp = ch;
        ch  = ch -> next;
        free(temp);
        return ch;

    }else{
    struct node *p, *cur;
    p = ch;
    cur = ch -> next;
    while( p-> next != NULL){
        if(cur -> val == v){
            p -> next = cur -> next;
            free(cur);
            return ch;
        }
        p = cur ;
        cur = cur->next;

    }
    }
    return ch;

}

struct node* delpos(struct node *ch,int pos){

    if(pos == 0){
        struct node *temp ;
        temp = ch;
        ch  = ch -> next;
        free(temp);
        return ch;

    }else{
    struct node *p, *cur;
    int i = 0 ;
    p = ch;
    cur = ch -> next;
    while( p-> next != NULL){
        i++;
        if(i == pos){
            p -> next = cur -> next;
            free(cur);
            return ch;
        }


        p = cur ;
        cur = cur->next;

    }


    }
    return ch;

}

struct node* agre(struct node *p ,int pot,int v){
    int i =0;
    struct node *n;
    n = malloc(sizeof(struct node));
    n-> val= v;
    if (pot == 0){
        printf("%d\n",n->val);
        n->next = p;
        p = n;
        return p;
    }else{
    struct node *pos, *prev;
    prev = p;
    pos = p -> next;
    for(i; i < pot-1 ; i++){
        prev = pos ;
        pos = pos -> next;
        if (pos == NULL){
            printf("error la posicion solicitada es mayor al tamnio \n");
            return p;
        }
    }
    prev -> next = n;
    n -> next = pos;
    return p;
}
}

void concat(struct node *a, struct node *b){
    while(a -> next != NULL){
        a = a->next;
    }
    a -> next = b;
    return;
}

//void buble

main(){
    struct node *lp,*la;
    int i[20] = {4,6,5,3};
    int j[20] = {1,6,2,93};
    lp = crear(i);
    prinl(lp);
    lp = delpos(lp,0);
    prinl(lp);



}
