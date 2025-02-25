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
  fgic->SetMachIC(0.6);
  fgic->SetAlphaDegIC(10.0);
  fgic->SetAltitudeAGLFtIC(1000.0);
  fdmex.GetPropagate()->SetInitialState(fgic.get());
  fdmex.SetPropertyValue("fcs/elevator-pos-norm", +1.0);
  fdmex.SetPropertyValue("fcs/flap-pos-norm", 0.0);
  fdmex.RunIC();
  for (auto prop: fdmex.GetPropertyCatalog())
    cout << prop << endl;
  cout << "forces in wind system: "
       << fdmex.GetPropertyValue("forces/fwx-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fwy-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fwz-aero-lbs") << endl;
  cout << "forces in body system: "
       << fdmex.GetPropertyValue("forces/fbx-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fby-aero-lbs") << ", "
       << fdmex.GetPropertyValue("forces/fbz-aero-lbs") << endl;
  cout << "aerodynamic moment: "
       << fdmex.GetPropertyValue("moments/l-aero-lbsft") << ", "
       << fdmex.GetPropertyValue("moments/m-aero-lbsft") << ", "
       << fdmex.GetPropertyValue("moments/n-aero-lbsft") << endl;
  cout << "total moment: "
       << fdmex.GetPropertyValue("moments/l-total-lbsft") << ", "
       << fdmex.GetPropertyValue("moments/m-total-lbsft") << ", "
       << fdmex.GetPropertyValue("moments/n-total-lbsft") << endl;
  return 0;
}
