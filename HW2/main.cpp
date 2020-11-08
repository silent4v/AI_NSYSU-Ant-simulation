#include <iostream>
#include "ant.h"
using namespace std;
int main()
{
    Space **tt = create_space();
    char temp;
    file_write(tt);
    for(p = space_map.begin() ; p != space_map.end() ; p++)
        cout << p->first.x << " " << p->first.y << endl;
    while(1)
    {
        
        for(p = space_map.begin(); p != space_map.end(); p++)
            p->second->work(tt);
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