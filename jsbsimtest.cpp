#include <iostream>
#include <FGFDMExec.h>

using namespace std;
using namespace JSBSim;

int main(void)
{
  FGFDMExec fdmex;
  fdmex.LoadModel("Shuttle");
}
