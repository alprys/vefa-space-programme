#include "G4RunManager.hh"

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4SteppingVerbose.hh"
#include "G4LogicalVolume.hh"

#include "QBBC.hh"


int main(int argc, char** argv) {
    G4UIExecutive* ui = nullptr;
    if (argc == 1) {
        ui = new G4UIExecutive(argc, argv);
    }

    G4int precision = 4;
    G4SteppingVerbose::UseBestUnit(precision);

    auto runManager = new G4RunManager();
    auto visManager = new G4VisExecutive();

    auto detector = new alp::DetectorConstruction();
    runManager->SetUserInitialization(detector);

    auto physicsList = new QBBC;
    physicsList->SetVerboseLevel(1);
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new alp::ActionInitialization());

    runManager->Initialize();
    visManager->Initialize();

    auto UImanager = G4UImanager::GetUIpointer();
    if (!ui) {
        // Batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }
    else {
        // Interactive mode
        UImanager->ApplyCommand("/control/macroPath C:/Users/alpur/Desktop/Kodlar/g4/alp/");
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    }

    delete visManager;
    delete runManager;
}