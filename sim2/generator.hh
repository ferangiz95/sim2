#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"
#include "G4Event.hh"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

//class G4GeneralParticleSource;
class G4Event;
class PrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
public:
    PrimaryGenerator();
    ~PrimaryGenerator();
    
    virtual void GeneratePrimaries(G4Event* /*anEvent*/);

private:
    G4ParticleGun *fParticleGun;
};

#endif
