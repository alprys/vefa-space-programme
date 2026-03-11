#include "TrackingAction.hh"

#include "EventAction.hh"
#include "G4Track.hh"

namespace alp {
	TrackingAction::TrackingAction(EventAction* event) : fEventAction(event) {}

	void TrackingAction::PreUserTrackingAction(const G4Track* track) {
		if (track->GetDefinition()->GetParticleName() != "proton") {
			fEventAction->AddToUnknownParticles(track->GetDefinition()->GetParticleName());
		}
	}
	void TrackingAction::PostUserTrackingAction(const G4Track* track) {}
}