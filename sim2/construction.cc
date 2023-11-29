#include "construction.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

DetectorConstruction::DetectorConstruction()
{}

DetectorConstruction::~DetectorConstruction()
{}

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4NistManager* nist = G4NistManager::Instance();
  
    G4double world_x = 2.0 * m;
    G4double world_y = 3.0 * m; 
    G4double world_z = 3.0 * m;
  
    G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
    G4bool checkOverlaps = true;

    G4Box *SolidWorld = new G4Box("SolidWorld", 0.5 * world_x, 0.5 * world_y, 0.5 * world_z);       

    G4LogicalVolume *logicWorld = new G4LogicalVolume(SolidWorld,  
                                                    world_mat,                                       
                                                    "World");                                       

    G4VPhysicalVolume* physWorld = new G4PVPlacement(0,
                                                   G4ThreeVector(0., 0., 0.),                           
                                                   logicWorld,                                
                                                   "physWorld",                                   
                                                   0,                                  
                                                   false,                                     
                                                   0,                                         
                                                   checkOverlaps);                            
   return physWorld; 
}
