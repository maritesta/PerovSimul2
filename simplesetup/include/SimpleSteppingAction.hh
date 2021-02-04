#ifndef SimpleSteppingAction_h
#define SimpleSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class SimpleEventAction;

class G4LogicalVolume;

class SimpleSteppingAction : public G4UserSteppingAction
{
  public:
    SimpleSteppingAction(SimpleEventAction* eventAction);
    virtual ~SimpleSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    SimpleEventAction*  fEventAction;
    G4LogicalVolume* fScoringVolume;
};

#endif
