#include "SimplePrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "Randomize.hh"

SimplePrimaryGeneratorAction::SimplePrimaryGeneratorAction()
  : G4VUserPrimaryGeneratorAction(),
    fParticleGun(0)
{
  G4int n_particle = 1;
  fParticleGun  = new G4ParticleGun(n_particle);
  
  // at rest in (0,0,0)
  fParticleGun->SetParticleEnergy(0*eV);
  fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
}

SimplePrimaryGeneratorAction::~SimplePrimaryGeneratorAction()
{
  delete fParticleGun;
}

void SimplePrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
  fParticleGun->GeneratePrimaryVertex(anEvent);
}



