typedef struct Bomb
{
    bool boom ;
    bool boomstay;
    int x;
    int y;
    int powerU;
    int powerD;
    int powerR;
    int powerL;
    int countDown;
    int boomstay_Count;

}Bomb;

typedef struct Players
{
    int x;
    int y;
    int On_Ballx;
    int On_Bally;
    int moveSpeed;
    int power;
    int ballnum;
    int ghost_count;
    int revive_time_counter;
    int kill;
    int suicide;
    bool ManOnBall;
    bool active;
    bool appear;
    bool ghost;
    bool Skyrun;
    int sky_counter;


}Player;

typedef enum LoadState {TileSet,Map1,Map2}loadstate;
