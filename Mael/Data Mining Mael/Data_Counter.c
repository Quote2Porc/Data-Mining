#include "Data_Counter.h"


/**     Private prototypes    **/

void Data_count_list(char*SDD,char item,int M);


/**     Public functions    **/

void Data_count(char* Data,char* SDD,int i,int M)
{
    char Data_current=Data[i];
    Data_count_list(SDD, Data_current,M);
}





/**     Private functions    **/

void Data_count_list(char*SDD,char item, int M)
{
    int i=0;
    char* item_current=SDD;
    while(i<M & item_current[0]!=item)
    {
    i++;
    /**     item_current+=sizeof(char);             A changer    **/
    }
    if(i==M)
    {
        /**replace last**/
    }
    else
    {
        /**counter++**/
    }
}
