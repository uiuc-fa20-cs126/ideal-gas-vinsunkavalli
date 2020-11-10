#include <particle.h>

Particle::Particle(double radius, double mass, double posX, double posY, double velX, double velY) {
  radius_ = radius;
  mass_ = mass;

  position_ = glm::vec2(posX, posY);
  velocity_ = glm::vec2(velX, velY);
}

glm::vec2& Particle::getPosition() {
  return position_;
}

glm::vec2& Particle::getVelocity(){
  return velocity_;
}

double Particle::getRadius() {
  return radius_;
}

double Particle::getMass() {
  return mass_;
}

void Particle::setVelocity(double velX, double velY) {
  velocity_ = glm::vec2(velX, velY);
}

void Particle::updatePosition() {
  position_ += velocity_;
}