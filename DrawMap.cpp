 #include"al_header.h"
 #include"openVarible.h"


void DrawMap(int *map1/*,int sourceX,int sourceY,float p1x,float p1y,*/)
{

ALLEGRO_BITMAP *bombpic = al_load_bitmap("bombpicture.png");
ALLEGRO_BITMAP *ghost = al_load_bitmap("ghost.png");
ALLEGRO_BITMAP *dievl = al_load_bitmap("dievl.png");
ALLEGRO_BITMAP *reddeivl = al_load_bitmap("reddeivl.png");
ALLEGRO_BITMAP *Maxpower = al_load_bitmap("Maxpower.png");
ALLEGRO_BITMAP *SkyRun = al_load_bitmap("SkyRun.png");
ALLEGRO_BITMAP *power = al_load_bitmap("power.png");
ALLEGRO_BITMAP *Speed = al_load_bitmap("Speed.png");

ALLEGRO_BITMAP *Board = al_load_bitmap("Board.png");//
ALLEGRO_BITMAP *yellowhouse = al_load_bitmap("yellowhouse.png");//
ALLEGRO_BITMAP *redhouse = al_load_bitmap("redhouse.png");//
ALLEGRO_BITMAP *orangebrick = al_load_bitmap("orangebrick.png");//
ALLEGRO_BITMAP *woodbrick = al_load_bitmap("woodbrick.png");//
ALLEGRO_BITMAP *three = al_load_bitmap("three.png");
ALLEGRO_BITMAP *green = al_load_bitmap("green.png");
ALLEGRO_BITMAP *brunch = al_load_bitmap("brunch.png");
ALLEGRO_BITMAP *gray = al_load_bitmap("gray.png");//
ALLEGRO_BITMAP *redbrick = al_load_bitmap("redbrick.png");//
ALLEGRO_BITMAP *gray_Line = al_load_bitmap("gray_Line.png");//
ALLEGRO_BITMAP *bluehouse = al_load_bitmap("bluehouse.png");
ALLEGRO_BITMAP *icon1 = al_load_bitmap("icon1.png");//
ALLEGRO_BITMAP *icon2 = al_load_bitmap("icon2.png");//



al_draw_bitmap(Board,STUFFS_SIZE*(Map_Width-1),STUFFS_SIZE,0);
al_draw_bitmap(icon1,STUFFS_SIZE*(Map_Width-1)+47,STUFFS_SIZE+113,0);
al_draw_bitmap(icon2,STUFFS_SIZE*(Map_Width-1)+47,STUFFS_SIZE+157,0);

for(int j=1;j<14;j++)
    {
        for(int i=1;i<=6;i++)
           {
               al_draw_bitmap(green,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
        }
    }
for(int j=1;j<14;j++)
    {
        for(int i=7;i<=7;i++)
           {
               al_draw_bitmap(gray,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
        }
    }
for(int j=1;j<14;j++)
    {
        for(int i=8;i<=8;i++)
           {
               al_draw_bitmap(gray_Line,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
        }
    }
    for(int j=1;j<14;j++)
    {
        for(int i=9;i<=9;i++)
           {
               al_draw_bitmap(gray,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
        }
    }for(int j=1;j<14;j++)
    {
        for(int i=10;i<=15;i++)
           {
               al_draw_bitmap(green,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
        }
    }
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

                    for(int j = 0;j <Map_Height;j++)// y
                    {
                        for(int i = 0;i <Map_Width;i++)// x
                            {
                            if (*(map1+(j*Map_Width+i))==5)//
                                            al_draw_bitmap(brunch,i*STUFFS_SIZE ,j*STUFFS_SIZE-10,0);
                            if (*(map1+(j*Map_Width+i))==10)//
                                            al_draw_bitmap(woodbrick,i*STUFFS_SIZE ,j*STUFFS_SIZE-5,0);
                            if (*(map1+(j*Map_Width+i))==24)//
                                            al_draw_bitmap(three,i*STUFFS_SIZE ,j*STUFFS_SIZE-5,0);
                            if (*(map1+(j*Map_Width+i))==12)//
                                            al_draw_bitmap(redbrick,i*STUFFS_SIZE ,j*STUFFS_SIZE-5,0);
                            if (*(map1+(j*Map_Width+i))==13)//
                                            al_draw_bitmap(orangebrick,i*STUFFS_SIZE ,j*STUFFS_SIZE-5,0);
                            if (*(map1+(j*Map_Width+i))==21)//
                                            al_draw_bitmap(bluehouse,i*STUFFS_SIZE ,j*STUFFS_SIZE-19,0);
                            if (*(map1+(j*Map_Width+i))==22)//
                                            al_draw_bitmap(redhouse,i*STUFFS_SIZE ,j*STUFFS_SIZE-19,0);
                            if (*(map1+(j*Map_Width+i))==23)//
                                            al_draw_bitmap(yellowhouse,i*STUFFS_SIZE ,j*STUFFS_SIZE-19,0);

                            ///////////////////////////////////////////////////////////////////////////

                            if(*(map1+(j*Map_Width+i))==-1)
                                al_draw_bitmap(bombpic,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-3)
                                al_draw_bitmap(power,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-2)
                                al_draw_bitmap(Speed,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-4)
                                al_draw_bitmap(ghost,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-5)
                                al_draw_bitmap(dievl,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-6)
                                al_draw_bitmap(Maxpower,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-7)
                                al_draw_bitmap(reddeivl,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);
                            if(*(map1+(j*Map_Width+i))==-8)
                                al_draw_bitmap(SkyRun,i*STUFFS_SIZE ,j*STUFFS_SIZE,0);

                        }
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

    al_destroy_bitmap(bombpic);
    al_destroy_bitmap(power);
    al_destroy_bitmap(Speed);
    al_destroy_bitmap(reddeivl);
    al_destroy_bitmap(ghost);
    al_destroy_bitmap(dievl);
    al_destroy_bitmap(SkyRun);
    al_destroy_bitmap(Maxpower);

    al_destroy_bitmap(Board);
    al_destroy_bitmap(icon1);
    al_destroy_bitmap(icon2);
    al_destroy_bitmap(yellowhouse);
    al_destroy_bitmap(redhouse);
    al_destroy_bitmap(orangebrick);
    al_destroy_bitmap(woodbrick);
    al_destroy_bitmap(brunch);
    al_destroy_bitmap(three);
    al_destroy_bitmap(green);
    al_destroy_bitmap(gray);
    al_destroy_bitmap(gray_Line);
    al_destroy_bitmap(redbrick);
    al_destroy_bitmap(bluehouse);

}
