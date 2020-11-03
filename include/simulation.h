#ifndef IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
#define IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_

#include "../../../include/glm/glm.hpp"
#include <vector>

#include <particle.h>

class Simulation {
 private:
  std::vector<Particle> particles;

  double maxX;
  double maxY;
 public:
  Simulation(int num_particles, double maxX, double maxY);//this will generate random particles
  Simulation(const std::vector<Particle>& particle_list, double maxX, double maxY);//this will use the given list of particles

  void update();//updates every particles' position
  bool checkCollision();//checks for collisions with both particles and wall

  void wallCollision(Particle& particle);
  void particleCollision(Particle& particle1, Particle& particle2);

  std::vector<Particle>& getParticles();
};

#endif //IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
