#ifndef Run_HH
#define Run_HH

#include "G4UserRunAction.hh"
#include "globals.hh"
#include "G4AnalysisManager.hh"

//class G4Run;

class RunAction : public G4UserRunAction
{
public:
    RunAction();
    ~RunAction(); //override = default;

    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
};

#endif

