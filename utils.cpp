#include "utils.h"
#include <iostream>

using namespace std;

int randint(int a, int b) {
  return (rand()%(abs(a-b))+min(a,b));
}
