#ifndef RunAction_h
#define RunAction_h

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"

class G4Run;

namespace alp {

	class EventAction;
	class PrimaryGeneratorAction;

	class RunAction : public G4UserRunAction {
	public:
		RunAction(EventAction* eventAction, PrimaryGeneratorAction* primary);
		~RunAction() override = default;

		void BeginOfRunAction(const G4Run*) override;
		void EndOfRunAction(const G4Run*) override;

		void AddEnergy(G4double energy) { fEnergyDep += energy; };

	private:
		G4Accumulable<G4double> fEnergyDep = 0.0;
		G4Accumulable<G4double> fEnergyDep2 = 0.;
		EventAction* fEventAction;
		PrimaryGeneratorAction* fPrimary;
	};
}

#endif