#ifndef SimpleEnergyDeposition_h
#define SimpleEnergyDeposition_h 1

#include "globals.hh"

class SimpleEnergyDeposition
{
public:   
  SimpleEnergyDeposition();
  SimpleEnergyDeposition( const SimpleEnergyDeposition &right );
  SimpleEnergyDeposition( G4double, G4double, G4double );
  virtual ~SimpleEnergyDeposition();

  G4bool operator==(const SimpleEnergyDeposition &right) const ;
  G4bool operator< (const SimpleEnergyDeposition &right) const ;
  G4bool operator<=(const SimpleEnergyDeposition &right) const ;

  G4double GetEnergy() {return fEnergy;};
  G4double GetTime() {return fTime;};
  G4double GetWeight() {return fWeight;};
  
private:
  G4double fEnergy;  
  G4double fTime;    
  G4double fWeight;
};

#endif
