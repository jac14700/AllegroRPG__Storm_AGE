#include"al_header.h"
bool ifthemaninbranch(int x,int y,int *map1)
{


    if(*(map1+(y*Map_Width+x))==5)
    return true;
    else
    return false;



}
