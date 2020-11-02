#ifndef IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
#define IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_

#include <glm/glm.hpp>
#include <vector>

class Simulation {
 private:
  std::vector<Particle> particles;

  double maxX;
  double maxY;
 public:
  Simulation(int num_particles, double maxX, double maxY);//this will generate random particles
  Simulation(const std::vector<Particle>& particle_list, double maxX, double maxY);//this will use the given list of particles

  update();//updates every particles' position
  checkCollision();//checks for collisions with both particles and wall

  wallCollision(Particle& particle);
  particleCollision(Particle& particle1, Particle& particle2);

  getParticles();
};

#endif //IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
