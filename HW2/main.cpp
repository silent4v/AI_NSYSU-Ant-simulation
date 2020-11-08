#include <iostream>
#include "ant.h"
using namespace std;
int main()
{
    Space **tt = create_space();
    file_write(tt);
    for(p = space_map.begin() ; p != space_map.end() ; p++)
        cout << p->first.x << " " << p->first.y << endl;
    cout << endl;
    for(p = space_map.begin() ; p != space_map.end() ; p++)
        p->second->work(tt);
    map_update(space_map,cache);
    for(p = space_map.begin() ; p != space_map.end() ; p++)
        cout << p->first.x << " " << p->first.y << endl;
    delete_var(tt);
    return 0;
}