#include "SimpleRun.hh"

SimpleRun::SimpleRun()
: G4Run(),
  fEdep(0.)
{} 

SimpleRun::~SimpleRun()
{} 

void SimpleRun::Merge(const G4Run* run)
{
  const SimpleRun* localRun = static_cast<const SimpleRun*>(run);
  fEdep += localRun->fEdep;

  G4Run::Merge(run); 
} 

void SimpleRun::AddEdep(G4double edep)
{
  fEdep += edep;
}

