#ifndef IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_
#define IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_

#include <glm/glm.hpp>

class Particle {
 private:
  glm::vec2 position;
  glm::vec2 velocity;

  double radius;
 public:
  Particle(double radius, double posX, double posY, double velX, double velY);

  updatePosition();//meant to be run after every unit of time (i.e. after every 1 frame)

  getPosition();
  getVelocity();

  setVelocity(double velX, double velY);//used for collisions - handled in simulation
};

#endif //IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_
