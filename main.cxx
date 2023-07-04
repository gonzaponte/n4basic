#include <iostream>
#include "nain4.hh"
#include <G4SystemOfUnits.hh>
#include <G4Box.hh>
#include <G4LogicalVolume.hh>
#include <G4NistManager.hh>

int main() {
  std::cout << "I'm a basic nain 4 example" << std::endl;

  auto water = nain4::material("G4_WATER");
  auto lx = 1 * m;
  auto ly = 2 * m;
  auto lz = 3 * m;
  
  auto g4mat = G4NistManager::Instance()->FindOrBuildMaterial("G4_WATER");
  auto g4box = new G4Box("g4box", lx, ly, lz);
  auto g4vol = new G4LogicalVolume(g4box, g4mat, "g4box");

  std::cout << "A g4volume done the giant way: " << g4vol << std::endl;

  auto box = nain4::volume<G4Box>("test_box", water, lx, ly, lz);

  nain4::place(box).at(lx, 0., 0.).now();

  std::cout << "A g4volume done the dwarf way: " << box << std::endl;


  return 0;
}
