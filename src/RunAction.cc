#include "RunAction.hh"

#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include "EventAction.hh"
#include "PrimaryGeneratorAction.hh"

#include <fstream>

namespace alp {
	RunAction::RunAction(EventAction* eventAction, PrimaryGeneratorAction* primary) : fEventAction(eventAction), fPrimary(primary) {
		G4AccumulableManager::Instance()->Register(fEnergyDep);
		G4AccumulableManager::Instance()->Register(fEnergyDep2);
	}
	void RunAction::BeginOfRunAction(const G4Run* run) {
		fEnergyDep = 0.;
		fEnergyDep2 = 0.;

		if (fPrimary) {
			G4double e = fPrimary->GetParticleGun()->GetParticleEnergy();
			G4cout << "Run " << run->GetRunID() << " is starting with energy: " << e / MeV << " MeV" << G4endl;
		}
	}
	void RunAction::EndOfRunAction(const G4Run* run) {
		G4int nEvents = run->GetNumberOfEvent();
		if (nEvents == 0) return;

		G4cout << "Run " << run->GetRunID() << " has been completed! A grand total of " << nEvents << " events have been processed." << G4endl;
		
		if (!fEventAction) {
			G4cerr << "A big problem: fEventAction pointer is null!" << G4endl;
			return;
		}

		const auto& energies = fEventAction->GetDetectedEnergies();
		std::ofstream fileE("EnergiesTest.csv");

		fileE << "Particle_index,Energy_MeV\n";

		double sumE = 0;
		for (size_t i = 0; i < energies.size(); i++) {
			double e = energies[i] / MeV;
			fileE << i << "," << e << "\n";
			sumE += e;
		}

		fileE << "Average" << "," << (sumE / energies.size()) << "\n";

		fileE.close();

		G4cout << "From these events, all individual energies detected at the detector have been written into EnergiesTest.csv" << G4endl;
		G4cout << "The average energy detected was " << (sumE / energies.size()) << G4endl;

		const auto& uParticles = fEventAction->GetUnknownParticles();
		std::ofstream fileP("UnknownParticlesTest.csv");

		fileP << "Index,Particle_name\n";

		for (size_t i = 0; i < uParticles.size(); i++) {
			fileP << i << "," << uParticles[i] << "\n";
		}

		fileP.close();

		G4cout << "From these events, there were " << uParticles.size() << " unknown particles (aka, non-protons) created. All these particles have been written into UnknownParticlesTest.csv" << G4endl;
	}
}