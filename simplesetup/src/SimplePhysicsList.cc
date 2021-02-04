#include "SimplePhysicsList.hh"
#include "SimplePhysListParticles.hh"

#include "G4EmStandardPhysics.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"
#include "G4ParticleTable.hh"

#include "G4Gamma.hh"
#include "G4Electron.hh"
#include "G4Positron.hh"

#include "G4UnitsTable.hh"
#include "G4LossTableManager.hh"

#include "G4StoppingPhysics.hh"
#include "G4IonBinaryCascadePhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4NeutronTrackingCut.hh"
#include "G4DecayPhysics.hh"

#include "G4SystemOfUnits.hh"

SimplePhysicsList::SimplePhysicsList() :
  G4VModularPhysicsList(),
  fCutForGamma(1.*mm), 
  fCutForElectron(1.*mm),
  fCutForPositron(1.*mm), 
  fEmPhysicsList(0),
  fRaddecayList(0),
  fParticleList(0)
{
  G4LossTableManager::Instance();
  defaultCutValue =1.*mm;
  
  SetVerboseLevel(1);

  // default physics
  fParticleList = new G4DecayPhysics();

  // default physics
  fRaddecayList = new G4RadioactiveDecayPhysics();

  // EM physics
  fEmPhysicsList = new G4EmStandardPhysics();
}

SimplePhysicsList::~SimplePhysicsList()
{
  delete fRaddecayList;
  delete fEmPhysicsList;
}

void SimplePhysicsList::ConstructParticle()
{
  fParticleList->ConstructParticle();
}

void SimplePhysicsList::ConstructProcess()
{
  AddTransportation();
  // em
  fEmPhysicsList->ConstructProcess();
  // decays
  fParticleList->ConstructProcess();
  fRaddecayList->ConstructProcess();
  G4cout << "### SimplePhysicsList::ConstructProcess is done" << G4endl;
}

void SimplePhysicsList::SetCuts()
{
  SetCutValue(fCutForGamma, "gamma");
  SetCutValue(fCutForElectron, "e-");
  SetCutValue(fCutForPositron, "e+");
  G4cout << "world cuts are set" << G4endl;

  if (verboseLevel>0) DumpCutValuesTable();
}

void SimplePhysicsList::SetCutForGamma(G4double cut)
{
  fCutForGamma = cut;
  SetParticleCuts(fCutForGamma, G4Gamma::Gamma());
}

void SimplePhysicsList::SetCutForElectron(G4double cut)
{
  fCutForElectron = cut;
  SetParticleCuts(fCutForElectron, G4Electron::Electron());
}

void SimplePhysicsList::SetCutForPositron(G4double cut)
{
  fCutForPositron = cut;
  SetParticleCuts(fCutForPositron, G4Positron::Positron());
}

