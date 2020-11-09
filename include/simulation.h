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

  void update();//updates every particles' position
  Particle & handleCollision(Particle &particle);//checks for collisions with both particles and wall then changes velocity accordingly

  Particle & wallCollision(Particle& particle);
  glm::vec2 & particleCollision(Particle& particle1, Particle& particle2);

  std::vector<Particle>& getParticles();
};

bool checkBounds(Particle& particle, double maxX, double maxY);
double particleDistance(Particle& particle1, Particle& particle2);
bool checkEqual(Particle& particle1, Particle& particle2);
bool moveTowards(Particle& particle1, Particle& particle2);
glm::vec2 posCheck(Particle& particle, double maxX, double maxY);

#endif //IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
