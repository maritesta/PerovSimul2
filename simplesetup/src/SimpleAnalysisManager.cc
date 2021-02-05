#include "SimpleAnalysisManager.hh"
#include "G4UnitsTable.hh"
#include "SimpleHisto.hh"
#include "G4ProcessTable.hh"
#include "G4RadioactiveDecay.hh"
#include "G4TwoVector.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>

SimpleAnalysisManager* SimpleAnalysisManager::fManager = 0;

SimpleAnalysisManager* SimpleAnalysisManager::GetInstance()
{
  if(!fManager) fManager = new SimpleAnalysisManager();
  
  return fManager;
}

void SimpleAnalysisManager::Dispose()
{
  delete fManager;
  fManager = 0;
}

SimpleAnalysisManager::SimpleAnalysisManager()
  : fVerbose(0),
    fVThresE(20*keV)
{
  fEdepo.clear();
  fHisto = new SimpleHisto();
  BookHisto();
}

SimpleAnalysisManager::~SimpleAnalysisManager()     
{
  delete fHisto;
}

void SimpleAnalysisManager::BookHisto()         
{
  G4double fHistEMax = 2500;
  G4double fHistEMin = 0;
  G4double fHistTMax = 3E17;
  G4double fHistTMin = 1E15;
  G4int fHistNBinT = 100;
  G4int fHistNBinE = 2500;

  // Chiara, for alpha
  // G4double fHistEMax = 7000;
  // G4double fHistEMin = 3500;
  // G4int fHistNBinE = 3500;
  
  fHisto->Add1D("H0", "Energy deposit (keV) in scintillator", fHistNBinE,fHistEMin,fHistEMax);
  fHisto->Add1D("H1", "1st Time deposit (nanosecond) in scintillator", fHistNBinT,fHistTMin,fHistTMax);
  fHisto->Add1D("H2", "Decay emission spectrum (keV)",fHistNBinE,fHistEMin,50*fHistEMax);
}
 
void SimpleAnalysisManager::BeginOfRun()  
{
  fHisto->Book();
}

void SimpleAnalysisManager::EndOfRun(G4int nevent)    
{
  fHisto->Save();
  G4cout << "SimpleAnalysisManager: Histograms have been saved!" << G4endl;
}

void SimpleAnalysisManager::BeginOfEvent()    
{
  fEdepo.clear();
}

void SimpleAnalysisManager::EndOfEvent()        
{
  if (fEdepo.size()) {

    std::sort(fEdepo.begin(),fEdepo.end());    

    G4double firstTimeV = 0;
    G4double VE = 0;

    for (size_t i = 0; i < fEdepo.size(); i++) {
      if ( ((firstTimeV==0) || (fEdepo[i].GetTime()<firstTimeV)) && fEdepo[i].GetEnergy() > fVThresE ) firstTimeV = fEdepo[i].GetTime();
      VE += fEdepo[i].GetEnergy();
    }
    if (firstTimeV>0) fHisto->FillHisto(1,firstTimeV,1);      
    if (VE) fHisto->FillHisto(0,VE,1);        // scitnillator energy histogram

    // now add zero energy to separate events
    AddEnergy(0.,0.,0.);
  }
}

void SimpleAnalysisManager::AddEnergy(G4double edep, G4double weight, G4double time) 
{
  SimpleEnergyDeposition A(edep,time,weight);
  fEdepo.push_back(A);
}

// energy spectrum for particles emitted in decay 
void SimpleAnalysisManager::AddParticle(G4double energy) 
{
  if (energy>0.0) fHisto->FillHisto(2,energy,1);
}


