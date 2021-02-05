#include "SimpleSteppingAction.hh"
#include "SimpleEventAction.hh"
#include "SimpleDetectorConstruction.hh"
#include "SimpleAnalysisManager.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"

SimpleSteppingAction::SimpleSteppingAction(SimpleEventAction* eventAction)
  : G4UserSteppingAction(),
    fEventAction(eventAction),
    fScoringVolume(0)
{}

SimpleSteppingAction::~SimpleSteppingAction()
{}

void SimpleSteppingAction::UserSteppingAction(const G4Step* step)
{
  G4Track* fTrack = step->GetTrack();
  G4int StepNo = fTrack->GetCurrentStepNumber();
  if(StepNo >= 10000) fTrack->SetTrackStatus(fStopAndKill);
  
  // this step
  G4double time   = step->GetPreStepPoint()->GetGlobalTime()/ns;
  G4double weight = step->GetPreStepPoint()->GetWeight();

  SimpleAnalysisManager* analysis = SimpleAnalysisManager::GetInstance();

  // Chiara: for egamma studies        
/* 
 if (StepNo == 1) { //beginning of step                                                                      
    G4double energy = step->GetPreStepPoint()->GetKineticEnergy()/keV;
    G4String partType= fTrack->GetDefinition()->GetParticleType();
    
    if (fTrack->GetTrackID() != 1 ){
      if (fTrack->GetCreatorProcess()->GetProcessName() == "RadioactiveDecay") {   //Radioactive decay products    
	// emitted particles except nuclei   
	if ( partType!= "nucleus") analysis->AddParticle(energy);    
      }
    }
  } // 1st step
*/
//Marianna
if (StepNo == 1) { //beginning of step                                                                      
    G4double energy = step->GetPreStepPoint()->GetKineticEnergy()/keV;
    G4String partType= fTrack->GetDefinition()->GetParticleType();
  if (1){
 //   if (fTrack->GetTrackID() != 1 ){
   if (1){
  //    if (fTrack->GetCreatorProcess()->GetProcessName() == "RadioactiveDecay") {   //Radioactive decay products    
        // emitted particles except nuclei   
                  if ( partType!= "nucleus") analysis->AddParticle(energy);
                       }
                           }
                             } // 1st step
        
                             
  /*
  // Chiara: for alpha studies
  if (StepNo == 1) { //beginning of step  
    G4double energy = step->GetPreStepPoint()->GetKineticEnergy()/keV;
    if (energy>0 && fTrack->GetDefinition()->GetParticleName() == "alpha" ) analysis->AddParticle(energy);    
  }
  */

  // energy deposition in the scintillator
  if (!fScoringVolume) { 
    const SimpleDetectorConstruction* detectorConstruction
      = static_cast<const SimpleDetectorConstruction*>
      (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detectorConstruction->GetScoringVolume();   
  }

  // get volume of the current step
  G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
      
  // check if we are in scoring volume
  if (volume != fScoringVolume) return;

  // chiara, for alpha studies only:
  // if (fTrack->GetDefinition()->GetParticleName() != "alpha") return;
  // if (edepStep<0) return;
  // chiara, for alpha studies only:

  G4double edepStep = step->GetTotalEnergyDeposit()/keV;
//Marianna
if ( edepStep) {
//  if (fTrack->GetTrackID() != 1 && edepStep) {
    if (volume == fScoringVolume) analysis->AddEnergy(edepStep,weight,time);  
    if (volume == fScoringVolume) fEventAction->AddEdep(edepStep);  
  }      
}



