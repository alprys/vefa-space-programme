#ifndef SteppingAction_h
#define SteppingAction_h

#include "G4UserSteppingAction.hh"
#include "G4Step.hh"

class G4Step;
class G4LogicalVolume;

namespace alp {

	class EventAction;

	class SteppingAction : public G4UserSteppingAction {
	public:
		SteppingAction(EventAction* eventAction);
		~SteppingAction() override = default;

		void UserSteppingAction(const G4Step*) override;
	private:
		EventAction* fEventAction = nullptr;
		G4LogicalVolume* fScoringVolume = nullptr;
	};
}

#endif