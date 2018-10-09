 #include"al_header.h"

void ManOnBall(int x,int y,int * map1,bool *manonball)
  {
      *(map1+(y*Map_Width+x))=2;
      //*manonball=false;
      return;
  }
