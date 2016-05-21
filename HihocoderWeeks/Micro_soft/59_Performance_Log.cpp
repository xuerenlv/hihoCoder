#include "stdio.h"
#include "string.h"

typedef struct {
        char name[256];
        int time[4];
        char state[10];
} slog;

slog space[20000*2];
int ns=0;

void push(slog a){
        space[ns++]=a;
}
slog pop(){
        return space[--ns];
}

slog get(){
        return space[ns-1];
}

int isempty(){
        return ns==0;
}

slog space1[20000];
int ns1=0;

int calculate_time(int* s, int* e){
        int i=0;
        int flag=0;
        for (i=2; i>=0; i--) {
                e[i]=e[i]+flag;
                flag=0;
                if(e[i]>=s[i])
                        e[i]=e[i]-s[i];
                else
                {
                        flag=-1;
                        e[i]=e[i]-s[i]+60;
                }
        }

        return flag+1;

}

int main(){
        int i=0, j=0;
        int N=0;
        scanf("%d", &N);
        while (N--) {
                slog s;
                scanf("%s %d:%d:%d %s", s.name, &s.time[0], &s.time[1],&s.time[2], s.state);

                if (strcmp(s.state, "START")==0) {
                        push(s);
                        strcpy(space1[ns1++].name, s.name);
                }else{
                        slog t=pop();
                        if (strcmp(t.name, s.name)==0 && strcmp(t.state, "START")==0 && calculate_time(t.time, s.time))
                                for (i=ns1-1; i>=0; i--) {
                                        if (strcmp(space1[i].name, t.name)==0) {
                                                space1[i].time[0]=s.time[0];
                                                space1[i].time[1]=s.time[1];
                                                space1[i].time[2]=s.time[2];
                                                break;
                                        }
                                }
                        else{
                                printf("Incorrect performance log\n");
                                return 0;
                        }
                }
        }

        if(!isempty())
        {
                printf("Incorrect performance log\n");
                return 0;
        }

        for (j=0; j<ns1; j++)
        {
                slog t=space1[j];
                printf("%s ", t.name);

                for (i=0; i<=1; i++) {
                        if (t.time[i]<10)
                                printf("0%d:", t.time[i]);
                        else
                                printf("%d:", t.time[i]);
                }

                if (t.time[2]<10)
                        printf("0%d", t.time[2]);
                else
                        printf("%d", t.time[2]);

                printf("\n");
        }

        return 0;
}
