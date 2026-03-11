#include "DetectorConstruction.hh"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4SystemOfUnits.hh"

namespace alp {
	G4VPhysicalVolume* DetectorConstruction::Construct() {
		G4NistManager* nist = G4NistManager::Instance();

		G4double wSizeX = 5 * cm;
		G4double wSizeY = 5 * cm;
		G4double wSizeZ = 5 * cm;
		G4Material* wMaterial = nist->FindOrBuildMaterial("G4_Galactic");

		G4Element* C = nist->FindOrBuildElement("C");
		G4Element* F = nist->FindOrBuildElement("F");
		G4Element* O = nist->FindOrBuildElement("O");
		G4Element* N = nist->FindOrBuildElement("N");
		G4Element* H = nist->FindOrBuildElement("H");
		G4Element* Si = nist->FindOrBuildElement("Si");
		G4Element* B = nist->FindOrBuildElement("B");

		G4Material* neoprene = nist->FindOrBuildMaterial("G4_RUBBER_NEOPRENE");
		G4Material* nylon = nist->FindOrBuildMaterial("G4_NYLON-6/6");

		// World
		auto wSolid = new G4Box("World", 0.5 * wSizeX, wSizeY * 0.5, wSizeZ * 0.5);
		auto wLogic = new G4LogicalVolume(wSolid, wMaterial, "World");
		auto wPhysics = new G4PVPlacement(nullptr, G4ThreeVector(), wLogic, "World", nullptr, false, 0, true);

		// Envelope
		auto eSolid = new G4Box("Envelope", 0.25 * cm, 0.25 * cm, 0.25 * cm);
		auto eLogic = new G4LogicalVolume(eSolid, wMaterial, "Envelope");
		new G4PVPlacement(nullptr, G4ThreeVector(), eLogic, "Envelope", wLogic, false, 0, true);

		G4double gap = 0.01 * cm;

		// Change this value between tests
		G4double layers34thickness = 0.05 * cm; // 0.086 * cm

		G4double totalThickness = 0.056 * cm + 0.042 * cm + 2 * layers34thickness + 0.001 * cm + 0.015 * cm + 0.032 * cm + 5 * gap;
		G4double zCenter = -totalThickness / 2 + gap;
		G4double xySize = 1 * cm;

		// Layer 1
		G4Material* orthofabric = new G4Material("orthofabric", 0.875 * (g / cm3), 5);
		orthofabric->AddElement(C, 0.4699);
		orthofabric->AddElement(F, 0.3799);
		orthofabric->AddElement(O, 0.0705);
		orthofabric->AddElement(N, 0.0582);
		orthofabric->AddElement(H, 0.0215);

		G4ThreeVector l1Position = G4ThreeVector(0, 0, zCenter + 0.056 * cm / 2);
		
		auto l1Solid = new G4Box("Layer1", 1 * cm, 1 * cm, 0.056 * cm / 2);
		auto l1Logic = new G4LogicalVolume(l1Solid, orthofabric, "Layer1");
		new G4PVPlacement(nullptr, l1Position, l1Logic, "Layer1", eLogic, false, 0, true);

		zCenter += 0.056 * cm + gap;

		// Layer 2
		G4Material* mylar = nist->FindOrBuildMaterial("G4_MYLAR");
		G4ThreeVector l2Position = G4ThreeVector(0, 0, zCenter + 0.042 * cm / 2);

		auto l2Solid = new G4Box("Layer2", xySize, xySize, 0.042 * cm / 2);
		auto l2Logic = new G4LogicalVolume(l2Solid, mylar, "Layer2");
		new G4PVPlacement(nullptr, l2Position, l2Logic, "Layer2", eLogic, false, 0, true);

		zCenter += 0.042 * cm + gap;

		// Layer 3 (1st test)
		G4Material* neoprene_coated_nylon = new G4Material("neoprene_coated_nylon", 0.651 * (g / cm3), 2);

		neoprene_coated_nylon->AddMaterial(neoprene, 0.6);
		neoprene_coated_nylon->AddMaterial(nylon, 0.4);

		/*G4ThreeVector l3Position = G4ThreeVector(0, 0, zCenter + 0.086 * cm / 2);

		auto l3Solid = new G4Box("Layer3", xySize, xySize, 0.086 * cm / 2);
		auto l3Logic = new G4LogicalVolume(l3Solid, neoprene_coated_nylon, "Layer3");
		new G4PVPlacement(nullptr, l3Position, l3Logic, "Layer3", eLogic, false, 0, true);

		zCenter += 0.086 * cm + gap;

		// Layer 4 (1st test)
		G4ThreeVector l4Position = G4ThreeVector(0, 0, zCenter + 0.086 * cm / 2);

		auto l4Solid = new G4Box("Layer4", xySize, xySize, 0.086 * cm / 2);
		auto l4Logic = new G4LogicalVolume(l4Solid, neoprene_coated_nylon, "Layer4");
		new G4PVPlacement(nullptr, l4Position, l4Logic, "Layer4", eLogic, false, 0, true);

		zCenter += 0.086 * cm + gap;*/

		// Layer 3 (2nd test)
		G4Material* stf_armor = new G4Material("stf_armor", 0.72 * (g / cm3), 7);

		stf_armor->AddElement(C, 0.5019);
		stf_armor->AddElement(H, 0.0339);
		stf_armor->AddElement(N, 0.0930);
		stf_armor->AddElement(O, 0.2160);
		stf_armor->AddElement(Si, 0.1042);
		stf_armor->AddElement(B, 0.0064);
		stf_armor->AddElement(F, 0.0446);

		G4ThreeVector l3Position = G4ThreeVector(0, 0, zCenter + 0.05 * cm / 2);

		auto l3Solid = new G4Box("Layer3", xySize, xySize, 0.05 * cm / 2);
		auto l3Logic = new G4LogicalVolume(l3Solid, neoprene_coated_nylon, "Layer3");
		new G4PVPlacement(nullptr, l3Position, l3Logic, "Layer3", eLogic, false, 0, true);

		zCenter += 0.05 * cm + gap;

		// Layer 4 (2nd test)
		G4ThreeVector l4Position = G4ThreeVector(0, 0, zCenter + 0.05 * cm / 2);

		auto l4Solid = new G4Box("Layer4", xySize, xySize, 0.05 * cm / 2);
		auto l4Logic = new G4LogicalVolume(l4Solid, neoprene_coated_nylon, "Layer4");
		new G4PVPlacement(nullptr, l4Position, l4Logic, "Layer4", eLogic, false, 0, true);
		
		zCenter += 0.05 * cm + gap;

		// Layer 5
		G4Material* dacron = new G4Material("dacron", 1.4 * (g / cm3), 3);
		dacron->AddElement(C, 0.625);
		dacron->AddElement(H, 0.042);
		dacron->AddElement(O, 0.333);

		G4ThreeVector l5Position = G4ThreeVector(0, 0, zCenter + 0.015 * cm);

		auto l5Solid = new G4Box("Layer5", xySize, xySize, 0.015 * cm / 2);
		auto l5Logic = new G4LogicalVolume(l5Solid, dacron, "Layer5");
		new G4PVPlacement(nullptr, l5Position, l5Logic, "Layer5", eLogic, false, 0, true);

		zCenter += 0.015 * cm + gap;

		// Layer 6
		G4Material* polyurethane = new G4Material("polyurethane", 1.2 * (g / cm3), 4);
		polyurethane->AddElement(C, 0.625);
		polyurethane->AddElement(H, 0.070);
		polyurethane->AddElement(N, 0.060);
		polyurethane->AddElement(O, 0.245);

		G4Material* urethane_coated_nylon = new G4Material("urethane_coated_nylon", 0.84 * (g / cm3), 2);
		urethane_coated_nylon->AddMaterial(neoprene, 0.6);
		urethane_coated_nylon->AddMaterial(nylon, 0.4);

		G4ThreeVector l6Position = G4ThreeVector(0, 0, zCenter + 0.032 * cm / 2);

		auto l6Solid = new G4Box("Layer6", xySize, xySize, 0.032 * cm / 2);
		auto l6Logic = new G4LogicalVolume(l6Solid, urethane_coated_nylon, "Layer6");
		new G4PVPlacement(nullptr, l6Position, l6Logic, "Layer6", eLogic, false, 0, true);

		zCenter += 0.032 * cm + gap;

		// Detector
		G4ThreeVector dPosition = G4ThreeVector(0, 0, zCenter + 0.01 * mm / 2);
		G4Material* skin = nist->FindOrBuildMaterial("G4_SKIN_ICRP");

		auto dSolid = new G4Box("Detector", 1 * cm, 1 * cm, 0.01 * mm);
		auto dLogic = new G4LogicalVolume(dSolid, skin, "Detector");
		new G4PVPlacement(nullptr, dPosition, dLogic, "Detector", eLogic, false, 0, true);

		fScoringVolume = dLogic;
		return wPhysics;
	}
}