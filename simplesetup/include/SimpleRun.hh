#ifndef SimpleRun_h
#define SimpleRun_h 1

#include "G4Run.hh"
#include "globals.hh"

class G4Event;

class SimpleRun : public G4Run
{
  public:
    SimpleRun();
    virtual ~SimpleRun();

    // method from the base class
    virtual void Merge(const G4Run*);
    
    void AddEdep (G4double edep); 

    // get methods
    G4double GetEdep() const { return fEdep; }

  private:
    G4double  fEdep;
};

#endif

