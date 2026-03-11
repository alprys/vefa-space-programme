#ifndef TrackingAction_h
#define TrackingAction_h

#include "G4UserTrackingAction.hh"
#include "G4Track.hh"

namespace alp {

	class EventAction;

	class TrackingAction : public G4UserTrackingAction {
	public:
		explicit TrackingAction(EventAction* event);
		~TrackingAction() override = default;
		void PreUserTrackingAction(const G4Track* track) override;
		void PostUserTrackingAction(const G4Track* track) override;
	private:
		EventAction* fEventAction;
	};
}

#endif