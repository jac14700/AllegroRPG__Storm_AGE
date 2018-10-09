 #include"al_header.h"

 void ball_boom(int x,int y,bool true1,ALLEGRO_COLOR Red,int *map1,int time)
  {
       ALLEGRO_BITMAP *bomb = al_load_bitmap("2.png");
       x = x/STUFFS_SIZE;
       y = y/STUFFS_SIZE;
       if(*(map1+(y*Map_Width+x))!=Bomb20){
       *(map1+(y*Map_Width+x))=Bomb20;}
       if(time%50>=38)
       al_draw_bitmap_region(bomb,0,0,50,50,x*STUFFS_SIZE,y*STUFFS_SIZE,NULL);
        if (time%50>=25&&time%50<38)
       al_draw_bitmap_region(bomb,50,0,50,50,x*STUFFS_SIZE,y*STUFFS_SIZE,NULL);
        if (time%50<25&&time%50>12)
        al_draw_bitmap_region(bomb,100,0,50,50,x*STUFFS_SIZE,y*STUFFS_SIZE,NULL);
        if (time%50<12)
        al_draw_bitmap_region(bomb,153,0,50,50,x*STUFFS_SIZE,y*STUFFS_SIZE,NULL);

        al_destroy_bitmap(bomb);

  }
