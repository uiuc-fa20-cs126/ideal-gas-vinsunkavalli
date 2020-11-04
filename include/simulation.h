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

  bool checkBounds(Particle& particle, double maxX, double maxY) {
    glm::vec2 pos = particle.getPosition();

    return (pos.x >= maxX || pos.y >= maxY) || (pos.x <= 0 || pos.y <= 0);
  }

  double particleDistance(Particle& particle1, Particle& particle2) {
    return (particle1.getPosition() - particle2.getPosition()).length();
  }

 public:
  Simulation(int num_particles, double maxX, double maxY);//this will generate random particles
  Simulation(const std::vector<Particle>& particle_list, double maxX, double maxY);//this will use the given list of particles

  void update();//updates every particles' position
  void handleCollision(Particle &particle);//checks for collisions with both particles and wall then changes velocity accordingly

  void wallCollision(Particle& particle);
  void particleCollision(Particle& particle1, Particle& particle2);

  std::vector<Particle>& getParticles();
};

#endif //IDEAL_GAS_VINSUNKAVALLI_SRC_SIMULATION_H_
