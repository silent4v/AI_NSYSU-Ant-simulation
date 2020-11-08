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
#define SPACE_INTERVAL 20
#define FOOD_INTERVAL 
#define MIN_X 3
#define MIN_Y 3
#define MAX_X space_size+SPACE_INTERVAL-1
#define MAX_Y space_size+SPACE_INTERVAL-1
//feature table
#define ANT 6
#define PHEROMONE 2
#define FOOD 3
#define HOME 5

typedef int Space;
const int ant_amount = 5;
const int space_size = 100;
extern map<Point,Base*>space_map;
extern map<Point,Base*>::iterator p;

Space** create_space();     //create a space and initialize 
void add_feature(Space**,int t);     //add feature to space , t : feature table
void add_feature(Space**,int,Point,Base*);
void delete_ant(Space** s, int x, int y);
void file_write(Space** s);
Space** file_read();
void delete_var(Space** var);


#endif