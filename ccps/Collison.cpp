#include"al_header.h"
bool Collison(float x,float y,int width,int height,int *map1,int *moveSpeed,int *power,int *ballnum, bool *ManOnBall,bool *ghost)
{/*
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

int X=x,Y=y;
    int i=0;
    for(int my = 0;my < Map_Height;my++)
    {
        for(int mx = 0;mx < Map_Width;mx++)
        {
            if((*(map1+(my*Map_Width+mx)) <=29  && *(map1+(my*Map_Width+mx))>20)||(*(map1+(my*Map_Width+mx))<20&&*(map1+(my*Map_Width+mx))>9 ))
            {

                if( x + 25 <= mx*STUFFS_SIZE || x - 25 >= mx*STUFFS_SIZE+width || y + height - 25 <= my*STUFFS_SIZE || y - 25 >= my*STUFFS_SIZE + height)
                {
                    i+=0;

                }else i++;
            }
        }
    }

    //===================================   Block  �� �y
        for(int my = 0;my < Map_Height;my++)
    {
        for(int mx = 0;mx < Map_Width;mx++)
        {
            if(*(map1+(my*Map_Width+mx)) ==Bomb20 && *ManOnBall==false&&*(map1+(Y/50*Map_Width+X/50))!=Bomb20)
            {

                if( x + 25<= mx*STUFFS_SIZE || x - 25 >= mx*STUFFS_SIZE+width || y + height - 25 <= my*STUFFS_SIZE || y - 25 >= my*STUFFS_SIZE + height)
                {
                    i+=0;

                }else i++;
            }

        }
    }
    //==================================================================                 �Y �F ��
       for(int my = 0;my < Map_Height;my++)
    {
        for(int mx = 0;mx < Map_Width;mx++)
        {
            if(*(map1+(my*Map_Width+mx)) < 0)
            {

                if( x + 15 >= mx*STUFFS_SIZE && x - 15 <= mx*STUFFS_SIZE+width && y +15 >= my*STUFFS_SIZE && y - 15 <= my*STUFFS_SIZE + height)
                {
                  if(*(map1+(my*Map_Width+mx))==-1)
                  {
                      if(*ballnum<maxball)
                      *ballnum+=1;
                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-2)
                  {
                      if(*moveSpeed<maxspeed)
                      *moveSpeed+=1;
                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-3)
                  {
                      if(*power<maxpower)
                      *power+=1;
                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-4)
                  {
                      *ghost=true;
                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-5)
                  {
                      *power-=2;
                      *moveSpeed-=2;
                      *ballnum-=1;
                      if(*power<1)
                        *power=1;
                      if(*moveSpeed<1)
                        *moveSpeed=1;
                      if(*ballnum<1)
                        *ballnum=1;


                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-6)
                  {
                      *power=7;
                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-7)
                  {
                      *moveSpeed=maxspeed;
                      *(map1+(my*Map_Width+mx))=0;
                  }
                  if(*(map1+(my*Map_Width+mx))==-8)
                  {

                      *(map1+(my*Map_Width+mx))=0;
                  }                        }
/*	for(d=1;d<=60;d++)//�Žc
	{
	    cards[d-1]=0;
	}
	for(d=51;d<=62;d++)//���y
	{
	    cards[d-1]=-1;
	}
	for(d=63;d<=68;d++)//�t��
	{
	    cards[d-1]=-2;
	}
	for(d=69;d<=73;d++)//�¤O
	{
	    cards[d-1]=-3;
	}
	for(d=74;d<=79;d++)//����
	{
	    cards[d-1]=-4;
	}
	for(d=80;d<=90;d++)//���r
	{
	    cards[d-1]=-5;
	}
	for(d=92;d<=93;d++)//max
	{
	    cards[d-1]=-6;
	}
	cards[94]=-8;//SkyRun

    for(d=46;d<=50;d++)//save
    {
        cards[d-1]=-7;
    }
*/


                }

            }


        }

    if(i>0)

    return true;
    return false;



}
