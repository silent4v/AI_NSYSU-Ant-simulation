#include"base.h"
#include<fstream>
#include<cstdlib>

Space :: Space()
{
    for(int i = SPACE_BOUND_START; i < SPACE_BOUND_END; i++)
        for(int j = SPACE_BOUND_START; j < SPACE_BOUND_END; j++)
            field[i][j] = 0;
    field[0][0] = NEST;
}

void Space :: outputField()
{
    ofstream fptr("output.txt");

    for(int i = SPACE_BOUND_START; i < SPACE_BOUND_END; i++)
    {
        for(int j = SPACE_BOUND_START; j < SPACE_BOUND_END; j++)
            fptr << field[i][j] << " ";
        fptr << endl;
    }

    fptr.close();
}