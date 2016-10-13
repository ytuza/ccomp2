#include <stdio.h>

struct node {
    int val;
    struct nodo *next;

};

void prinl(struct node *p){
    while (p -> next != NULL){
        printf("%d , ",p -> val);
        p = p -> next;
    }
    printf("ult: %d \n",p -> val);
    return;
}

struct node* del(struct node *ch, v){
    struct node *cur, *temp;
    if(p -> val == v){
        temp = ch;
        ch  = ch -> next;
        free(temp);
        return ch;

    }else{
    while(p -> next != NULL){
        if(p -> val == v){
            p -> next = cur -> next;
            free(cur);
            break;
        }
        p = cur ;
        cur = cur->next

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



main(){
    struct node *inic, *seg, *te;

    inic = malloc(sizeof(struct node));
    seg = malloc(sizeof(struct node));
    te = malloc(sizeof(struct node));

    inic -> val = 5;
    seg -> val = 2;
    te -> val = 8;
    inic -> next = seg;
    seg -> next = te;
    te -> next = NULL;
    prinl(inic);
    inic = agre(inic,4,14);
    prinl(inic);

}
