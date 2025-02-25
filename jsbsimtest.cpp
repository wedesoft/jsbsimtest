#include <memory>
#include <iostream>
#include <FGFDMExec.h>
#include <initialization/FGInitialCondition.h>

using namespace std;
using namespace JSBSim;

int main(void)
{
  FGFDMExec fdmex;
  fdmex.LoadModel("Shuttle");
  shared_ptr<FGInitialCondition> fgic = fdmex.GetIC();
  fgic->InitializeIC();
  fgic->SetMachIC(0.8);
  fgic->SetAlphaDegIC(10.0);
  fgic->SetAltitudeAGLFtIC(1000.0);
  fdmex.GetPropagate()->SetInitialState(fgic.get());
  fdmex.RunIC();
  cout << "forces in wind system: "
       << fdmex.GetPropertyValue("forces/fwx-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fwy-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fwz-aero-lbs") << endl;
  cout << "forces in body system: "
       << fdmex.GetPropertyValue("forces/fbx-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fby-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fbz-aero-lbs") << endl;
  return 0;
}
