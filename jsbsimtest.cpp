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
  fgic->SetMachIC(0.3);
  fgic->SetFlightPathAngleDegIC(-22.0);
  fgic->SetAlphaDegIC(8.0);
  fgic->SetAltitudeAGLFtIC(6000.0);
  fdmex.GetPropagate()->SetInitialState(fgic.get());
  fdmex.SetPropertyValue("fcs/elevator-pos-rad", -0.31);
  for (auto prop: fdmex.GetPropertyCatalog())
    cout << prop << endl;
  fdmex.RunIC();
  for (int i=0; i<2000; i++) {
    fdmex.Run();
    cout << "velocities: "
      << fdmex.GetPropertyValue("velocities/v-north-fps") << ", "
      << fdmex.GetPropertyValue("velocities/v-east-fps") << ", "
      << fdmex.GetPropertyValue("velocities/v-down-fps") << "; ";
    // cout << "forces in wind system: "
    //   << fdmex.GetPropertyValue("forces/fwx-aero-lbs") << ", "
    //   << fdmex.GetPropertyValue("forces/fwy-aero-lbs") << ", "
    //   << fdmex.GetPropertyValue("forces/fwz-aero-lbs") << "; ";
    // cout << "total forces in body system: "
    //      << fdmex.GetPropertyValue("forces/fbx-total-lbs") << ", "
    //      << fdmex.GetPropertyValue("forces/fby-total-lbs") << ", "
    //      << fdmex.GetPropertyValue("forces/fbz-total-lbs") << "; ";
    cout << "; aerodynamic moment: "
      << fdmex.GetPropertyValue("moments/l-aero-lbsft") << ", "
      << fdmex.GetPropertyValue("moments/m-aero-lbsft") << ", "
      << fdmex.GetPropertyValue("moments/n-aero-lbsft") << endl;
    // cout << "total moment: "
    //      << fdmex.GetPropertyValue("moments/l-total-lbsft") << ", "
    //      << fdmex.GetPropertyValue("moments/m-total-lbsft") << ", "
    //      << fdmex.GetPropertyValue("moments/n-total-lbsft") << endl;
  };
  return 0;
}
