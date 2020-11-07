#include "space.h"

int** create_space()
{
    Space **space = new Space* [size + 6];
    for(int i = 0; i < size + 6; i++)
        space[i] = new Space [size + 6];
    int count, x, y;
    srand(time(NULL));

    for(int i = 0; i < size + 6; i++)        //initialize the space
        for(int j = 0; j < size + 6; j++)
        {
            if(i < 3 || i > size + 2 || j < 3 || j > size + 2)
                space[i][j] = -1;
            else
                space[i][j] = 0;
        }
    
    space[3][3] = 5;       //set x = 0, y = 0 and value 5 is ant nest

    count = 0;
    while(count < ant_amount)       //add ant into space
    {
        x = rand() % 100;
        y = rand() % 100;
        if(space[x + 3][y + 3] != 0)
               continue;

        count++;
        space[x + 3][y + 3] = 1;
    }

    return space;
}

void delete_ant(Space** s, int x, int y)              //change space[x][y] ant into nothing
{
    if(x < 3 || y < 3 || x > size + 2 || y > size + 2)
        cerr << "delete range out of bondary" << endl;
    else
        s[x][y] = 0;
}

void file_write(int** s)        //just write space into file data.txt
{
    ofstream file("data.txt");
    
    if(!file)
        cerr << "file data.txt cannot open" << endl;        //connot open data.txt just in case
    else
    {
        for(int i = 0; i < size + 6; i++)
        {
            for(int j = 0; j < size + 6; j++)
                file << s[i][j] << " ";
            file << endl;
        }
    }

    file.close();
}

Space** file_read()           //just read space from file data.txt
{
    ifstream file("data.txt");
    int** ant_map = new int* [size + 6];

    if(!file)
        cerr << "file data.txt cannot open" << endl;
    else
    {
        for(int i = 0; i < size + 6; i++)
        {
            ant_map[i] = new int [size + 6];
            for(int j = 0; j < size + 6; j++)
                file >> ant_map[i][j];
        }
    }

    file.close();
    return ant_map;
}

void delete_var(Space** var)              //release the memory of space variable if no need
{
    for(int i = 0; i < size + 6; i++)
        delete var[i];
    delete var;
}