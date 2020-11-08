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
        for(p = space_map.begin() ; p != space_map.end() ; p++)
        {
            alive = p->second->add_day();
            if(alive)
            {
                cout << "alive" << endl;
                p->second->work(tt);
                cout << "finished" << endl;
            }
            else
            {
                
            }
        }

        map_update(space_map, cache);
        for(p = space_map.begin() ; p != space_map.end() ; p++)
            cout << p->first.x << " " << p->first.y << endl;
        cin >> temp;
    }
    delete_var(tt);
    return 0;
}