#include <iostream>
#include "ant.h"
#include <unistd.h>
using namespace std;
int main()
{
    Space **tt = create_space();
    bool alive;
    char temp;
    file_write(tt);
    /*for(p = space_map.begin() ; p != space_map.end() ; p++)
        cout << "h " << p->second.x << " " << p->second.y << endl;*/
    
    while(1)
    {
        for(p = space_map.begin() ; p != space_map.end() ; p++)
           cout << p->second.x << " " << p->second.y << endl;
        for(p = space_map.begin(); p != space_map.end(); p++)
        {
            alive = p->first->add_day();
            if(alive)
                p->first->work(tt);
            else
            {
                tt[p->second.x][p->second.y] = 0;
                cout << "dead" << endl;
            }
        }
        cout << endl;
        for(int i = MIN_X ; i < MAX_X ; i++)
        {
            for(int j = MIN_Y ; j < MAX_Y ; j++)
            {
                if(tt[i][j] > PHEROMONE)
                    tt[i][j]--;
                else if(tt[i][j] == PHEROMONE)
                    tt[i][j] = 0; 
            }
        }
        map_update(space_map, cache);
        if(rand() % 3 == 0)
            add_feature(tt, FOOD);
        file_write(tt);
        getchar();
        sleep(1);
    }
    delete_var(tt);
    return 0;
}