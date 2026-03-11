#include "PrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4ThreeVector.hh"

namespace alp {
	PrimaryGeneratorAction::PrimaryGeneratorAction() {
		fParticleGun = new G4ParticleGun(1);

		G4ParticleDefinition* particle = G4ParticleTable::GetParticleTable()->FindParticle("proton");
		fParticleGun->SetParticleDefinition(particle);
		fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0., 0., 1.));
		fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -0.5 * m));
		fParticleGun->SetParticleEnergy(100. * MeV);
	}

	PrimaryGeneratorAction::~PrimaryGeneratorAction() {
		delete fParticleGun;
	}

	void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
		fParticleGun->GeneratePrimaryVertex(event);
	}
}