#include <iostream>
#include "ant.h"
using namespace std;
int main()
{
    Space **tt = create_space();
    bool alive;
    char temp;
    file_write(tt);
    for(p = space_map.begin() ; p != space_map.end() ; p++)
        cout << p->first.x << " " << p->first.y << endl;
    while(1)
    {
        
        for(p = space_map.begin(); p != space_map.end(); p++)
        {
            alive = p->second->add_day();
            if(alive)
                p->second->work(tt);
            else
            {
                
            }
        }
        cout << endl;
        map_update(space_map, cache);
        for(p = space_map.begin() ; p != space_map.end() ; p++)
            cout << p->first.x << " " << p->first.y << endl;
        file_write(tt);
        
        cin >> temp;
    }
    delete_var(tt);
    return 0;
}