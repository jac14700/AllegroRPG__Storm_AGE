  #include"al_header.h"
  void init(void){

   /* first, set up Allegro and the graphics mode */
   al_init(); /* initialize Allegro */
   al_install_keyboard(); /* install the keyboard for Allegro to use */
   al_init_image_addon();
   al_install_audio();  // install sound driver
   al_init_acodec_addon();
   al_reserve_samples(9);
   al_init_font_addon();    // install font addons
   al_init_ttf_addon();
    return ;
  }
