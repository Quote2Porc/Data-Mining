#include <stdio.h>
#include <stdlib.h>
#include "Top_k.h"
#include "defines.h"


//extern List last_item;
extern List DTB;
/** Public prototypes   **/

/** Private prototypes  **/


List Init_DTB(int type,int M);

/** |DATA|DATA length|k|M|DTB type|            **/
int main(int argc, char *argv[])
{
    /**if(argc!=5)
        return -1;******************************************/

    //char *Data;//[1000];//=argv[0];         /**        A changer                     **/
    //int Data_len;//=(int)argv[1][0];
    int k;//=argv[2][0];/**not used**/
    int M;//=argv[3][0];
    int type;//=argv[3][0];




/*****/
/***************************/
FILE* file = fopen("/home/mael/Bureau/DataMining_Projet/Commun/fichier_test","r");
if(file==NULL)
    return -1;
//Data=file;
/*int j=0;
while(Data[j]!='\0')
{
    j++;
}
Data_len=j;*/
/****/
/*
int j;
Data_len=1000;
for(j=0;j<1000;j++)
Data[j]=(int)random()*40;
*/
k=2;
M=13;
type=LIST;
/*****/

    DTB=Init_DTB(type,M);
//    last_item=NULL;


    int Data = fgetc(file);
    //int i;
    //for(i=0;i<Data_len;i++)
    while(Data!=EOF)
    {
        Top_k(Data,DTB,type);
        Data = fgetc(file);
        /*********************************/
   /* List DTB_temp=DTB;
            int i;
    for(i=0;i<M-1;i++)
    {
        if(DTB_temp==NULL;
            break;
        printf("%d|%d\t|\n",DTB_temp->item,DTB_temp->counter);
        DTB_temp=DTB_temp->next;
    }
    i++;*/
        /*********************************/
    }

    fclose(file);
    //printf("\n");
    //fflush(stdout);
    FILE* Data_result = fopen("/home/mael/Bureau/DataMining_Projet/Commun/resultats.txt","w");
    List DTB_temp=DTB;
    int i;
    for(i=0;i<M-1;i++)
    {
        //if(DTB_temp==NULL)/**********************************************************************************/
            //break;
        fprintf(Data_result,"%d|%d\t|\n",DTB_temp->item,DTB_temp->counter);
        DTB_temp=DTB_temp->next;
    }
    fclose(Data_result);
    return 0;
}






/**********************************************************************************************************free the list***********/




List Init_DTB(int type,int M)
{
    switch(type)
    {
    case LIST :
        {
        List result=(List)malloc(sizeof(Link));
        List prec=result;
        List temp=result;

        result->previous=NULL;
        result->item=0;
        result->counter=0;

        temp=(List)malloc(sizeof(Link));
        prec->next=temp;

        temp->previous=prec;
        temp->counter=0;
        temp->item=0;
        prec=temp;

        int i;
        for(i=0;i<M-1;i++)
        {
            temp=(List)malloc(sizeof(Link));
            prec->next=temp;
            temp->previous=prec;
            temp->counter=0;
            temp->item=0;
            prec=temp;
        }
 //       last_item=temp;
        temp->next=NULL;
        return result;
        }

    case TREE :
        return NULL;

    case DATA_STREAM_SUMMARY :    /*******/
        return NULL;/*******/
    default :
        return NULL;
    }
}

