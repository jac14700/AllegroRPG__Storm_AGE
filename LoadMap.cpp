 #include"al_header.h"
 #include"structs.h"
 #include"openVarible.h"
 #include"openVarible.h"
void LoadMap(const char *filename,std::vector< std::vector <int> > &map1
             ,std::vector< std::vector <int> > &map2,int state,ALLEGRO_BITMAP *tileSet)
{
    std::ifstream openfile(filename);
    if(openfile.is_open())
    {
        std::string line, value;
        int space;
        while(!openfile.eof())
        {
            std::getline(openfile,line);

            if(line.find("[TileSet1]") != std::string::npos)
            {
                state = 0;
                continue;
            }
            else if(line.find("[Map1]") != std::string::npos)
            {
                state = 1;
                continue;
            }
            else if(line.find("[Map2]") != std::string::npos)
            {
                state = 2;
                continue;
            }
            switch(state)
            {
            case TileSet:{
                if(line.length() > 0)
                    tileSet = al_load_bitmap(line.c_str());


                break;}
            /*case Map1:
            {
                std::stringstream str(line);
                std::vector<int> tempVector;
                while(!str.eof())
                {
                    std::getline(str,value,' ');
                    if(value.length() > 0)
                        tempVector.push_back(atoi(value.c_str()));
                }
                map1.push_back(tempVector);
                break;
            }
            /*case Map2:
            {
                std::stringstream str1(line);
                std::vector<int> tempVector1;
                while(!str1.eof())
                {
                    std::getline(str1,value,' ');
                    if(value.length() > 0)
                        tempVector1.push_back(atoi(value.c_str()));
                }
                map2.push_back(tempVector1);
                break;
            }*/
            }

        }

    }
}
