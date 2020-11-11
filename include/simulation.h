#ifndef IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
#define IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_

#include "../../../include/glm/glm.hpp"
#include <vector>
#include <stdexcept>

#include <particle.h>

class Simulation {
 private:
  std::vector<Particle> particles;

  double boundX;
  double boundY;
 public:
  Simulation(int num_particles, double maxX, double maxY);//this will generate random particles
  Simulation(const std::vector<Particle>& particle_list, double maxX, double maxY);//this will use the given list of particles

  //updates every particles' position based on velocity, handling collisions as well
  void update();

  //checks for collisions with both particles and wall then changes velocity_ accordingly
  void handleCollision(Particle &particle);

  //does math for collisions against wall/particle and changes velocity accordingly
  void wallCollision(Particle& particle);
  void particleCollision(Particle& particle1, Particle& particle2);

  std::vector<Particle>& getParticles();
};

bool checkBounds(Particle& particle, double maxX, double maxY);
double particleDistance(Particle& particle1, Particle& particle2);
bool checkEqual(Particle& particle1, Particle& particle2);
bool moveTowards(Particle& particle1, Particle& particle2);

#endif //IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
