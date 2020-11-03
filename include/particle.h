#ifndef IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_
#define IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_

#include "../../../include/glm/glm.hpp"

class Particle {
 private:
  glm::vec2 position;
  glm::vec2 velocity;

  double radius;
 public:
  Particle(double radius, double posX, double posY, double velX, double velY);

  void updatePosition();//meant to be run after every unit of time (i.e. after every 1 frame)

  glm::vec2 getPosition();
  glm::vec2 getVelocity();

  void setVelocity(double velX, double velY);//used for collisions - handled in simulation
  double getRadius();
};

#endif //IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_
