#ifndef SimplePhysicsList_h
#define SimplePhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"
#include <vector>

class G4VPhysicsConstructor;
class G4ProductionCuts;

class SimplePhysicsList: public G4VModularPhysicsList
{
public:
  SimplePhysicsList();
  virtual ~SimplePhysicsList();

  virtual void ConstructParticle();

  virtual void SetCuts();
  void SetCutForGamma(G4double);
  void SetCutForElectron(G4double);
  void SetCutForPositron(G4double);

  virtual void ConstructProcess();

private:

  // hide assignment operator
  SimplePhysicsList & operator=(const SimplePhysicsList &right);
  SimplePhysicsList(const SimplePhysicsList&);

  G4double fCutForGamma;
  G4double fCutForElectron;
  G4double fCutForPositron;

  G4VPhysicsConstructor*  fEmPhysicsList;
  G4VPhysicsConstructor*  fRaddecayList;
  G4VPhysicsConstructor*  fParticleList;
};

#endif

