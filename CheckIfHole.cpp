#include"al_header.h"
int CheckIfHole(int * x,int * y,int *map1,int dir)
{
   int RightorLeft_x = *x%50;
   int RightorLeft_y= *y%50;

int   x1=*x/50;
int   y1=*y/50;
   switch(dir)
   {
  //enum Direction{ UP, DOWN, RIGHT, LEFT};¤À§O¬O0 1 2 3
/*
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
case 0:
    {
      if(*(map1+((y1-1)*Map_Width+(x1+1)))>9)//右上有東西
        if(*(map1+((y1-1)*Map_Width+(x1)))<10)//上面沒有東西
         if(RightorLeft_x>25)
            {printf("Yes1,%d\n",RightorLeft_x);
                if(RightorLeft_x==26)
                {
                 *x=x1*STUFFS_SIZE+25;
                 break;
                }

                *x-=1;;//緩向左
            }

       if(*(map1+((y1-1)*Map_Width+(x1)))>9)//上邊有東西
        if(*(map1+((y1-1)*Map_Width+(x1-1)))<10)//左上沒有東西
         if(*(map1+((y1)*Map_Width+(x1-1)))<10)
          if(RightorLeft_x<=20)//偏下
           {printf("Yes2");
                *x-=2;//快向左
           }
       if(*(map1+((y1-1)*Map_Width+(x1-1)))>9)//左上有東西
        if(*(map1+((y1-1)*Map_Width+(x1)))<10)//上邊沒東西
         if(RightorLeft_x<25)//偏上
         {printf("Yes,%d\n",RightorLeft_x);
            if(RightorLeft_x==24)
                {
                 *x=x1*STUFFS_SIZE+25;
                 break;
                }
                *x+=1;//緩向右
         }
       if(RightorLeft_x>=30)
        if(*(map1+((y1-1)*Map_Width+(x1+1)))<10)//右上沒東西
         if(*(map1+((y1-1)*Map_Width+(x1)))>9)//上面有東西
          if(*(map1+((y1)*Map_Width+(x1+1)))<10)//右邊沒東西
           {printf("Yes3");
                *x+=2;;//快向右
           }
           else return -1;

case 1:
    {
       if(*(map1+((y1+1)*Map_Width+(x1-1)))>9)//左下有東西
        if(*(map1+((y1+1)*Map_Width+(x1)))<10)//下面沒東西
         if(RightorLeft_x<25)
           *x+=1;

       if(RightorLeft_x>=30)
        if(*(map1+((y1+1)*Map_Width+(x1)))>9)//下面有東西
         if(*(map1+((y1+1)*Map_Width+(x1+1)))<10)//右下沒東西
          if(*(map1+((y1)*Map_Width+(x1+1)))<10)//右邊沒東西
            *x+=2;

       if(*(map1+((y1+1)*Map_Width+(x1+1)))>9)//右下有東西
        if(*(map1+((y1+1)*Map_Width+(x1)))<10)//下面沒東西
         if(RightorLeft_x>25)
            *x-=1;

       if(RightorLeft_x<=20)
         if(*(map1+((y1+1)*Map_Width+(x1)))>9)//下面有東西
        if(*(map1+((y1+1)*Map_Width+(x1-1)))<10)//左下沒東西
          if(*(map1+(y1*Map_Width+(x1-1)))<10)//左邊沒東西
           *x-=2;

   break;
    }
   case 2:
    {
      if(*(map1+((y1-1)*Map_Width+(x1+1)))>9)//右上有東西
        if(*(map1+((y1)*Map_Width+(x1+1)))<10)//右邊沒有東西
         if(RightorLeft_y<25)
            {
                *y+=1;;//緩向下

            }

       if(*(map1+((y1)*Map_Width+(x1+1)))>9)//右邊有東西
        if(*(map1+((y1+1)*Map_Width+(x1+1)))<10)//右下沒有東西
         if(*(map1+((y1+1)*Map_Width+(x1)))<10)//下面沒東西
          if(RightorLeft_y>=30)//偏下
           {
                printf("1\n");
                *y+=2;//快向下
           }
       if(*(map1+((y1+1)*Map_Width+(x1+1)))>9)//右下有東西
        if(*(map1+((y1)*Map_Width+(x1+1)))<10)//右邊沒東西
         if(RightorLeft_y>25)//偏上
         {
                printf("2\n");
                *y-=1;//緩向上
         }
       if(RightorLeft_y<=20)
        if(*(map1+((y1-1)*Map_Width+(x1+1)))<10)//右上沒東西
         if(*(map1+((y1-1)*Map_Width+(x1)))<10)//下面沒東西
          if(*(map1+((y1)*Map_Width+(x1+1)))>9)//右邊有東西
           {
                printf("3\n");
                *y-=2;;//快向上
           }

    break;
    }

   case 3:
       {
    ///     左上 超過一半
       if(*(map1+((y1-1)*Map_Width+(x1-1)))>9)//左上有東西
        if(*(map1+((y1*Map_Width+(x1-1))))<10)//左邊沒東西
         if(RightorLeft_y<25)
            *y+=1;


    ///
       if(RightorLeft_y>=30)
        if(*(map1+((y1)*Map_Width+(x1-1)))>9)//左邊有東西
         if(*(map1+((y1+1)*Map_Width+(x1-1)))<10)//左下沒東西
          if(*(map1+((y1+1)*Map_Width+(x1)))<10)//下面沒東西
           *y+=2;//快向下
    ///上半部
       if(RightorLeft_y<=20)
        if(*(map1+((y1)*Map_Width+(x1-1)))>9)//左邊有東西
         if(*(map1+((y1-1)*Map_Width+(x1-1)))<10)//左上沒東西
          if(*(map1+((y1-1)*Map_Width+(x1)))<10)//上面沒東西
            *y-=2;//快向上
    ///
       if(*(map1+((y1+1)*Map_Width+(x1-1)))>9)
        if(*(map1+((y1)*Map_Width+(x1-1)))<10)
         if(RightorLeft_y>25)
            *y-=1;


    break;
    }
    }
 }
}
