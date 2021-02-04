#ifndef SimpleEventAction_h
#define SimpleEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

/// Event action class
class SimpleEventAction : public G4UserEventAction
{
public:
  SimpleEventAction();
  virtual ~SimpleEventAction();
  
  virtual void BeginOfEventAction(const G4Event* event);
  virtual void EndOfEventAction(const G4Event* event);
  
  void AddEdep(G4double edep) { fEdep += edep; }
  
private:
  G4double     fEdep;
};

#endif

    
