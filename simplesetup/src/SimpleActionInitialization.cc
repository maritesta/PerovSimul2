#include "SimpleActionInitialization.hh"
#include "SimplePrimaryGeneratorAction.hh"
#include "SimpleRunAction.hh"
#include "SimpleEventAction.hh"
#include "SimpleSteppingAction.hh"

SimpleActionInitialization::SimpleActionInitialization()
 : G4VUserActionInitialization()
{}

SimpleActionInitialization::~SimpleActionInitialization()
{}

void SimpleActionInitialization::BuildForMaster() const
{
  SimpleRunAction* runAction = new SimpleRunAction(0);
  SetUserAction(runAction);
}

void SimpleActionInitialization::Build() const
{
  SimplePrimaryGeneratorAction* primary = new SimplePrimaryGeneratorAction();    
  SetUserAction(primary);

  SimpleRunAction* runAction = new SimpleRunAction(primary);                     
  SetUserAction(runAction);
  
  SimpleEventAction* eventAction = new SimpleEventAction();                      
  SetUserAction(eventAction);
  
  SetUserAction(new SimpleSteppingAction(eventAction));                   
}  
