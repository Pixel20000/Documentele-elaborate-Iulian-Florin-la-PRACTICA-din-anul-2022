#include "construction.hh"


 MyDetectorConstruction::MyDetectorConstruction()
 {
 }


 MyDetectorConstruction::~MyDetectorConstruction()
 {}



 G4VPhysicalVolume *MyDetectorConstruction::Construct() 
 {   //notiuni de baza


    //...........................................................................................

     // Get nist material manager(pentru a imprumuta materiale)
     G4NistManager* nist = G4NistManager::Instance();


     //define the materials;


     //CUPRU;
    // G4Material* shape1_mat = nist->FindOrBuildMaterial("G4_Cu");

     //BOR;
     G4Material* shape2_mat = nist->FindOrBuildMaterial("G4_B"); //select a material
     G4Material* shape3_mat = nist->FindOrBuildMaterial("G4_B");

     //GERMANIU;
     G4Material* shape4_mat = nist->FindOrBuildMaterial("G4_Ge");
     G4Material* shape5_mat = nist->FindOrBuildMaterial("G4_Ge");

     //LITIU;
     G4Material* shape6_mat = nist->FindOrBuildMaterial("G4_Li");
     G4Material* shape7_mat = nist->FindOrBuildMaterial("G4_Li");

     //ALUMINIU;
     G4Material* shape8_mat = nist->FindOrBuildMaterial("G4_Al");
     G4Material* shape9_mat = nist->FindOrBuildMaterial("G4_Al");

     //Final;
     G4Material* shape10_mat = nist->FindOrBuildMaterial("G4_Al");

     //WorldMaterial
     G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR"); //world material
     //



    //...........................................................................................

     // Option to switch on/off checking of volumes overlaps
     G4bool checkOverlaps = true;



     // Envelope parameters(Anvelopa inglobeaza ansambulu detector)
     G4double env_sizeXY = 30*cm, env_sizeZ = 30*cm;
     G4Material* env_mat = nist->FindOrBuildMaterial("G4_AIR");

     G4double world_sizeXY = 40*cm;
     G4double world_sizeZ  = 40*cm;



     //1)solid + 2)logical + 3)physical (volume)( x3 volumes) - box VOLUME World

     //BOX World Volumes;
     G4Box* solidWorld =
       new G4Box("World",                       //its name
          0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ);     //its size

     G4LogicalVolume* logicWorld =
       new G4LogicalVolume(solidWorld,          //its solid
                           world_mat,           //its material
                           "World");            //its name

     G4VPhysicalVolume* physWorld =
       new G4PVPlacement(0,                     //no rotation
                         G4ThreeVector(),       //at (0,0,0)
                         logicWorld,            //its logical volume
                         "World",               //its name
                         0,                     //its mother  volume
                         false,                 //no boolean operation
                         0,                     //copy number
                         true);                 //overlaps checking



     // Envelope definition;

      G4Box* solidEnv =
       new G4Box("Envelope",                    //its name
           0.5*env_sizeXY, 0.5*env_sizeXY, 0.5*env_sizeZ); //its size

      logicEnv =
       new G4LogicalVolume(solidEnv,            //its solid
                           env_mat,             //its material
                           "Envelope");         //its name

    //  fScoringVolume = logicEnv;

       new G4PVPlacement(0,                       //no rotation
                        G4ThreeVector(),         //at (0,0,0)
                        logicEnv,                //its logical volume
                        "Envelope",              //its name
                        logicWorld,              //its mother  volume
                        false,                   //no boolean operation
                        0,                       //copy number
                        checkOverlaps);          //overlaps checking




     //--------------------------------------SECTION 1-------------------------------------

     //Materials-I;
     //Geometry-II;


      //.............................................Pinul din CUPRU....................................................;(OPTIONAL)
     //G4ThreeVector pos1 = G4ThreeVector(0, 0, 0);


     // Cilindrical section shape - CentralCopperContactPin

     //solidVOlumeSizes
     // G4Tubs *solidPin = new G4Tubs("solidPin", // name
                                  //    0.*mm, // inner radius (0)
                                   //   2.55*mm, // outer radius
                                   //   48.15*mm, // Z half! length
                                  //    0.*deg, // starting Phi (0)
                                    //  360.*deg); // segment angle (two_pi)

      //Logical VOlume material;
     // G4LogicalVolume* logicPin = new G4LogicalVolume(solidPin,    //its solid
                                                    //  shape1_mat,          //its material
                                                     // "logicPin"); //its name(logic)

      //vol. fizic
     //  new G4PVPlacement(0,
                  //       pos1,  //position vector
                      //   logicPin, 		      //its logical volume
                       //  "physPin",         	      //its name
                      //   logicEnv,              //its mother volume
                    //     false,                   //no boolean operation
                     //    0,                       //copy number
                        // checkOverlaps);          //verifica suprapunerile(de evitat)



   //......................................Section 2(BOR)................................................

     // Shape 2- Boron Contact layer

      G4ThreeVector pos2 = G4ThreeVector(0, 0, 0); //(x,y,z) - vectorul de poz. al centrului


      //solidVOlumeSizes
      G4Tubs *solidBor = new G4Tubs("solidBor", // name
                                     5.1*mm, // inner radius (0)
                                     5.1003*mm, // outer radius
                                     48.15*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicBor = new G4LogicalVolume(solidBor,    //its solid
                                                      shape2_mat,  //its material
                                                      "logicBor"); //its name(logic)

      //vol. fizic final
       new G4PVPlacement(0,
                         pos2,                         //position vector
                         logicBor, 		      //its logical volume
                         "physBor",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)




    //for Boron plate(top) - shape3

     G4ThreeVector pos3 = G4ThreeVector(0, 0, 48.15015); //(x,y,z)


     //solidVOlumeSizes
      G4Tubs *solidBorplate = new G4Tubs("solidBorplate", // name
                                     0.*mm, // inner radius (0)
                                     5.1003*mm, // outer radius
                                     0.0003*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicBorplate = new G4LogicalVolume(solidBorplate,    //its solid
                                                      shape3_mat,  //its material
                                                      "logicBorplate"); //its name(logic)

      //if(logicDetector != NULL)
        //logicDetector->SetSensitiveDetector(sensDet);
      //vol. fizic
       new G4PVPlacement(0,
                         pos3,  //position vector
                         logicBorplate, 		      //its logical volume
                         "physBorplate",               //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)


    //llllllllllllllllllllllllllllllllllllllllll_SECTION 3_(Ge)lllllllllllllllllllllllllllllllllllllllllll

      // Shape 4- Active Ge zone- layer

      G4ThreeVector pos4 = G4ThreeVector(0, 0, 0.00015); //(x,y,z)

      //solidVOlumeSizes
      G4Tubs *solidDetector = new G4Tubs("solidDetector", // name(detectorul principal)
                                     5.1004*mm, // inner radius (0)
                                     41.*mm, // outer radius
                                     48.15016*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)


      //Logical VOlume material;
     logicDetector = new G4LogicalVolume(solidDetector,    //its solid
                                                           shape4_mat,  //its material
                                                           "logicDetector"); //its name(logic)

      fScoringVolume = logicDetector; // ................................................................................................Vol tinta.


      //vol. fizic
       new G4PVPlacement(0,
                         pos4,  //position vector
                         logicDetector, 		      //its logical volume
                         "physDetector",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)


     // Shape 5- GePlateTop

      G4ThreeVector pos5 = G4ThreeVector(0, 0, 55.); //(x,y,z)

      G4Tubs *solidGeplate = new G4Tubs("solidGeplate", // name
                                     0.*mm, // inner radius (0)
                                     41.*mm, // outer radius
                                     6.2*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicGeplate = new G4LogicalVolume( solidGeplate,    //its solid
                                                           shape5_mat,  //its material
                                                           "logicGeplate"); //its name(logic)
      // fScoringVolume = logicGeplate;
      //vol. fizic
       new G4PVPlacement(0,
                         pos5,  //position vector
                         logicGeplate, 		      //its logical volume
                         "physGeplate",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)


     //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa_SECTION 4(Li)aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa


       // Shape 6- Li contact zone- layer

      G4ThreeVector pos6 = G4ThreeVector(0, 0, 0); //(x,y,z)


      //solidVOlumeSizes
      G4Tubs *solidLi = new G4Tubs("solidLi", // name
                                     41.1*mm, // inner radius (0)
                                     41.8*mm, // outer radius
                                     61.2*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicLi = new G4LogicalVolume(solidLi,      //its solid
                                                      shape6_mat,  //its material
                                                      "logicLi");  //its name(logic)

      //vol. fizic
       new G4PVPlacement(0,
                         pos6,  //position vector
                         logicLi, 		      //its logical volume
                         "physLi",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)


   //Li plate TOP - 2

     G4ThreeVector pos7 = G4ThreeVector(0, 0, 70); //(x,y,z)

    //solidVOlumeSizes
      G4Tubs *solidLiplate = new G4Tubs("solidLiplate", // name
                                     0*mm, // inner radius (0)
                                     41.8*mm, // outer radius
                                     0.35*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicLiplate = new G4LogicalVolume(solidLiplate,      //its solid
                                                          shape7_mat,  //its material
                                                          "logicLiplate");  //its name(logic)

      //vol. fizic
       new G4PVPlacement(0,
                         pos7,  //position vector
                         logicLiplate, 		      //its logical volume
                         "physLiplate",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)



     //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa_SECTION 5(Al)aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

        // Shape 8- Al foil contact zone- layer2

     G4ThreeVector pos8 = G4ThreeVector(0, 0, 0); //(x,y,z)


    //solidVOlumeSizes
      G4Tubs *solidAl = new G4Tubs("solidAl", // name
                                     41.9*mm, // inner radius (0)
                                     42.4*mm, // outer radius
                                     62.5*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicAl = new G4LogicalVolume(solidAl,      //its solid
                                                     shape8_mat,  //its material
                                                     "logicAl");  //its name(logic)

      //vol. fizic
       new G4PVPlacement(0,
                         pos8,  //position vector
                         logicAl, 		      //its logical volume
                         "physAl",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)


   //Al plate foil TOP - shape9

     G4ThreeVector pos9 = G4ThreeVector(0, 0, 63.); //(x,y,z)

    //solidVOlumeSizes
      G4Tubs *solidAlplate = new G4Tubs("solidAlplate", // name
                                     0*mm, // inner radius (0)
                                     41.9*mm, // outer radius
                                     0.5*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicAlplate = new G4LogicalVolume(solidAlplate,      //its solid
                                                          shape9_mat,  //its material
                                                          "logicAlplate");  //its name(logic)

      //vol. fizic
       new G4PVPlacement(0,
                         pos9,  //position vector
                         logicAlplate, 		      //its logical volume
                         "physAlplate",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)




   //kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk

   //shape10 - exterior Al_tick

      G4ThreeVector pos10 = G4ThreeVector(0, 0, 4.*mm); //(x,y,z)


    //solidVOlumeSizes
      G4Tubs *solidAltick = new G4Tubs("solidAltick", // name
                                     45.*mm, // inner radius (0)
                                     46.*mm, // outer radius
                                     67*mm, // Z half! length
                                     0.*deg, // starting Phi (0)
                                     360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicAltick = new G4LogicalVolume(solidAltick,      //its solid
                                                     shape10_mat,          //its material
                                                     "logicAltick");       //its name(logic)

      //vol. fizic
       new G4PVPlacement(0,
                         pos10,  //position vector
                         logicAltick, 		      //its logical volume
                         "physAltick",         	      //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)

      //shape11 - exterior Al_tick plate
      G4Material* shape11_mat = nist->FindOrBuildMaterial("G4_Al");
      G4ThreeVector pos11 = G4ThreeVector(0, 0, 71.7*mm); //(x,y,z)


      //solidVOlumeSizes
      G4Tubs *solidAltickplate = new G4Tubs("solidAltickplate", // name
                                             0, // inner radius (0)
                                             46.*mm, // outer radius
                                             0.5*mm, // Z half! length
                                             0.*deg, // starting Phi (0)
                                             360.*deg); // segment angle (twopi)

      //Logical VOlume material;
      G4LogicalVolume* logicAltickplate = new G4LogicalVolume(solidAltickplate,      //its solid
                                                              shape11_mat,          //its material
                                                             "logicAltickplate");       //its name(logic)

      //vol. fizic
       new G4PVPlacement(0,
                         pos11,  //position vector
                         logicAltickplate, 	      //its logical volume
                         "physAltickplate",            //its name
                         logicEnv,                     //its mother volume
                         false,                        //no boolean operation
                         0,                            //copy number
                         checkOverlaps);               //verifica suprapunerile(de evitat)




   //În cele din urmă, clasa de construcție a detectorului returnează un pointer către world volume al geometriei construite care conține geometria construită.

     return physWorld;
 }
 

 //for sensitive Detector;
 void MyDetectorConstruction::ConstructSDandField()
 {    //createan object
      MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");
      
      //logic det. part

     if(logicDetector != NULL)
       logicDetector->SetSensitiveDetector(sensDet);

     //  if(logicEnv != NULL)
       //  logicEnv->SetSensitiveDetector(sensDet);

 }
