#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include"al_header.h"
#include"structs.h"
#include"flie_list.h"
#include"openVarible.h"


#define ScreenWidth 1024
#define ScreenHeight 768
#define MLbsourse 65
#define MLsource 205
using namespace std;

void cameraUpdate(float *cameraPosition,float x,float y,int Width,int Height)
{
    cameraPosition[0]=-(ScreenWidth/2)+(x+Width/2);
    cameraPosition[2]=-(ScreenHeight/2)+(x+Height/2);
    if(cameraPosition[0]<0)
        cameraPosition[0]=0;
    if(cameraPosition[1]<0)
        cameraPosition[1]=0;
    if(cameraPosition[0]>780)
        cameraPosition[0]=780;

}


int main()
{
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_audio();
    al_init_acodec_addon();
    ALLEGRO_DISPLAY *display=al_create_display(ScreenWidth,ScreenHeight);

    if(!al_init())
        al_show_native_message_box(NULL,"Error",NULL,"Could not Initialize Allegro",NULL,NULL);

al_set_new_display_flags(ALLEGRO_OPENGL);
al_set_window_position(display,200,0);//window位置的放置
al_set_window_title(display,"LastBoss program");//window的名稱
    if(!display)
        al_show_native_message_box(NULL,"Error",NULL,"Could not Initialize Allegro",NULL,NULL);

    bool done=false,draw=true,active=false,mactive=false,mifRight=false;

    //= rand() % 2;

    enum Direction {DOWN,LEFT,RIGHT,UP};
    const float FPS=60.0;
    const float frameFPS=15.0;
    float degrees=0.0f;
    float scale =1.0f;

    float x=10,y=10,mx=500,my=480,moveSpeed=5,mmoveSpeed=3;
    float velx,vely,mvelx,mvely;
          velx=vely=mvelx=mvely=0;
    int dir=DOWN,sourceX=50,sourceY=0,mLsourceX=205,mLbsourceX=65,mRsourceX=0,mRbsourceX=0,Hp=1000,hurt;;//向左是用減的.向又是用家的
    //
    int mdir=0;//0是Left,1是Right

    bool jump = false;

    float jumpSpeed = 12;

    const float gravity=1;
    float cameraPosition[2]={0,0};
    float comparison[2]={0,0};
    int i=0,j=0;

    al_init_image_addon();
    al_install_keyboard();
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();
    ALLEGRO_BITMAP *background=al_load_bitmap("background.png");
    ALLEGRO_BITMAP *escape=al_load_bitmap("escape.png");
    ALLEGRO_BITMAP *statement=al_load_bitmap("statement.png");
    ALLEGRO_BITMAP *babyleft=al_load_bitmap("babyleft.png");
    ALLEGRO_BITMAP *babybreathright=al_load_bitmap("babybreathright.png");
    ALLEGRO_BITMAP *babybreathleft=al_load_bitmap("babybreathleft.png");
    ALLEGRO_BITMAP *mush_state=al_load_bitmap("mush_state.png");
    ALLEGRO_BITMAP *aegis=al_load_bitmap("aegis.png");
    ALLEGRO_BITMAP *name=al_load_bitmap("name.png");

    ALLEGRO_BITMAP *GAMEOVER=al_load_bitmap("GAMEOVER.png");

    ALLEGRO_BITMAP *babyright=al_load_bitmap("babyright.png");
    ALLEGRO_BITMAP *player=al_load_bitmap("PlayerImage1.png");
    ALLEGRO_BITMAP *fire=al_load_bitmap("fire.png");
    ALLEGRO_TIMER *timer=al_create_timer(1.0/FPS);
    ALLEGRO_TIMER *frameTimer = al_create_timer(1.0/frameFPS);
    ALLEGRO_EVENT_QUEUE *event_queue=al_create_event_queue();
    ALLEGRO_SAMPLE *C8763 =al_load_sample("C8763.wav");
    ALLEGRO_SAMPLE *wolo =al_load_sample("30 Wololo.wav");
    ALLEGRO_FONT *fonte = al_load_ttf_font("ARCHRISTY.ttf", 24, 0);
    ALLEGRO_FONT *fonte1 = al_load_ttf_font("ARCHRISTY.ttf", 48, 0);
    ALLEGRO_SAMPLE *menumusic = al_load_sample("menumusic.wav");
    ALLEGRO_SAMPLE *yes = al_load_sample("01 Yes.wav");
    ALLEGRO_SAMPLE *roggan = al_load_sample("29 Roggan.wav");
    ALLEGRO_SAMPLE *please = al_load_sample("05 Gold, PLease.wav");
    ALLEGRO_SAMPLE *herb = al_load_sample("11 Herb laugh.wav");
    ALLEGRO_SAMPLE_ID id;
    al_reserve_samples(6);


    ALLEGRO_KEYBOARD_STATE keyState;

    ALLEGRO_TRANSFORM camera;

    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_register_event_source(event_queue,al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_keyboard_event_source());







    al_draw_bitmap(name,0,0,0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    al_rest(4);
    al_draw_bitmap(aegis,0,0,0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    al_rest(3);






    al_play_sample(menumusic, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &id);
    al_start_timer(timer);
    al_start_timer(frameTimer);

    while(!done)
    {

        ALLEGRO_EVENT events;
        al_wait_for_event(event_queue,&events);
        al_get_keyboard_state(&keyState);
        al_draw_bitmap(background,0,0,NULL);



        if(Hp<=0)
        {

            done=true;

        }
        if(events.type==ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done=true;
        }
        else if(events.type==ALLEGRO_EVENT_TIMER)
        {

           if(events.timer.source==timer)
           {
            active=true;


            if(al_key_down(&keyState,ALLEGRO_KEY_ENTER))
            {
                if(x>=1317&&x<=1417&&y<=180&&y>=175)
                    {al_play_sample(C8763, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                         cameraPosition[0]=-SCREEN_W;
                        cameraPosition[2]=-(SCREEN_H/2)+(x+50/2);
                        if(cameraPosition[0]<0)
                            cameraPosition[0]=0;
                        if(cameraPosition[1]<0)
                            cameraPosition[1]=0;
                        if(cameraPosition[0]>780)
                            cameraPosition[0]=780;
                        al_identity_transform(&camera);
                        al_translate_transform(&camera,-cameraPosition[0],-cameraPosition[1]);
                        al_use_transform((&camera));
                        al_stop_sample(&id);

                        al_stop_timer(timer);
                        al_stop_timer(frameTimer);
                        GAMANIA(display);
                        al_play_sample(menumusic, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &id);
                        al_start_timer(timer);
                        al_start_timer(frameTimer);

                    }
                    else if(x>400&&x<=460&&y<=490&&y>=480)
                    {
                        cameraPosition[0]=-SCREEN_W;
                        cameraPosition[2]=-(SCREEN_H/2)+(x+50/2);
                        if(cameraPosition[0]<0)
                            cameraPosition[0]=0;
                        if(cameraPosition[1]<0)
                            cameraPosition[1]=0;
                        if(cameraPosition[0]>780)
                            cameraPosition[0]=780;
                        al_identity_transform(&camera);
                        al_translate_transform(&camera,-cameraPosition[0],-cameraPosition[1]);
                        al_use_transform((&camera));
                        al_stop_timer(timer);
                        al_stop_timer(frameTimer);
                        gameR(display);
                        al_start_timer(timer);
                        al_start_timer(frameTimer);

                    }
                    else if(x>=970&&x<=1070&&y<=490&&y>=480)
                    {   al_play_sample(C8763, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        cameraPosition[0]=-SCREEN_W;
                        cameraPosition[2]=-(SCREEN_H/2)+(x+50/2);
                        if(cameraPosition[0]<0)
                            cameraPosition[0]=0;
                        if(cameraPosition[1]<0)
                            cameraPosition[1]=0;
                        if(cameraPosition[0]>780)
                            cameraPosition[0]=780;



                        al_identity_transform(&camera);
                        al_translate_transform(&camera,-cameraPosition[0],-cameraPosition[1]);
                        al_use_transform((&camera));
                        al_stop_sample(&id);
                        al_stop_timer(timer);
                        al_stop_timer(frameTimer);
                        GAMANIA1(display);
                        al_play_sample(menumusic, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &id);
                        al_play_sample()
                        al_start_timer(timer);
                        al_start_timer(frameTimer);

                    }
                    else if(x>=0&&x<=150&&y<=250&&y>=100)
                    {
                        al_play_sample(roggan, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    }
                    else if(x>=30&&x<=125&&y<=542&&y>=460)
                    {
                        al_play_sample(yes, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    }
                    else if(x>=387&&x<=504&&y<=389&&y>=287)
                    {
                        al_play_sample(please, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    }
                    else if(x>=1588&&x<=1678&&y<=610&&y>=500)
                    {
                        al_play_sample(herb, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                    }
            }

            if(al_key_down(&keyState,ALLEGRO_KEY_ESCAPE))
            {
                done=true;
            }
            if(al_key_down(&keyState,ALLEGRO_KEY_RIGHT))
            {
                velx=moveSpeed;
                dir=RIGHT;
            }

            else if(al_key_down(&keyState,ALLEGRO_KEY_LEFT))
            {
                velx=-moveSpeed;
                dir=LEFT;
            }

            else
            {
                velx=0;
                active=false;
            }
//處理mbaby的是不是active
j++;



if(j%100==0)
{
mactive=rand()%2;
}

if(mactive)
{
 if(j%100==0)
    mifRight=rand()%2;
 if(mifRight)//四分之一秒
 {
     if(j%10==0)
     mRsourceX+=68;
     mvelx=mmoveSpeed;
 }
 if(!mifRight)
 {if(j%10==0)
 mLsourceX -=68;
     mvelx=-mmoveSpeed;
 }
}

if(!mactive)//一秒鐘呼吸兩下，若沒有前進則播放呼吸圖
{
 mvelx=0;
 if(mifRight&&j/15==0)
 {
 mRbsourceX+= al_get_bitmap_width(babybreathright)/2;
 }
 if(!mifRight&&j/15==0)
 {
 mLbsourceX-= al_get_bitmap_width(babybreathleft)/2;
 }
}
 if(mRbsourceX >= al_get_bitmap_width(babybreathright))
                mRbsourceX = 0;
if(mLsourceX <= 0)
                mLsourceX = MLsource;
 if(mRsourceX >= al_get_bitmap_width(babyright))
                mRsourceX = 0;
 if(mLbsourceX <=0)
                mLbsourceX =MLbsourse ;
mx+=mvelx;

        if(al_key_down(&keyState,ALLEGRO_KEY_UP)&&jump)
            {
                vely = -jumpSpeed;
                jump = false;
            }

            if(active)
                sourceX += al_get_bitmap_width(player)/4;

            else
                sourceX=50;
            if(sourceX >= al_get_bitmap_width(player))
                sourceX = 0;
            sourceY = dir;

            if(!jump)
                    vely += gravity;

            else
            vely = 0;

            x += velx;
            y += vely;

            jump = (y>=545);/*545 is ground*/
            if(jump)
            {
                if(y <= 545)
                {
                    true;
                }
                y = 545;

            }
            if(x>=-10&&x<=1400&&y>490)//地底
            {
                for(y=491;y>490;y--)
                {
                    jump=false;
                }
            }
            if(x>mx&&x<mx+68)
            {
                if(y>=480&&y<530)
                {
                    hurt=rand()%10;
                    if(mifRight)
                        x+=20;
                    if(!mifRight)
                        x-=20;
                    y-=25;
                    Hp-=hurt;

            al_draw_textf(fonte1, al_map_rgb(255,17,0),x,y-90, ALLEGRO_ALIGN_CENTRE, "-%d",hurt);

                }
            }
            if(mx>1450)//右邊邊界
            {
                mx=1450;
            }

            if(mx<-5)//左邊邊界
            {
                mx=-5;
            }

            if(x>=-5&&x<=1450&&y>490)//平台邊界
            {
                x=1450;
            }
            if(x>1765)//右邊邊界
            {
                x=1765;
            }
            if(x<-5)//左邊邊界
            {
                x=-5;
            }

            if(x>=-5&&x<=1440&&y<=490&&y>=489)//大平台//360~635
            {
                if(x>=360&&x<635)
                    al_draw_bitmap(mush_state,530,105,NULL);
                jump=true;
            }
            if(x>=100&&x<=190&&y<485&&y>=450)//左下角平台
            {
                jump=true;
            }
            if(x>190&&x<=280&&y<=400&&y>=390)//左二平台
            {
                jump=true;
            }
            if(x>280&&x<=600&&y<=340&&y>=330)//中間大平台
            {
                jump=true;

                al_draw_bitmap(escape,530,105,NULL);
            }
            if(x>600&&x<=690&&y<=400&&y>=390)//右2平台
            {

                jump=true;
            }
            if(x>690&&x<=780&&y<485&&y>=450)//右下角平台
            {
                jump=true;
            }
            if(x>=100&&x<=235&&y<=280&&y>=270)//左上角平台
            {
                jump=true;
            }
            if(x>=130&&x<=180&&y<=225&&y>=220)//左上角平台的石碑
            {
                jump=true;
            }
            if(x>=-5&&x<=130&&y<=155&&y>=150)//有NPC的平台
            {
                jump=true;
            }
            if(x>=645&&x<=780&&y<=280&&y>=270)//右上角平台
            {
                al_draw_bitmap(statement,530,105,NULL);
                jump=true;
            }
            if(x>=1350&&x<=1385&&y<=425&&y>=424)//樓梯第一階
            {
                jump=true;
            }
            if(x>=1350&&x<=1385&&y<=360&&y>=359)//樓梯第二階
            {
                jump=true;
            }
            if(x>=1350&&x<=1385&&y<=315&&y>=314)//樓梯第三階
            {
                jump=true;
            }
            if(x>=1350&&x<=1385&&y<=270&&y>=269)//樓梯第四階
            {
                jump=true;
            }
            if(x>=1350&&x<=1385&&y<=225&&y>=224)//樓梯第五階
            {
                jump=true;
            }
            if(x>=1300&&x<=1720&&y<=180&&y>=175)//弓箭手雕像平台
            {
                jump=true;
            }

            draw = true;

            cameraUpdate(cameraPosition,x,y,50,50);
            al_identity_transform(&camera);
            al_translate_transform(&camera,-cameraPosition[0],-cameraPosition[1]);
            al_use_transform((&camera));

        }
        else if(events.timer.source==frameTimer)
        {
            if(active)
                sourceX +=al_get_bitmap_width(player)/4;
            else
                sourceX=200;
            if(sourceX >al_get_bitmap_width(player))
                sourceX=0;

            sourceY=dir;
        }

            i++;
            if(i%10<10)
            {
                al_draw_bitmap_region(fire,(i/4%4)*80, 0,80,97,1000,431,NULL);
                al_draw_bitmap_region(fire,(i/4%4)*80, 0,80,97,400,431,NULL);
                al_draw_bitmap_region(fire,(i/4%4)*80, 0,80,97,1317,135,NULL);
            }

            draw=true;
        }
//printf("mx,my=%d %d",mx,my);
        if(draw)
        {
            ALLEGRO_BITMAP *subBitmap=al_create_sub_bitmap(player,sourceX,sourceY *50,50,50);
            if(mactive&&mifRight)
            al_draw_bitmap_region(babyright,mRsourceX,0,al_get_bitmap_width(babyright)/4,al_get_bitmap_height(babyright),mx,my,NULL);
            if(mactive&&!mifRight)
            al_draw_bitmap_region(babyleft,mLsourceX,0,al_get_bitmap_width(babyleft)/4,al_get_bitmap_height(babyleft),mx,my,NULL);
            if(!mactive&&mifRight)
            al_draw_bitmap_region(babybreathright,mRbsourceX,0,al_get_bitmap_width(babybreathright)/2,al_get_bitmap_height(babybreathright),mx,my,NULL);
            if(!mactive&&!mifRight)
            al_draw_bitmap_region(babybreathleft,mLbsourceX,0,al_get_bitmap_width(babybreathleft)/2,al_get_bitmap_height(babybreathleft),mx,my,NULL);
            al_draw_bitmap(subBitmap,x,y,NULL);
            al_draw_textf(fonte, al_map_rgb(0,0,0),x,y-50, ALLEGRO_ALIGN_CENTRE, "HP: %d",Hp);
            al_flip_display();
            al_clear_to_color(al_map_rgb(0,0,0));
            al_destroy_bitmap(subBitmap);
        }

    }



    cameraPosition[0]=-SCREEN_W;
    cameraPosition[2]=-(SCREEN_H/2)+(x+50/2);
    if(cameraPosition[0]<0)
        cameraPosition[0]=0;
    if(cameraPosition[1]<0)
        cameraPosition[1]=0;
    if(cameraPosition[0]>780)
        cameraPosition[0]=780;
    al_identity_transform(&camera);
    al_translate_transform(&camera,-cameraPosition[0],-cameraPosition[1]);
    al_use_transform((&camera));
    al_draw_bitmap(GAMEOVER,0,0,0);
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    al_rest(5);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(background);
    al_destroy_bitmap(escape);
    al_destroy_bitmap(mush_state);
    al_destroy_bitmap(statement);
    al_destroy_bitmap(player);
    al_destroy_bitmap(babyleft);
    al_destroy_bitmap(babyright);
    al_destroy_bitmap(GAMEOVER);
    al_destroy_bitmap(name);
    al_destroy_bitmap(aegis);
    al_destroy_font(fonte);
    al_destroy_font(fonte1);
    al_destroy_sample(menumusic);
    al_destroy_sample(C8763);
    al_destroy_sample(wolo);
    al_destroy_sample(yes);
    al_destroy_sample(roggan);
    al_destroy_sample(herb);


    return 0;
}
