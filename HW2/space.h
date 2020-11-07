#include <iostream>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
using namespace std;

#define TIME_INTERVAL 5;
const int ant_amount = 5;
const int size = 100;

int** create_space();
void delete_ant(int** s, int x, int y);
void file_write(int** s);
int** file_read();
void delete_var(int** var);