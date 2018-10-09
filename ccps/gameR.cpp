 #include"al_header.h"
void gameR(ALLEGRO_DISPLAY* display)
{
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_mouse();

    ALLEGRO_BITMAP *game_rule = al_load_bitmap("game_rule.bmp");
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue , al_get_mouse_event_source());
    al_register_event_source(event_queue , al_get_display_event_source(display));

    int x=0;
    int y=0;
    bool done = false;

    while(!done)
    {
        al_draw_bitmap(game_rule,0,0,NULL);
        ALLEGRO_EVENT events;
        if (!al_is_event_queue_empty(event_queue))
        {
                while (al_get_next_event(event_queue, &events))
                {
                            x = events.mouse.x;
                            y = events.mouse.y;

                        switch (events.type)
                        {

                                case  ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :
                                {

                                    if(x > 556 && x < 736 && y > 35 && y < 88)
                                    {
                                         if ( events.mouse.button& 1)
                                           {

                                               done=true;
                                           }


                                    }
                                    break;
                                }


                        }
        }
    }
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
}

    // Cleanup
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(game_rule);

}
