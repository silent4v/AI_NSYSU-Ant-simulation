#include <iostream>
#include "ant.h"
using namespace std;
int main()
{
    Space **tt = create_space();
    delete_var(tt);
    return 0;
}