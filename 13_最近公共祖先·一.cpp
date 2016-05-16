#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char name[128];
    struct _node *dad;
} node;

node *find (char name[], int n, node list[]) {
    for (int i=0; i<n; ++i)
        if (strcmp(name,list[i].name)==0) {return &list[i];}
    return NULL;
}


int main () {

    int n = 0;
    scanf("%d\n",&n);

    char  nam1[128],  nam2[128];
    node  list[200], *trc1[200], *trc2[200];

    int num = 0;
    for (int i=0,id=0,is=0; i<n; ++i) {
        scanf("%s%s",nam1,nam2);
        id = num;
        while (id-- && strcmp(nam1,list[id].name)!=0) {}
        if (id < 0) {
            id = num;
            strcpy(list[id].name,nam1);
            list[id].dad = NULL;
            num++;
        }
        is = num;
        while (is-- && strcmp(nam2,list[is].name)!=0) {}
        if (is < 0) {
            is = num;
            strcpy(list[is].name,nam2);
            list[is].dad = NULL;
            num++;
        }
        list[is].dad = &list[id];
    }

    int m = 0;
    scanf("%d\n",&m);

    for (int i=0; i<m ;++i) {
        scanf("%s%s",nam1,nam2);
        if (strcmp(nam1,nam2) == 0) {
            printf("%s\n",nam1);
        } else {
            node *nod1 = find(nam1,num,list);
            node *nod2 = find(nam2,num,list);
            if (!nod1 || !nod2) {printf("-1\n");}
            else {

              //   写的太好了，这一段跟链表找环是一个意思
                int num1 = 0, num2 = 0;
                do {
                    trc1[num1++] = nod1;
                    nod1 = nod1->dad;
                } while (nod1);
                do {
                    trc2[num2++] = nod2;
                    nod2 = nod2->dad;
                } while (nod2);
                if (trc1[num1-1] != trc2[num2-1]) {
                    printf("-1\n");
                } else {
                    while (num1-- && num2-- && trc1[num1]==trc2[num2]) {}
                    printf("%s\n",trc1[num1+1]->name);
                }
            }
        }
    }
    return 0;
}
