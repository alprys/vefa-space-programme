#include "SteppingAction.hh"

#include "G4Step.hh"
#include "G4ios.hh"
#include "EventAction.hh"

namespace alp {
	SteppingAction::SteppingAction(EventAction* event) : fEventAction(event) {}

	void SteppingAction::UserSteppingAction(const G4Step* step) {
		auto preVolume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
		if (!preVolume) return;

		G4String volumeName = preVolume->GetName();
		if (volumeName == "Detector") {
			G4Track* track = step->GetTrack();

			fEventAction->SetDetectorHit(true);
			fEventAction->AddToDetectedEnergies(track->GetKineticEnergy());
		}
	}
}