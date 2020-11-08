#include "space.h"


map<Base*,Point>space_map;
map<Base*,Point>::iterator p;
map<Base*,Point>cache;
int queen;
int** create_space()
{
    space_map.clear();
    Space **space = new Space* [space_size + (SPACE_INTERVAL * 2) ];
    for(int i = 0; i < space_size + (SPACE_INTERVAL * 2) ; i++)
        space[i] = new Space [space_size + (SPACE_INTERVAL * 2) ];
    srand(time(NULL));
    queen = 0;
    for(int i = 0; i < space_size + (SPACE_INTERVAL * 2) ; i++)     //initialize the space
    {
        for(int j = 0; j < space_size + (SPACE_INTERVAL * 2) ; j++)
        {
            if(i < MIN_X || i > MAX_X || j < MIN_Y || j > MAX_Y)
                space[i][j] = OUT_RANGE;
            else
                space[i][j] = EMPTY;
        }
    }       
        
    
    space[MIN_X][MIN_Y] = HOME;       //set x = 0, y = 0 and value 5 is ant nest

    for(int i = 0 ; i < ant_amount ; i++)
        add_feature(space,ANT);
    
    return space;
}


void file_write(int** s)        //just write space into file data.txt
{
    ofstream file("data.txt");
    
    if(!file)
        cerr << "file data.txt cannot open" << endl;        //connot open data.txt just in case
    else
    {
        for(int i = 0; i < space_size + (SPACE_INTERVAL * 2) ; i++)
        {
            for(int j = 0; j < space_size + (SPACE_INTERVAL * 2) ; j++)
                file << s[i][j] << " ";
            file << endl;
        }
    }

    file.close();
}

Space** file_read()           //just read space from file data.txt
{
    ifstream file("data.txt");
    int** ant_map = new int* [space_size + (SPACE_INTERVAL * 2) ];

    if(!file)
        cerr << "file data.txt cannot open" << endl;
    else
    {
        for(int i = 0; i < space_size + (SPACE_INTERVAL * 2) ; i++)
        {
            ant_map[i] = new int [space_size + (SPACE_INTERVAL * 2) ];
            for(int j = 0; j < space_size + (SPACE_INTERVAL * 2) ; j++)
                file >> ant_map[i][j];
        }
    }

    file.close();
    return ant_map;
}

void delete_var(Space** var)              //release the memory of space variable if no need
{
    for(int i = 0; i < space_size + (SPACE_INTERVAL * 2) ; i++)
        delete var[i];
    delete var;
}

void map_update(map<Base*,Point> &x,map<Base*,Point> &y)
{
    x.clear();
    x = y;
    y.clear();
}