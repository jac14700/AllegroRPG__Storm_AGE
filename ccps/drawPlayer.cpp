 #include"al_header.h"

 void drawPlayer(int x,int y,ALLEGRO_COLOR Red)
  {

      int z=0,
          k=0;
      z=x/50;k=y/50;x=z*50;y=k*50;

      al_draw_rectangle(x*STUFFS_SIZE,y*STUFFS_SIZE,x*STUFFS_SIZE + 50,y*STUFFS_SIZE + 50, Red,7.0);
      printf("(%d,%d)\n",x,y);


  }
