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
        cout << "h " << p->second.x << " " << p->second.y << endl;
    
    while(1)
    {
        for(p = space_map.begin() ; p != space_map.end() ; p++)
        {
            alive = p->first->add_day();
            if(alive)
            {
                cout << "alive" << endl;
                p->first->work(tt);
                //cout << "finished" << endl;
            }
            else
            {
                cout << "dead" << endl;
                //cout << "dead" << endl;
            }
        }
        cout << endl;

        map_update(space_map, cache);
        //cout << "hello" << endl;
        for(p = space_map.begin() ; p != space_map.end() ; p++)
            cout << p->second.x << " " << p->second.y << endl;
        cout << endl;
        cin >> temp;
    }
    delete_var(tt);
    return 0;
}