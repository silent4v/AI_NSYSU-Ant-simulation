#include <time.h>
#include "base.h"
#include <unistd.h>

void update(Space &f,Queen &h)
{
    Worker::forDelete.clear();
    for(auto i = Worker::antPoint.begin(); i != Worker::antPoint.end(); i++)
    {
        cout << "map fuck" << endl;
        i->second->work(f);
    }


    for(int i = 0; i < SPACE_BOUND_END ; i++)
    {
        for(int j = 0; j < SPACE_BOUND_END ;j++)
        {
                if(f.field[i][j]==2)
                {
                    if(Worker::antPoint.find(Point(i,j)) != Worker::antPoint.end())
                        if(Worker::antPoint[Point(i,j)]->get_blood() <= 0)
                            f.field[i][j] = EMPTY; 
                  //  else
                    //    f.field[i][j] = EMPTY;
                    
                }
        }
    }
    for(auto i = Worker::forDelete.begin() ; i != Worker::forDelete.end() ; i++)
        Worker::antPoint.erase(*i);

    Pheromone::forDelete.clear();
    for(auto i = Worker::pheromonePoint.begin(); i != Worker::pheromonePoint.end(); i++)
    {
        cout << "pheromone fuck" << endl;
        i->second.decrease_density();
        if(i->second.get_density() == 0)
        {
            f.field[i->first.x][i->first.y] = EMPTY;
            Pheromone::forDelete.push_back(i->first);
        }
    }
    for(auto i = Pheromone::forDelete.begin() ; i != Pheromone::forDelete.end() ; i++)
        Worker::pheromonePoint.erase(*i);
    h.work(f);    
}

int main()
{
    srand(time(NULL));
    Space mainSpace;
    Queen onlyQueen;
    for(int i = 0 ; i < 10 ; i++)
    {
        onlyQueen.addAnt(mainSpace);
    }

   while(true)
    {
        cout << "fuck u" << endl;
        /*for(auto i = Worker::antPoint.begin() ; i != Worker::antPoint.end() ; i++)
            cout << "(" << i->first.x << "," << i->first.y << ") : " << i->second.get_name() << endl;
        cout << endl;*/
        update(mainSpace, onlyQueen);
        mainSpace.outputField();
        sleep(1);
    }
}