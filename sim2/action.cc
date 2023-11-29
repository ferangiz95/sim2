#include "action.hh"
#include "generator.hh"
//#include "PrimaryGeneratorAction.hh"

ActionInitialization::ActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}
void ActionInitialization::Build() const
{
    PrimaryGenerator *generator = new PrimaryGenerator();
    SetUserAction(generator);
    
    RunAction *runAction = new RunAction();
    SetUserAction(runAction);
    
    /*EventAction *eventAction = new EventAction();
    SetUserAction(eventAction);*/
}
