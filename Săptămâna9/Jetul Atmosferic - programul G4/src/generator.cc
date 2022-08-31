#include "generator.hh" //include file

 MyPrimaryGenerator::MyPrimaryGenerator() //create particle
 {
   fParticleGun = new G4ParticleGun(1); //create 1 primary vertex/event

   G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();

   //give a name of the part.
   G4String particleName = "proton";

   //find particle and copy inf about the particle
   G4ParticleDefinition *particle = particleTable->FindParticle("proton");


   //vectors def. (coordinates)
   G4ThreeVector pos(0.,0.,-20.*km); //position vector- in the center
   G4ThreeVector mom(0.,0.,1.); //z direction - momentum vector


   //special function for particle- set the properties.
   //...
   fParticleGun->SetParticlePosition(pos); //for position(in center)
   fParticleGun->SetParticleMomentumDirection(mom); //for z dir
   fParticleGun->SetParticleMomentum(100.*GeV); //for momentum... in natural units

   //...
   fParticleGun->SetParticleDefinition(particle);
 }


  MyPrimaryGenerator::~MyPrimaryGenerator() //delete particle
 {
   delete fParticleGun;
 }


 //basic function
 void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
 {
     G4ParticleDefinition* particle = fParticleGun->GetParticleDefinition();

     //tell G4 to generate a vertex
     fParticleGun->GeneratePrimaryVertex(anEvent); //generate primary vertex for event
 }
