#ifndef SimplePhysListParticles_h
#define SimplePhysListParticles_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class SimplePhysListParticles : public G4VPhysicsConstructor
{
public: 
  SimplePhysListParticles(const G4String& name = "particles");
  virtual ~SimplePhysListParticles();
  
public: 
  // This method will be invoked in the Construct() method. 
  // each particle type will be instantiated
  virtual void ConstructParticle();
  
  // This method is dummy.
  virtual void ConstructProcess() {};
};

#endif








