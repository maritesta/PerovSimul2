#include "SimpleEventAction.hh"
#include "SimpleAnalysisManager.hh"
#include "SimpleRun.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"

SimpleEventAction::SimpleEventAction()
  : G4UserEventAction(),
    fEdep(0.)
{} 

SimpleEventAction::~SimpleEventAction()
{}

void SimpleEventAction::BeginOfEventAction(const G4Event*)
{    
  fEdep = 0.;

  SimpleAnalysisManager::GetInstance()->BeginOfEvent();
}

void SimpleEventAction::EndOfEventAction(const G4Event* evt)
{   
  // accumulate statistics in SimpleRun                                                   
  SimpleRun* run = static_cast<SimpleRun*>(G4RunManager::GetRunManager()->GetNonConstCurrentRun());
  run->AddEdep(fEdep);
  
  // for histos
  SimpleAnalysisManager::GetInstance()->EndOfEvent();
}
