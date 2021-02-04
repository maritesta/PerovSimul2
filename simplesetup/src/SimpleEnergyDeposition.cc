#include "SimpleEnergyDeposition.hh"

SimpleEnergyDeposition::SimpleEnergyDeposition()
  : fEnergy(0.), fTime(0.),fWeight(1.)
{;}

SimpleEnergyDeposition::SimpleEnergyDeposition( G4double energy, G4double time, G4double weight )
  : fEnergy(energy),
    fTime(time),
    fWeight(weight)
{;}

SimpleEnergyDeposition::SimpleEnergyDeposition(const SimpleEnergyDeposition &right )
  : fEnergy(right.fEnergy),
    fTime(right.fTime),
    fWeight(right.fWeight)
{;}
   
SimpleEnergyDeposition::~SimpleEnergyDeposition() {;}

G4bool SimpleEnergyDeposition::operator==
                                          ( const SimpleEnergyDeposition &right ) const
{
  return fTime == right.fTime;
}

G4bool SimpleEnergyDeposition::operator<
                                    ( const SimpleEnergyDeposition &right ) const
{
  return fTime < right.fTime;
}

G4bool SimpleEnergyDeposition::operator<=
                                    ( const SimpleEnergyDeposition &right ) const
{
  return fTime <= right.fTime;
}
