#include"al_header.h"
bool ifthereisAball(int x,int y,int *map1)
{
    if(*(map1+(y*Map_Width+x))==20)
    {
        printf("YYY");
        return true;
    }
    else
    return false;

}
