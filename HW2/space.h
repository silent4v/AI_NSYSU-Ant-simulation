#ifndef __SPACE_H__
#define __SPACE_H__
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "base_object.h"
using namespace std;

#define TIME_INTERVAL 3
#define SPACE_INTERVAL 3
#define FOOD_INTERVAL 
#define MIN_X 3
#define MIN_Y 3
#define MAX_X space_size+SPACE_INTERVAL-1
#define MAX_Y space_size+SPACE_INTERVAL-1
//feature table
#define OUT_RANGE -1
#define EMPTY 0
#define ANT 2
#define PHEROMONE 4
#define FOOD 1
#define HOME 3
#define PHEROMONE_CONST 3

typedef int Space;
const int ant_amount = 5;
const int space_size = 100;
extern map<Base*,Point>space_map;
extern map<Base*,Point>::iterator p;
extern map<Base*,Point>cache;
extern map<Base*,Point>::iterator q;
extern int queen;

Space** create_space();     //create a space and initialize 
void add_feature(Space**,int t);     //add feature to space , t : feature table
void add_feature(Space**,int,Base*,Point);
void delete_ant(Space** s, int x, int y);
void file_write(Space** s);
Space** file_read();
void delete_var(Space** var);
void map_update(map<Base*,Point>&,map<Base*,Point>&);

#endif