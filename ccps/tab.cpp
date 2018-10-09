 #include"al_header.h"

 void tab(int *map1)
  {
           for(int j = 0;j <Map_Height;j++)// y
            {
                for(int i = 0;i <Map_Width;i++)// x
                    {
                        printf("%3-d",*(map1+(j*Map_Width+i)));
                    }
                    printf("\n\n");
            }
            printf("\n\n\n\n");

  }
