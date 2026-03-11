#include "EventAction.hh"

#include "G4Event.hh"
#include "G4ios.hh"

namespace alp {
	EventAction::EventAction() {}

	void EventAction::BeginOfEventAction(const G4Event* event) {
		// G4cout << "Event " << event->GetEventID() << " has begun. " << G4endl;
	}

	void EventAction::EndOfEventAction(const G4Event* event) {
		/*if (fDetectorHit) {
			G4cout << "Proton of event " << event->GetEventID() << "has HIT the human skin with energy: " <<  << G4endl;
		} else {
			G4cout << "Proton of event " << event->GetEventID() << " has NOT hit the human skin." << G4endl;
		}*/
	}
}