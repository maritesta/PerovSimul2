#ifndef SimpleRunAction_h
#define SimpleRunAction_h 1

#include "SimpleRun.hh"   
#include "SimplePrimaryGeneratorAction.hh"
#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Run;

class SimpleRunAction : public G4UserRunAction
{
public:
  SimpleRunAction(SimplePrimaryGeneratorAction*);
  virtual ~SimpleRunAction();
  
  virtual G4Run* GenerateRun();
  virtual void BeginOfRunAction(const G4Run*);
  virtual void   EndOfRunAction(const G4Run*);

private:
  SimplePrimaryGeneratorAction* fPrimary;
};

#endif

