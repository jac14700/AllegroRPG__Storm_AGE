void init(void);

void draw( int barL_y, int barR_y, int ball_x, int ball_y, ALLEGRO_BITMAP *bar, ALLEGRO_BITMAP *ball );

void ball_boom (int x,int y,bool true1,ALLEGRO_COLOR Re,int *map1,int time);

void ball_killer(int x,int y,ALLEGRO_COLOR Red,int pl_x1,int pl_y1,int pl_x2,int pl_y2,int *player1die,int * suicide,int *player2die,int *kill,int power,int *map1
                 ,int *powerU,int *powerD,int *powerR,int *powerL,int * tools,int player);

bool Collison(float x,float y,int width,int height,int *map1,int *moveSpeed,int *power,int *ballnum,bool *ManOnBall,bool *ghost);

void LoadMap(const char *filename,std::vector< std::vector <int> > &map1,std::vector< std::vector <int> > &map2,int state,ALLEGRO_BITMAP *tileSet);

void DrawMap(int *map1/*,std::vector <std::vector <int> > map2*/);

void drawPlayer(int x,int y,ALLEGRO_COLOR Red);

int MENU(ALLEGRO_DISPLAY* display);

void tab(int *map1);

int CheckIfHole(int * x,int * y,int *map1,int dir);

void ManOnBall(int x,int y,int * map1,bool *manonball);

bool ifthemaninbranch(int x,int y,int *map1);

bool ifthereisAball(int x,int y,int *map1);

void SetbombOnfire(int x,int y,bool *trueOrfaulse);

void gameR(ALLEGRO_DISPLAY* display);

int GAMANIA(ALLEGRO_DISPLAY* display);
int GAMANIA1(ALLEGRO_DISPLAY* display);
