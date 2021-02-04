#ifndef SimpleAnalysisManager_h
#define SimpleAnalysisManager_h 1

#include "globals.hh"
#include "SimpleEnergyDeposition.hh"
#include <vector>

class SimpleHisto;

class SimpleAnalysisManager
{

public:

  // With description
  static SimpleAnalysisManager* GetInstance();
  static void Dispose();
  
private:
  
  SimpleAnalysisManager();
  ~SimpleAnalysisManager();

public: // Without description

  void BookHisto();

  void BeginOfRun();
  void EndOfRun(G4int);

  void BeginOfEvent();
  void EndOfEvent();

  void AddEnergy(G4double, G4double, G4double);
  void AddParticle(G4double);

  void SetVerbose(G4int val) {fVerbose = val;};
  G4int GetVerbose() const {return fVerbose;};

private:

  // MEMBERS
  static SimpleAnalysisManager* fManager;

  G4int fVerbose;

  G4double fVThresE;

  // energy depositions for an event
  std::vector <SimpleEnergyDeposition> fEdepo;
  //
  SimpleHisto*  fHisto;  
};

#endif
