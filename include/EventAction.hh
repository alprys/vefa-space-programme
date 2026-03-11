#ifndef EventAction_h
#define EventAction_h

#include "G4UserEventAction.hh"
#include "G4LogicalVolume.hh"
#include "globals.hh"
#include <vector>
#include <string>

class G4Event;

namespace alp {
	class EventAction : public G4UserEventAction {
	public:
		EventAction();
		~EventAction() override = default;
		void BeginOfEventAction(const G4Event* event) override;
		void EndOfEventAction(const G4Event* event) override;

		void AddEnergy(G4double energy) { fEnergyDep += energy; };
		void SetDetectorHit(G4bool hit) { fDetectorHit = hit; }

		void AddToDetectedEnergies(const G4double& energy) { fDetectedEnergies.push_back(energy); };
		void AddToUnknownParticles(const std::string& particle) { fUnknownParticles.push_back(particle); }
		const std::vector<G4double>& GetDetectedEnergies() const { return fDetectedEnergies; }
		const std::vector<std::string>& GetUnknownParticles() const { return fUnknownParticles; }
	private:
		G4double fEnergyDep = 0.;
		G4bool fDetectorHit;
		std::vector<G4double> fDetectedEnergies;
		std::vector<std::string> fUnknownParticles;
	};
}

#endif