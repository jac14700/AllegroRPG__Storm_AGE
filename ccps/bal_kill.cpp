#include"al_header.h"
void ball_killer(int x,int y,ALLEGRO_COLOR Red,int pl_x1,int pl_y1,int pl_x2,int pl_y2,int *player1die,int * suicide,int *player2die,int *kill,int power,int *map1
                 ,int *powerU,int *powerD,int *powerR,int *powerL,int * tools,int player)
{
///�洫�ˬd��K
int PX,PY,tmp=99;

///�u��x,y�Ȧs
x=x/STUFFS_SIZE;
y=y/STUFFS_SIZE;
int temp_x=x,temp_y=y;
///�u��x,y
int origin_x1=pl_x1;
int origin_y1=pl_y1;
int origin_x2=pl_x2;
int origin_y2=pl_y2;
///�d�j���B�ܰ��z���¤O���ܼ�
int countPower=0;


pl_x1=pl_x1/STUFFS_SIZE;
pl_y1=pl_y1/STUFFS_SIZE;
pl_x2=pl_x2/STUFFS_SIZE;
pl_y2=pl_y2/STUFFS_SIZE;




*(map1+(y*Map_Width+x))=0;/*
<0 �D��
0~4�i�q�L ������
5~9�i�q�L �����F
10~19���i�q�L �i��
20~29���i�q�L ���i��
0             10 ��c      20 ���y
1             11 ��        21 �ũФl
2             12 ���n��    22 ���Фl
3             13 ��n��    23 ���Фl
4             14           24
5���O         15           25
6             16           26
7             17           27
8             18           28
9             19           29 �C�����~*/

// �B�zy --
do{
    y--;
    if(*(map1+(y*Map_Width+x))>9&&*(map1+(y*Map_Width+x))<20)// ��ܦ��c�l�i�H��
    {
        for(int i=0;i<95;i++)
        {
           if(*(tools+i)!=0)
           {
               tmp=*(tools+i);
               *(tools+i)=0;
               break;
           }
        }
        if(tmp!=99)
        *(map1+(y*Map_Width+x))=tmp;
        break;
    }
    if(*(map1+(y*Map_Width+x))>20)
    {
        break;
    }
    if(*(map1+(y*Map_Width+x))<0)
    {
        *(map1+(y*Map_Width+x))=0;
        countPower++;
    }
    if(*(map1+(y*Map_Width+x))<10)
    {
        if(*(map1+(y*Map_Width+x))==5)
            *(map1+(y*Map_Width+x))=0;
        countPower++;
    }


  }while(countPower<power) ;
  *powerU=countPower;
  countPower=0;
  y=temp_y;


//�B�zy++
do{
    y++;
    if(*(map1+(y*Map_Width+x))>9&&*(map1+(y*Map_Width+x))<20)// ��ܦ��c�l�i�H��
    {
        for(int i=0;i<95;i++)
        {
           if(*(tools+i)!=0)
           {
               tmp=*(tools+i);
               *(tools+i)=0;
               break;
           }
        }
        if(tmp!=99)
        *(map1+(y*Map_Width+x))=tmp;
        break;
    }    if(*(map1+(y*Map_Width+x))>20)
    {
        break;
    }
    if(*(map1+(y*Map_Width+x))<0)
    {
       *(map1+(y*Map_Width+x))=0;

    }
    if(*(map1+(y*Map_Width+x))<10)
    {
        if(*(map1+(y*Map_Width+x))==5)
            *(map1+(y*Map_Width+x))=0;
        countPower++;
    }
  }while(*(map1+(y*Map_Width+x))<1&&countPower<power) ;
  *powerD=countPower--;
  countPower=0;
  y=temp_y;


//�B�zx++
do{
    x++;
    if(*(map1+(y*Map_Width+x))>9&&*(map1+(y*Map_Width+x))<20)// ��ܦ��c�l�i�H��
    {
        for(int i=0;i<95;i++)
        {
           if(*(tools+i)!=0)
           {
               tmp=*(tools+i);
               *(tools+i)=0;
               break;
           }
        }
        if(tmp!=99)
        *(map1+(y*Map_Width+x))=tmp;
        break;
    }
    if(*(map1+(y*Map_Width+x))>20)
    {
        break;
    }
    if(*(map1+(y*Map_Width+x))<0)
    {
       *(map1+(y*Map_Width+x))=0;

    }
    if(*(map1+(y*Map_Width+x))<10)
    {
        if(*(map1+(y*Map_Width+x))==5)
            *(map1+(y*Map_Width+x))=0;
        countPower++;
    }
  }while(*(map1+(y*Map_Width+x))<1&&countPower<power) ;
  *powerR=countPower--;
  countPower=0;
  x=temp_x;

//�B�zx--
do{
    x--;
    if(*(map1+(y*Map_Width+x))>9&&*(map1+(y*Map_Width+x))<20)// ��ܦ��c�l�i�H��
    {
        for(int i=0;i<95;i++)
        {
           if(*(tools+i)!=0)
           {
               tmp=*(tools+i);
               *(tools+i)=0;
               break;
           }
        }
        if(tmp!=99)
        *(map1+(y*Map_Width+x))=tmp;
        break;
    }
    if(*(map1+(y*Map_Width+x))>20)
    {
        break;
    }
    if(*(map1+(y*Map_Width+x))<0)
    {
      *(map1+(y*Map_Width+x))=0;

    }
    if(*(map1+(y*Map_Width+x))<10)
    {
        if(*(map1+(y*Map_Width+x))==5)
            *(map1+(y*Map_Width+x))=0;
        countPower++;
    }
  }while(*(map1+(y*Map_Width+x))<1&&countPower<power) ;
  *powerL=countPower--;
  countPower=0;
  x=temp_x;


int orginP1die=*player1die;
int orginP2die=*player2die;

///////////////////////////          �ˬdP2

//////�ˬdP2
PX=origin_x2;
PY=origin_y2;
    if((x-*powerL)*STUFFS_SIZE<=PX&&(x+1+*powerR)*STUFFS_SIZE>=PX)
    {
        if(y*STUFFS_SIZE<=PY&&(y+1)*STUFFS_SIZE>=PY)
        {
            *player2die = 1;

        }
    }

    if((y-*powerU)*STUFFS_SIZE<=PY&&(y+*powerD+1)*STUFFS_SIZE>=PY)
    {
        if((x)*STUFFS_SIZE<=PX&&(x+1)*STUFFS_SIZE>=PX)
        {
            *player2die = 1;

        }

    }
/////�ˬdP1

PX=origin_x1;
PY=origin_y1;
    if((x-*powerL)*STUFFS_SIZE<=PX&&(x+1+*powerR)*STUFFS_SIZE>=PX)
    {
        if(y*STUFFS_SIZE<=PY&&(y+1)*STUFFS_SIZE>=PY)
        {
            *player1die = 1;
            }

    }

    if((y-*powerU)*STUFFS_SIZE<=PY&&(y+*powerD+1)*STUFFS_SIZE>=PY)
    {
        if((x)*STUFFS_SIZE<=PX&&(x+1)*STUFFS_SIZE>=PX)
        {
            *player1die = 1;


            }
    }

if(player==0)
{
    if(*player1die-orginP1die==1)
        *suicide+=1;
    if(*player2die-orginP2die==1)
        *kill+=1;
}
else if(player==1)
{
    if(*player1die-orginP1die==1)
        *kill+=1;
    if(*player2die-orginP2die==1)
        *suicide+=1;
}
    }

