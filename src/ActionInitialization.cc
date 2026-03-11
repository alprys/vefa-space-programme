#include "ActionInitialization.hh"

#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "TrackingAction.hh"

#include "G4LogicalVolume.hh"

namespace alp {
	ActionInitialization::ActionInitialization() {}

	void ActionInitialization::Build() const {
		auto primaryGeneratorAction = new PrimaryGeneratorAction();
		SetUserAction(primaryGeneratorAction);

		auto eventAction = new EventAction();
		SetUserAction(eventAction);

		SetUserAction(new RunAction(eventAction, primaryGeneratorAction));
		SetUserAction(new SteppingAction(eventAction));
		SetUserAction(new TrackingAction(eventAction));
	}
}