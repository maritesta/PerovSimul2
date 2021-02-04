#include "SimpleRunAction.hh"
#include "SimpleAnalysisManager.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include <G4Gamma.hh>

SimpleRunAction::SimpleRunAction(SimplePrimaryGeneratorAction* kin)
  : G4UserRunAction(),
    fPrimary(kin)
{}

SimpleRunAction::~SimpleRunAction()
{}

G4Run* SimpleRunAction::GenerateRun()  
{
  return new SimpleRun;
}

void SimpleRunAction::BeginOfRunAction(const G4Run*)
{ 
  // inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);
  
  // Creation of the analysis manager
  SimpleAnalysisManager* analysis = SimpleAnalysisManager::GetInstance();
  analysis->BeginOfRun();
}

void SimpleRunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) return;
  
  // Total deposits
  const SimpleRun* myRun = static_cast<const SimpleRun*>(run);
  G4double edep = myRun->GetEdep();

  // Get the analysis manager
  SimpleAnalysisManager* analysis = SimpleAnalysisManager::GetInstance();
  analysis->EndOfRun(run->GetNumberOfEvent());  

  // Print
  G4cout << "--------------------End of Run------------------------" << G4endl;
  G4cout << "The run consists of " << nofEvents << " events" << G4endl;
  G4cout << "Total deposited energy in scintillator = "  << edep << " [keV]" << G4endl;
  G4cout << G4endl;
}

