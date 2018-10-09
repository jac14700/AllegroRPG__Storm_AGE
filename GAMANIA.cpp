#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include"al_header.h"
#include"structs.h"
#include"flie_list.h"
#include"openVarible.h"
int main();
int GAMANIA(ALLEGRO_DISPLAY * display)
{
    const float Fps=130.0;
    int time1=0;
    enum Direction{ UP, DOWN, RIGHT, LEFT};
    int i;
    Player player[PLAYER_NUM];
    Bomb ball[MAX_BALL];

    /// 變數宣告區
    bool done =false,draw =true;
    bool Game=true;
    int p2die=0,p1die=0,dir1=DOWN,dir2=DOWN,sourceX =0,sourceY =0,sourceX1 =0,sourceY1 =0;
    int state = 0;
    int r = 0, g = 0, b = 0;
    int min1 = 3, seg  =  0  ;


    for(i=0;i<PLAYER_NUM;i++)
    {
        player[i].moveSpeed=3;
        player[i].ballnum=0;
        player[i].ghost_count=ghostcount;
        player[i].power=1;
        player[i].ManOnBall=false;
        player[i].ghost=false;
        player[i].On_Ballx=0;
        player[i].On_Bally=0;
    }
        player[0].x=775;
        player[0].y=675;
        player[1].x=75;
        player[1].y=75;
    player[1].ballnum++;
    for(i=0;i<MAX_BALL;i++)
    {
        ball[i].boom=false;
        ball[i].countDown=100;
        ball[i].boomstay=false;
        ball[i].boomstay_Count=BallCounter;
        if(i<10)
        {
            ball[i].powerD=player[0].power;
            ball[i].powerU=player[0].power;
            ball[i].powerR=player[0].power;
            ball[i].powerL=player[0].power;

        }
            if(i>9)
        {
            ball[i].powerD=player[1].power;
            ball[i].powerU=player[1].power;
            ball[i].powerR=player[1].power;
            ball[i].powerL=player[1].power;

        }
    }




    if(!al_init())
    {
    al_show_native_message_box(NULL,"Error",NULL,"Could not initialize Allegro",0,0);
    }

    if (!display)//若沒有display跳方塊-->沒有display
    {
    al_show_native_message_box(display,"error",NULL,"Could not display main window",NULL,NULL);
    return -1;
    }
    /// //////////////////////  i n s t a l l
    al_init_primitives_addon();//event&queue
    al_install_keyboard();//鍵盤
    al_init_image_addon();
    al_install_audio();  // install sound driver
    al_init_acodec_addon();
    al_init_font_addon();    // install font addons
    al_init_ttf_addon();

    /// /////////////////////////////////////////////////        ALLEGRO宣 告

    ALLEGRO_BITMAP *RPG1 = al_load_bitmap("player1.png");//新增有指標
    ALLEGRO_BITMAP *RPG2 = al_load_bitmap("player2.png");//新增有指標
    ALLEGRO_SAMPLE *starburst =al_load_sample("starburst.wav");
    ALLEGRO_SAMPLE *C8763 =al_load_sample("C8763.wav");
    ALLEGRO_SAMPLE *MODOHAIYAKU =al_load_sample("MODOHAIYAKU.wav");

    al_reserve_samples(1);


    /// /////////////////////////////////////////////////

    ALLEGRO_KEYBOARD_STATE keyState;
    ALLEGRO_TIMER * timer = al_create_timer(1.0/Fps),*contador = al_create_timer(1.0);
    ALLEGRO_COLOR electricB =al_map_rgb(44,117,228);
    ALLEGRO_COLOR Red  =al_map_rgb(255,0,0);
    ALLEGRO_COLOR DarkBlue=al_map_rgb(16,19,133);
    ALLEGRO_EVENT_QUEUE * event_queue =al_create_event_queue(),* contador_queue = al_create_event_queue();
    ALLEGRO_FONT *fonte2 = al_load_ttf_font("ARCHRISTY.ttf", 70, 0);
    ALLEGRO_FONT *fonte = al_load_ttf_font("ARCHRISTY.ttf", 20, 0);
    ALLEGRO_FONT *fonte1 = al_load_ttf_font("ARCHRISTY.ttf", 17, 0);





    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue,al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(contador_queue, al_get_timer_event_source(contador));
    std::vector <std::vector <int> > map1;
    std::vector <std::vector <int> > map2;

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

    int Map1[Map_Width][Map_Height]=
                 {29    ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29,
                  29    ,0  ,13 ,12 ,13 ,12 ,5  ,0  ,0  ,10 ,5  ,23 ,12 ,23 ,0  ,23 ,29,
                  29    ,0  ,22 ,10 ,22 ,10 ,24 ,10 ,0  ,0  ,24 ,12 ,13 ,0  ,0  ,0  ,29,
                  29    ,0  ,0  ,13 ,12 ,13 ,5  ,0  ,10 ,10 ,5  ,23 ,10 ,23 ,10 ,23 ,29,
                  29    ,10 ,22 ,10 ,22 ,10 ,24 ,10 ,0  ,0  ,24 ,13 ,12 ,13 ,12 ,13 ,29,
                  29    ,12 ,13 ,12 ,13 ,12 ,5  ,0  ,0  ,10 ,5  ,23 ,10 ,23 ,10 ,23,29,
                  29    ,13 ,22 ,13 ,22 ,13 ,24 ,10 ,10 ,0  ,0  ,12 ,13 ,12 ,13 ,12 ,29,
                  29    ,24 ,5  ,24 ,5  ,24 ,5  ,0  ,0  ,10 ,5  ,24 ,5  ,24 ,5  ,24 ,29,
                  29    ,12 ,13 ,12 ,13 ,12 ,0  ,10 ,0  ,0  ,24 ,12 ,22 ,12 ,22 ,12 ,29,
                  29    ,21 ,10 ,21 ,10 ,21 ,5  ,0  ,10 ,10 ,5  ,13 ,12 ,13 ,12 ,13 ,29,
                  29    ,13 ,12 ,13 ,12 ,13 ,24 ,10 ,0  ,0  ,24 ,10 ,22 ,10 ,22 ,10 ,29,
                  29    ,21 ,0  ,21 ,10 ,21 ,5  ,0  ,0  ,10 ,5  ,12 ,13 ,12 ,13 ,-4  ,29,
                  29    ,0  ,0  ,12 ,13 ,12 ,24 ,10 ,10 ,0  ,24 ,10 ,22 ,10 ,22 ,0  ,29,
                  29    ,21 ,0  ,21 ,12 ,21 ,5  ,0  ,0  ,10 ,5  ,13 ,12 ,13 ,0  ,0  ,29,
                  29    ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29 ,29};

        srand(time(NULL));
        int a,j,t1,t2,tmp;

    //1~52張牌
        int d;
        int cards[95];
        for(d=1;d<=59;d++)//空箱
        {
            cards[d-1]=-9;
        }
        for(d=60;d<=62;d++)//水球
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


    for(int i=0;i<94;i++)
        printf("%-3d",cards[i]);


    // 從牌堆抽二張交換
        int f;
        for(f=0; f<50000; f++)
        {
         t1 = rand() % 95;
         t2 = rand() % 95;
    //(左右互換
         if (t1=t2)
         {
         tmp = cards[t1];
         cards[t1] = cards[t1-1];
         cards[t1-1] = tmp;
         }
    //(兩張互換
         if(t1!=t2)
         {
         tmp = cards[t1];
         cards[t1] = cards[t2];
         cards[t2] = tmp;
         }
        }
    int choice=-2;
    //choice = MENU(display);
    if (choice==-1)
        return 0;
    al_play_sample(starburst, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
    al_start_timer(timer);
    al_start_timer(contador);
    while(!done)

    {


            if (!al_is_event_queue_empty(event_queue))
            {
                    ALLEGRO_EVENT events;
                    while (al_get_next_event(event_queue, &events))
                    {
                            switch (events.type)
                            {

                                    case ALLEGRO_EVENT_KEY_DOWN:
                                    {

                                            al_get_keyboard_state(&keyState);
                            if(al_key_down(&keyState,ALLEGRO_KEY_SPACE)&&!p1die)//PLAYER1
                            {

                                if(!ifthereisAball(player[0].x/50,player[0].y/50,*Map1))
                                for(i=0;i<10;i++)
                                {
                                    if(i<=player[0].ballnum)
                                    if(!ball[i].boom)
                                    {

                                            ball[i].x=player[0].x;
                                            ball[i].y=player[0].y;
                                            ball[i].boom =true;
                                            player[0].On_Ballx=player[0].x/50;
                                            player[0].On_Bally=player[0].y/50;
                                            player[0].ManOnBall=true;
                                            break;
                                    }
                                }
                            }if(al_key_down(&keyState,ALLEGRO_KEY_Q))//PLAYER2
                            {

                                al_play_sample(C8763, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                                if(!ifthereisAball(player[1].x/50,player[1].y/50,*Map1))
                                for(i=11;i<20;i++)
                                {
                                    if((i-10)<=player[1].ballnum)
                                    if(!ball[i].boom)
                                    {printf("h\n");
                                            ball[i].x=player[1].x;
                                            ball[i].y=player[1].y;
                                            ball[i].boom =true;
                                            player[1].On_Ballx=player[1].x/50;
                                            player[1].On_Bally=player[1].y/50;
                                            player[1].ManOnBall=true;
                                            break;
                                    }
                                }
                            }


                                        if (al_key_down(&keyState,ALLEGRO_KEY_TAB))
                                            tab(*Map1);

                                    if(al_key_down(&keyState,ALLEGRO_KEY_H))//PLAYER2
                                    {
                                            al_destroy_bitmap(RPG1);
                                            al_destroy_bitmap(RPG2);
                                            al_destroy_font(fonte);
                                            al_destroy_sample(starburst);
                                            al_destroy_timer(timer);
                                            al_destroy_timer(contador);
                                            al_destroy_event_queue(event_queue);
                                            al_destroy_event_queue(contador_queue);
                                            return 0;
                                    }
                                    }


                                    case ALLEGRO_EVENT_TIMER:
                                    {
                                        if(player[0].ghost)
                                           {    printf("%d\n",player[0].ghost_count);
                                               player[0].ghost_count--;
                                               if(player[0].ghost_count<=0)
                                                {player[0].ghost=false;
                                               player[0].ghost_count=ghostcount;}
                                           }
                                           if(player[1].ghost)
                                           {    printf("%d\n",player[1].ghost_count);
                                               player[1].ghost_count--;
                                               if(player[1].ghost_count<=0)
                                                {player[1].ghost=false;
                                               player[1].ghost_count=ghostcount;}
                                           }

                                        if(p1die||p2die)
                                        {
                                            if(p1die)
                                         al_draw_textf(fonte, al_map_rgb(r, g, b),905,75, ALLEGRO_ALIGN_CENTRE, "byio;ijaf;ioj;i;aij;diayy");
                                            if(p2die)
                                         al_draw_textf(fonte, al_map_rgb(r, g, b),905,75, ALLEGRO_ALIGN_CENTRE, "byio;ijaf;ioj;i;aij;diayy");
                                            if(p2die&&p1die)
                                         al_draw_textf(fonte, al_map_rgb(r, g, b),905,75, ALLEGRO_ALIGN_CENTRE, "byio;ijaf;ioj;i;aij;diayy");

                                             Game=false;
                                        }

                                        if (++r >= 255) r = 0;
                                        if (++g >= 255) g = 0;
                                        if (++b >= 255) b = 0;

                                        for(i=0;i<MAX_BALL;i++)
                                        {
                                            if(ball[i].boom)
                                            {
                                                ball[i].countDown--;

                                            }
                                        }

                                        al_get_keyboard_state(&keyState);


                                        //PLAYER1
                                        if(al_key_down(&keyState,ALLEGRO_KEY_DOWN)||
                                           al_key_down(&keyState,ALLEGRO_KEY_UP)||
                                           al_key_down(&keyState,ALLEGRO_KEY_LEFT)||
                                           al_key_down(&keyState,ALLEGRO_KEY_RIGHT))
                                           {
                                                if(al_key_down(&keyState,ALLEGRO_KEY_DOWN)&&!p1die){
                                                player[0].y +=player[0].moveSpeed;dir1=1;sourceY=0;}
                                                else if(al_key_down(&keyState,ALLEGRO_KEY_UP)&&!p1die){
                                                player[0].y -= player[0].moveSpeed;dir1=0;sourceY=3;}
                                                else if(al_key_down(&keyState,ALLEGRO_KEY_LEFT)&&!p1die){
                                                player[0].x -= player[0].moveSpeed;dir1=3;sourceY=1;}
                                                else if(al_key_down(&keyState,ALLEGRO_KEY_RIGHT)&&!p1die){
                                                player[0].x += player[0].moveSpeed;dir1=2;sourceY=2;}

                                                player[0].active=true;
                                           }

                                        if(!al_key_down(&keyState,ALLEGRO_KEY_DOWN)&&
                                           !al_key_down(&keyState,ALLEGRO_KEY_UP)&&
                                           !al_key_down(&keyState,ALLEGRO_KEY_LEFT)&&
                                           !al_key_down(&keyState,ALLEGRO_KEY_RIGHT))
                                            {
                                                player[0].active=false;
                                            }
                                        //PLAYER2
                                        if(al_key_down(&keyState,ALLEGRO_KEY_S)||
                                           al_key_down(&keyState,ALLEGRO_KEY_W)||
                                           al_key_down(&keyState,ALLEGRO_KEY_A)||
                                           al_key_down(&keyState,ALLEGRO_KEY_D))
                                           {
                                                if(al_key_down(&keyState,ALLEGRO_KEY_S)&&!p1die){
                                                player[1].y +=player[1].moveSpeed;dir2=1;sourceY1=0;}
                                                else if(al_key_down(&keyState,ALLEGRO_KEY_W)&&!p2die){
                                                player[1].y -= player[1].moveSpeed;dir2=0;sourceY1=3;}
                                                else if(al_key_down(&keyState,ALLEGRO_KEY_A)&&!p2die){
                                                player[1].x -= player[1].moveSpeed;dir2=3;sourceY1=1;}
                                                else if(al_key_down(&keyState,ALLEGRO_KEY_D)&&!p2die){
                                                player[1].x += player[1].moveSpeed;dir2=2;sourceY1=2;}

                                                player[1].active=true;
                                           }

                                        if(!al_key_down(&keyState,ALLEGRO_KEY_S)&&
                                           !al_key_down(&keyState,ALLEGRO_KEY_W)&&
                                           !al_key_down(&keyState,ALLEGRO_KEY_A)&&
                                           !al_key_down(&keyState,ALLEGRO_KEY_D))
                                            {
                                                player[1].active=false;
                                            }

                                        //其他選項
                                         if(al_key_down(&keyState,ALLEGRO_KEY_V))
                                            {
                                                p1die=0;p2die=0;
                                            }

                                        if (al_key_down(&keyState,ALLEGRO_KEY_HOME))
                                        {
                                             player[0].x=450;
                                             player[0].y=450;
                                             player[1].x=450;
                                             player[1].y=450;
                                        }





                                    if(Collison(player[0].x,player[0].y,STUFFS_SIZE,STUFFS_SIZE,*Map1,&player[0].moveSpeed,&player[0].power,&player[0].ballnum,&player[0].ManOnBall,&player[0].ghost))
                                        {
                                            if(dir1 == 1)
                                            {
                                                player[0].y =(player[0].y/STUFFS_SIZE)*STUFFS_SIZE+25;

                                                CheckIfHole(&player[0].x,&player[0].y,*Map1,dir1);
                                              }
                                            if(dir1 == 3)
                                            {
                                                player[0].x =( player[0].x/STUFFS_SIZE)*STUFFS_SIZE+25;
                                                CheckIfHole(&player[0].x,&player[0].y,*Map1,dir1);
                                            }
                                             else if(dir1 == 2)
                                            {

                                                player[0].x =( player[0].x/STUFFS_SIZE)*STUFFS_SIZE+25;
                                                CheckIfHole(&player[0].x,&player[0].y,*Map1,dir1);
                                            }
                                            else if(dir1 == 0)
                                            {
                                               player[0].y =(player[0].y/STUFFS_SIZE)*STUFFS_SIZE+25;

                                               CheckIfHole(&player[0].x,&player[0].y,*Map1,dir1);

                                                }
                                        }

                                        if(abs(player[0].x/50-player[0].On_Ballx)>0 || abs(player[0].y/50-player[0].On_Bally)>0)
                                        if(player[0].ManOnBall)
                                        {player[0].ManOnBall=false;}


                                        //PLAYER2

                                    if(Collison(player[1].x,player[1].y,STUFFS_SIZE,STUFFS_SIZE,*Map1,&player[1].moveSpeed,&player[1].power,&player[1].ballnum,&player[1].ManOnBall,&player[1].ghost))
                                        {
                                            if(dir2 == 1)
                                            {
                                                player[1].y =(player[1].y/STUFFS_SIZE)*STUFFS_SIZE+25;

                                                CheckIfHole(&player[1].x,&player[1].y,*Map1,dir2);
                                              }
                                            if(dir2 == 3)
                                            {
                                                player[1].x =( player[1].x/STUFFS_SIZE)*STUFFS_SIZE+25;
                                                CheckIfHole(&player[1].x,&player[1].y,*Map1,dir2);
                                            }
                                             else if(dir2 == 2)
                                            {

                                                player[1].x =( player[1].x/STUFFS_SIZE)*STUFFS_SIZE+25;
                                                CheckIfHole(&player[1].x,&player[1].y,*Map1,dir2);
                                            }
                                            else if(dir2 == 0)
                                            {
                                               player[1].y =(player[1].y/STUFFS_SIZE)*STUFFS_SIZE+25;

                                               CheckIfHole(&player[1].x,&player[1].y,*Map1,dir2);

                                                }
                                        }

                                        if(abs(player[1].x/50-player[1].On_Ballx)>0 || abs(player[1].y/50-player[1].On_Bally)>0)
                                        if(player[1].ManOnBall)
                                        {player[1].ManOnBall=false;}


        /////////////////////////////////////////////


                                        draw = true ;

                                    }
                            }
                    }

                    //PLAYER1 動作
                    if(player[0].active)
                    {
                        sourceX+=al_get_bitmap_width(RPG1)/4;
                        if(sourceX>=al_get_bitmap_width(RPG1))
                            sourceX=0;

                    }
                    if(!player[0].active)
                    {
                        sourceX=0;
                    }
                    //PLAYER2 動作
                    if(player[1].active)
                    {
                        sourceX1+=al_get_bitmap_width(RPG1)/4;
                        if(sourceX1>=al_get_bitmap_width(RPG1))
                            sourceX1=0;

                    }
                    if(!player[1].active)
                    {
                        sourceX1=0;
                    }

                    //繪畫
                    if(draw)
                    {
                        DrawMap(*Map1);
                        draw = false;
                        for(i=0;i<MAX_BALL;++ i)
                        {
                            if (ball[i].boom)
                            {
                                ball_boom(ball[i].x,ball[i].y,1,Red,*Map1,ball[i].countDown);
                                if(ball[i].countDown<0)
                                {
                                        ball[i].boom =false;

                                        ball[i].boomstay=true;
                                        ball[i].countDown=100;
                                        if(i<10)
                                        ball_killer(ball[i].x,ball[i].y,Red,player[0].x,player[0].y,player[1].x,player[1].y,&p1die,&player[0].suicide,&p2die,&player[0].kill,player[0].power
                                                    , *Map1,&ball[i].powerU,&ball[i].powerD,&ball[i].powerR,&ball[i].powerL,cards,0);
                                        if(i>=10&&i<20)
                                        ball_killer(ball[i].x,ball[i].y,Red,player[0].x,player[0].y,player[1].x,player[1].y,&p1die,&player[1].suicide,&p2die,&player[1].suicide,player[1].power
                                                    , *Map1,&ball[i].powerU,&ball[i].powerD,&ball[i].powerR,&ball[i].powerL,cards,1);



                                }
                            }
                            if (ball[i].boomstay_Count>0&&ball[i].boomstay)
                            {
                                ball[i].boomstay_Count--;
                                al_draw_filled_rectangle((ball[i].x/STUFFS_SIZE-ball[i].powerL)*STUFFS_SIZE,ball[i].y/STUFFS_SIZE*STUFFS_SIZE,(ball[i].x/STUFFS_SIZE+1+ball[i].powerR)*STUFFS_SIZE,(ball[i].y/STUFFS_SIZE+1)*STUFFS_SIZE,DarkBlue);
                                al_draw_filled_rectangle((ball[i].x/STUFFS_SIZE)*STUFFS_SIZE,(ball[i].y/STUFFS_SIZE-ball[i].powerU)*STUFFS_SIZE,(ball[i].x/STUFFS_SIZE+1)*STUFFS_SIZE,(ball[i].y/STUFFS_SIZE+1+ball[i].powerD)*STUFFS_SIZE,DarkBlue);
                            }

                            if(ball[i].boomstay_Count==0)
                            {
                                ball[i].boomstay=false;
                                ball[i].boomstay_Count=BallCounter;
                                 if(i<10)
                                    {
                                        ball[i].powerD=player[0].power;
                                        ball[i].powerU=player[0].power;
                                        ball[i].powerR=player[0].power;
                                        ball[i].powerL=player[0].power;

                                    }
                                  if(i>9)
                                    {
                                        ball[i].powerD=player[1].power;
                                        ball[i].powerU=player[1].power;
                                        ball[i].powerR=player[1].power;
                                        ball[i].powerL=player[1].power;

                                    }
                            }
                        }

        /////////////////////////////////////



                            if(!p1die&&!ifthemaninbranch(player[0].x/50,player[0].y/50,*Map1)&&!player[0].ghost)
                                al_draw_bitmap_region(RPG1,sourceX,sourceY*al_get_bitmap_height(RPG1)/4,STUFFS_SIZE,STUFFS_SIZE,player[0].x-25,player[0].y-25,NULL);
                            if(!p2die&&!ifthemaninbranch(player[1].x/50,player[1].y/50,*Map1)&&!player[1].ghost)
                                al_draw_bitmap_region(RPG2,sourceX1,sourceY1*al_get_bitmap_height(RPG2)/4,al_get_bitmap_width(RPG2)/4,al_get_bitmap_height(RPG2)/4,player[1].x-25,player[1].y-25,NULL);
                            al_draw_textf(fonte, al_map_rgb(r, g, b),955,125, ALLEGRO_ALIGN_CENTRE, "%-2d  :  %-2d", min1, seg);
                            al_flip_display();//一定要弄 不然沒畫面 可以平穩潤滑畫面時使用
                            al_clear_to_color(al_map_rgb(0,0,0));
                    }

            }
            if (!al_is_event_queue_empty(contador_queue))
            {
                ALLEGRO_EVENT evento;
                while (al_get_next_event(contador_queue, &evento))
                {
                    switch (evento.type)
                    {
                        case ALLEGRO_EVENT_TIMER:

                            seg--;
                            if(min1==0&&seg==-1)
                                done=true;
                            if (seg == -1)
                            {
                                seg=59;
                                if(min1!=0)
                                min1--;
                            }
                    }
                }
            }
        if(!Game)
    {
        break;

    }
    }
       if(!Game)
    {
                                if(p1die&&!p2die)
                                al_draw_textf(fonte2, al_map_rgb(6,29,234),SCREEN_W/2,SCREEN_H/2, ALLEGRO_ALIGN_CENTRE, "P2win");
                                if(!p1die&&p2die)
                                al_draw_textf(fonte2, al_map_rgb(6,29,234),SCREEN_W/2,SCREEN_H/2, ALLEGRO_ALIGN_CENTRE, "P1win");
                                if(p1die&&p2die)
                                al_draw_textf(fonte2, al_map_rgb(6,29,234),SCREEN_W/2,SCREEN_H/2, ALLEGRO_ALIGN_CENTRE, "Tie");
                                if(!p1die&&!p2die)
                                al_draw_textf(fonte2, al_map_rgb(6,29,234),SCREEN_W/2,SCREEN_H/2, ALLEGRO_ALIGN_CENTRE, "Tie");
                                al_flip_display();//一定要弄 不然沒畫面 可以平穩潤滑畫面時使用
                            al_clear_to_color(al_map_rgb(0,0,0));

       al_rest(5);

    }

        al_destroy_bitmap(RPG1);
        al_destroy_bitmap(RPG2);
        al_destroy_font(fonte1);
        al_destroy_font(fonte2);
        al_destroy_font(fonte);
        al_destroy_sample(C8763);
        al_destroy_sample(MODOHAIYAKU);
        al_destroy_sample(starburst);
        al_destroy_timer(timer);
        al_destroy_timer(contador);
        al_destroy_event_queue(event_queue);
        al_destroy_event_queue(contador_queue);
        return 0;
}
