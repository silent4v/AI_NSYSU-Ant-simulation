#ifndef __SPACE_H__
#define __SPACE_H__
#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define TIME_INTERVAL 3
#define SPACE_INTERVAL 3
#define MIN_X 3
#define MIN_Y 3
#define MAX_X size-4
#define MAX_Y size-4
typedef int Space;
const int ant_amount = 5;
const int size = 100;

Space** create_space();
void delete_ant(Space** s, int x, int y);
void file_write(Space** s);
Space** file_read();
void delete_var(Space** var);

#endif