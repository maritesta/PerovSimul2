#ifndef SimpleDetectorConstruction_h
#define SimpleDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class SimpleDetectorConstruction : public G4VUserDetectorConstruction
{
public:
  SimpleDetectorConstruction();
  virtual ~SimpleDetectorConstruction();
  
  virtual G4VPhysicalVolume* Construct();
  
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }
  
protected:
  G4LogicalVolume*  fScoringVolume;
  
private:
  void DefineMaterials();
};

#endif

