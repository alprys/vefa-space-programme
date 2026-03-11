#ifndef PrimaryActionGenerator_h
#define PrimaryActionGenerator_h

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"

class G4Event;

namespace alp {
    class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
    public:
        PrimaryGeneratorAction();
        ~PrimaryGeneratorAction() override;

        virtual void GeneratePrimaries(G4Event* event) override;

        G4ParticleGun* GetParticleGun() const { return fParticleGun; }
    private:
        G4ParticleGun* fParticleGun;
    };
}

#endif