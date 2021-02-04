#ifndef SimpleHisto_h
#define SimpleHisto_h 1

#include "globals.hh"
#include <vector>

// Root classes
class TFile;
class TH1D;
class TNtuple;

class SimpleHisto
{

public:
  SimpleHisto();

  ~SimpleHisto();

  void Book();
  void Save();

  void Add1D(const G4String&, const G4String&, G4int nb=100, G4double x1=0., G4double x2=1.);

  void SetHisto1D(G4int, G4int, G4double, G4double, G4double);

  void FillHisto(G4int, G4double, G4double);

  void ScaleHisto(G4int, G4double);

  void SetFileName(const G4String&);
  const G4String& GetFileName() const;  

  void SetFileType(const G4String&);
  const G4String& FileType() const;
  
private:
  
  G4String fHistName;
  G4String fHistType;

  G4int    fNHisto;
  G4int    fVerbose;
  G4int    fDefaultAct;

  TFile* fHfileROOT; 
  std::vector<TH1D*> fROOThisto;
  std::vector<TNtuple*>   fROOTntup;
  std::vector< std::vector<float> > fRarray;
  std::vector<G4int> fRcol;
  
  std::vector<G4int>     fActive;
  std::vector<G4int>     fBins;
  std::vector<G4double>  fXmin;
  std::vector<G4double>  fXmax;
  std::vector<G4String>  fIds;
  std::vector<G4String>  fTitles;
};

#endif
