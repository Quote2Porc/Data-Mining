#include "Top_k.h"






int bool_DTB_full=0;
//List last_item=NULL;
List DTB=NULL;


/**     Private prototypes    **/

//void Top_k_list(List DTB,char data, int type);
List Next_in_DTB(char item,List DTB,int type);
void Replace_in_DTB(char item,List DTB,int type,List item_current);
int has_next(List item);


/**     Public functions    **/

/*
void   Top_k(char Data,List DTB,int type)
{
    Top_k_list(DTB,Data, type);
}
*/




/**     Private functions    **/





void  Top_k(char item, List DTB, int type)
{
    int i=0;
    List item_current=DTB;
    while((has_next(item_current)) && (item_current->item!=0) && (item_current->item!=item))
    {
        i++;
        item_current=Next_in_DTB(item,item_current,type);
        /**     item_current+=sizeof(char);             A changer    **/
    }
 //   if(!has_next(item_current))
 //   {
 //       //bool_DTB_full=1;
 //       Replace_in_DTB(item,DTB,type,last_item);/**rework**/
 //           /**replace last**/
 //   }
 //   else
    {
            /**counter++**/
        //if(!bool_DTB_full)

        Replace_in_DTB(item,DTB,type,item_current);/**rework**/
    }
}



List Next_in_DTB(char item,List DTB_current,int type)
{
    switch(type)
    {
    case LIST :
        return DTB_current->next;

    case TREE :
        return NULL;

    case DATA_STREAM_SUMMARY :    /*******/
        return NULL;/*******/
    default :
        return NULL;
    }
}



void Replace_in_DTB(char item,List DTB,int type,List item_current)
{
    switch(type)
    {
    case LIST :
        item_current->item=item;/**updates in case of new link or does nothing if was already in the list**/
        item_current->counter=item_current->counter + 1;/**increment counter**/

        List prev;
        List prevprev;
        List nex;
        while((item_current->previous!=NULL) && (item_current->previous->counter < item_current->counter))/**moving up the link in the list**/
            {
            prev=item_current->previous;
            prevprev=prev->previous;
            nex=item_current->next;

            item_current->previous=prevprev;
            item_current->next=prev;

            prev->next=nex;
            prev->previous=item_current;

            if(prevprev!=NULL)
                prevprev->next=item_current;

            if(nex!=NULL)
                nex->previous=prev;
            }
        if(item_current->previous==NULL)/**if the link decomes the new first link**/
            DTB=item_current;

 //       while(last_item->next!=NULL)/**if the current link was last link and moved up the list**/
 //           last_item=last_item->next;

        break;

    case TREE :
        break;

    case DATA_STREAM_SUMMARY :    /*******/
        break;/*******/
    }
}



int has_next(List item)
{
    return ((item!=NULL)&&(item->next != NULL));
}



