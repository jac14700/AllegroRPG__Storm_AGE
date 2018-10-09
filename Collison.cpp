#include"al_header.h"
bool Collison(float x,float y,int width,int height,int *map1,int *moveSpeed,int *power,int *ballnum, bool *ManOnBall,bool *ghost)
{/*
<0 道具
0~4可通過 炸不到
5~9可通過 炸的了
10~19不可通過 可炸
20~29不可通過 不可炸
0             10 木箱      20 水球
1             11 樹        21 藍房子
2             12 紅積木    22 紅房子
3             13 橘積木    23 黃房子
4             14           24
5樹叢         15           25
6             16           26
7             17           27
8             18           28
9             19           29 遊戲之外*/

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

    //===================================   Block  水 球
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
    //==================================================================                 吃 東 西
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
/*	for(d=1;d<=60;d++)//空箱
	{
	    cards[d-1]=0;
	}
	for(d=51;d<=62;d++)//水球
	{
	    cards[d-1]=-1;
	}
	for(d=63;d<=68;d++)//速度
	{
	    cards[d-1]=-2;
	}
	for(d=69;d<=73;d++)//威力
	{
	    cards[d-1]=-3;
	}
	for(d=74;d<=79;d++)//隱身
	{
	    cards[d-1]=-4;
	}
	for(d=80;d<=90;d++)//中毒
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
