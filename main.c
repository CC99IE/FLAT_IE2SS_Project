#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int id_num;
    int st_val;
    struct node *link0;
    struct node *link1;
};
struct node *start, *q, *ptr;
int vst_arr[100], a[10];
int main(){
    int nrStates, i, pozitie, j;
    char n[10], keyWord[256];
    printf("Keyword: ");
    scanf("%s",&keyWord);
    nrStates=strlen(keyWord);
    q=(struct node *)malloc(sizeof(struct node)*nrStates);
    for(i=0;i<nrStates;i++){
        (q+i)->id_num=i;
        printf("\nState Number::%d\n",i);
        printf("Next State if 0:");
        scanf("%d",&pozitie);
        (q+i)->link0=(q+pozitie);
        printf("Next State if 1:");
        scanf("%d",&pozitie);
        (q+i)->link1=(q+pozitie);
        printf("Is the State Final?(0 = N/1 = Y)?");
        scanf("%d",&(q+i)->st_val);
    }
    printf("\nWhich State should start from:");
    scanf("%d",&pozitie);
    start=q+pozitie;
    printf("\n");
    while(1){
        printf("\n");
        printf("Do you want to check it?(0 = N/1 = Y):");
        scanf("%d",&j);
        if(j){
      while(n[pozitie]!='\0'){
                a[pozitie]=(n[pozitie]-'0');
                pozitie++;
            }
            i=0;
            printf("Visited States:");
            do{
                vst_arr[i]=ptr->id_num;
                if(a[i]==0){
                    ptr=ptr->link0;
                }
                else if(a[i]==1){
                    ptr=ptr->link1;
                }
                else{
                    printf("Illegal Input\n");
                    return 0;
                }
                printf("[%d]",vst_arr[i]);
                i++;
            }while(i<pozitie);
            printf("\n");
            printf("Current State:%d\n",ptr->id_num);
            printf("String Status:: ");
            if(ptr->st_val==1)
                printf("Accepted\n");
            else
                printf("Rejected\n");
        }
        else
            return 0;
    }
}
