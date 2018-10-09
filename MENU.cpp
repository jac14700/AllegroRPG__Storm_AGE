#include"al_header.h"
void gameR(ALLEGRO_DISPLAY* display);
int MENU(ALLEGRO_DISPLAY* display)
{       int i=0;

    // Initialize Allegro
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();



    ALLEGRO_BITMAP *fondo1 = al_load_bitmap("1.bmp");
    ALLEGRO_BITMAP *fondo2 = al_load_bitmap("2.bmp");
    ALLEGRO_BITMAP *fondo3 = al_load_bitmap("3.bmp");

        int x,y;

    // Create allegro display
   // display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    if(display == NULL)
    {
        printf("Failed to create Allegro display!\n");
        return 0;
    }

    bool done = false;


    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue , al_get_mouse_event_source());
    al_register_event_source(event_queue , al_get_display_event_source(display));

    while(!done)
    {

        ALLEGRO_EVENT events;
        if (!al_is_event_queue_empty(event_queue))
        {
                while (al_get_next_event(event_queue, &events))
                {
                        switch (events.type)
                        {


                            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                                {
                                    done = true;
                                }
                            case ALLEGRO_EVENT_MOUSE_AXES:
                                {
                                    x = events.mouse.x;
                                    y = events.mouse.y;
                                    if(x > 385 && x < 691 && y > 560 && y < 641)
                                    {
                                        al_draw_bitmap(fondo2,0,0,NULL);
                                    }
                                    else if(x > 70 && x < 362 && y > 560 && y < 641)
                                    {
                                        al_draw_bitmap(fondo3,0,0,NULL);
                                    }
                                    else
                                        al_draw_bitmap(fondo1,0,0,NULL);
                                }
                            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN :
                                {

                                    if(x > 385 && x < 691 && y > 560 && y < 641)
                                    {
                                        if ( events.mouse.button& 1)
                                           return 1;


                                    }
                                    else if(x > 70 && x < 362 && y > 560 && y < 641)
                                    {
                                        if ( events.mouse.button& 1)
                                        gameR(display);
                                    }
                            default:break;
                                }
                        }

                }
    }

    al_flip_display();
}



    // Cleanup
    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_bitmap(fondo1);
    al_destroy_bitmap(fondo2);
    al_destroy_bitmap(fondo3);

}
/*#include"al_header.h"
#include"flie_list.h"

int MENU(ALLEGRO_DISPLAY* display)
{   int i=0;

    // Initialize Allegro
    al_init();
    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_mouse();



    ALLEGRO_BITMAP *fondo1 = al_load_bitmap("FONDO1.bmp");
    ALLEGRO_BITMAP *fondo2 = al_load_bitmap("FONDO2.bmp");
    ALLEGRO_BITMAP *fondo3 = al_load_bitmap("FONDO3.bmp");


        int x,y;

    if(display == NULL)
    {
        printf("Failed to create Allegro display!\n");
        return 0;
    }

    bool done = false;


    ALLEGRO_TIMER * timer = al_create_timer(1.0/60);
    ALLEGRO_KEYBOARD_STATE keyState;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue,al_get_keyboard_event_source());
    al_register_event_source(event_queue , al_get_mouse_event_source());
    al_register_event_source(event_queue , al_get_display_event_source(display));
    al_register_event_source(event_queue,al_get_timer_event_source(timer));

al_start_timer(timer);
    while(!done)
    {

        ALLEGRO_EVENT events;
        if (!al_is_event_queue_empty(event_queue))
        {
                while (al_get_next_event(event_queue, &events))
                {



                           if( events.type== ALLEGRO_EVENT_TIMER){printf("h");


                             if( events.type==ALLEGRO_EVENT_MOUSE_AXES){printf("h1");
                                    x = events.mouse.x;
                                    y = events.mouse.y;
                                    if(x > 385 && x < 691 && y > 560 && y < 641)
                                    {
                                        al_draw_bitmap(fondo2,0,0,NULL);
                                    }
                                    else if(x > 70 && x < 362 && y > 560 && y < 641)
                                    {
                                        al_draw_bitmap(fondo3,0,0,NULL);
                                    }
                                    else
                                        al_draw_bitmap(fondo1,0,0,NULL);
                                }
                            al_flip_display();
                            al_clear_to_color(al_map_rgb(0,0,0));
                            break;
                            //default :al_draw_bitmap(fondo1,0,0,NULL);break;
                        }

                }
    }
}



    // Cleanup

    al_destroy_event_queue(event_queue);
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_bitmap(fondo1);
    al_destroy_bitmap(fondo2);
    al_destroy_bitmap(fondo3);
}
*/
