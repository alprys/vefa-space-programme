#ifndef ActionInitialization_h
#define ActionInitialization_h

#include "G4VUserActionInitialization.hh"
#include "G4LogicalVolume.hh"

namespace alp {
    class ActionInitialization : public G4VUserActionInitialization {
    public:
        ActionInitialization();
        ~ActionInitialization() override = default;

        void Build() const override;
    private:
        G4LogicalVolume* fScoringVolume;
    };
}

#endif