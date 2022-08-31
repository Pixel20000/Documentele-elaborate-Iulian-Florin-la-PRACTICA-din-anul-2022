#include "construction.hh"

 MyDetectorConstruction::MyDetectorConstruction()
 {
   DefineMaterials();
 }

 MyDetectorConstruction::~MyDetectorConstruction()
 {}

 void MyDetectorConstruction::DefineMaterials()
 {
     G4NistManager *nist = G4NistManager::Instance();

    //worldMaterial
    worldMat = nist->FindOrBuildMaterial("G4_AIR");

     //for world material and aerogel
    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();

    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4double density0 = 1.29*kg/m3;
    G4double aN = 14.01*g/mole;
    G4double aO = 16.00*g/mole;

    G4Element *elN = new G4Element("Nitrogen", "N", 7, aN);
    G4Element *elO = new G4Element("Oxygen", "O", 8, aO);

    G4double f = 3;
    G4double R = 8.3144626181532;
    G4double g0 = 9.81;
    G4double kappa = (f+2)/f;
    G4double T = 293.15;
    G4double M = (0.3*aN + 0.7*aO)/1000.;

    for(G4int i = 0; i < 10; i++)
    {
        std::stringstream stri;
        stri << i;
        G4double h = 40e3/10.*i;
        G4double density = density0*pow((1-(kappa-1)/kappa*M*g0*h/(R*T)),(1/(kappa-1)));
        Air[i] = new G4Material("G4_AIR_"+stri.str(), density, 2);
        Air[i]->AddElement(elN, 70*perCent);
        Air[i]->AddElement(elO, 30*perCent);
    }

 }

 //all geometry and material
 G4VPhysicalVolume *MyDetectorConstruction::Construct()
 {


    //indici de refractie(CLIP6) - for Cher. radiation angle

    G4double xWorld = 40.*km;
    G4double yWorld = 40.*km;
    G4double zWorld = 20.*km;


    //1)solid + 2)logical + 3)physical (volume)( x3 volumes) - box VOLUME World

    solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld);
    logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld"); //a class for logical volume
    physWorld = new G4PVPlacement(0, G4ThreeVector(0.,0.,0.), logicWorld, "physWorld", 0, false, 0, true); //motherVolume


    solidAir = new G4Box("solidAir", xWorld, yWorld, zWorld/10.);

    for(G4int i = 0; i < 10; i++)
    {
        logicAir[i] = new G4LogicalVolume(solidAir, Air[i], "logicAir");
        physAir[i] = new G4PVPlacement(0, G4ThreeVector(0, 0, zWorld/10.*2*i - zWorld + zWorld/10.), logicAir[i], "physAir", logicWorld, false, i, true);
    }


    return physWorld;
 }

 //clip7;

 void MyDetectorConstruction::ConstructSDandField()
 {    //createan object
      MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

      //logic det. part

     //if(logicDetector != NULL)
      //logicDetector->SetSensitiveDetector(sensDet);
 }
