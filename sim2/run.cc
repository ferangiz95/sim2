//#include "RunAction.hh"
#include "run.hh"

#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
{}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{
    auto analysisManager = G4AnalysisManager::Instance();

    analysisManager->OpenFile("output.root");
  
    analysisManager->CreateNtuple("Hits", "Hits");
    analysisManager->CreateNtupleIColumn("fEvent");
    analysisManager->CreateNtupleIColumn("fX");
    analysisManager->CreateNtupleIColumn("fY");
    analysisManager->CreateNtupleIColumn("fZ");
    analysisManager->FinishNtuple(0);
}

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
    auto analysisManager = G4AnalysisManager::Instance();
    
    analysisManager->Write();
    analysisManager->CloseFile();
}
