#ifndef SimpleActionInitialization_h
#define SimpleActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class SimpleActionInitialization : public G4VUserActionInitialization
{
  public:
    SimpleActionInitialization();
    virtual ~SimpleActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;
};

#endif

    
