//#include "PrimaryGenerator.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

#include "generator.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"


PrimaryGenerator::PrimaryGenerator()
{
    G4int n_particle = 2;
    fParticleGun  = new G4ParticleGun(n_particle);
}

PrimaryGenerator::~PrimaryGenerator()
{
    delete fParticleGun;
}

void PrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName ="gamma";
    G4ParticleDefinition *particle = particleTable->FindParticle("gamma");
    
    G4ThreeVector pos(0., 0., 0.);  
    G4ThreeVector mom(0., 0., 1.); 
     
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(100.*GeV);
    fParticleGun->SetParticleDefinition(particle);
  
    fParticleGun->GeneratePrimaryVertex(anEvent);  
}

