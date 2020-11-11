#ifndef IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_
#define IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_

#include "../../../include/glm/glm.hpp"

class Particle {
 private:
  glm::vec2 position_;
  glm::vec2 velocity_;

  double radius_;
  double mass_;
 public:
  Particle(double radius, double mass, double posX, double posY, double velX, double velY);

  //changes the position of the particle based on velocity only
  void updatePosition();//meant to be run after every unit of time (i.e. after every 1 frame)

  //getters and setters
  glm::vec2& getPosition();
  glm::vec2& getVelocity();
  double getMass();
  double getRadius();

  void setVelocity(double velX, double velY);//used for collisions - handled in simulation
};

#endif //IDEAL_GAS_VINSUNKAVALLI__PARTICLE_H_
