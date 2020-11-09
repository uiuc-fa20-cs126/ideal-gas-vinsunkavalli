#include <particle.h>

Particle::Particle(double particle_radius, double posX, double posY, double velX, double velY) {
  radius = particle_radius;

  position = glm::vec2(posX, posY);
  velocity = glm::vec2(velX, velY);
}

glm::vec2 Particle::getPosition() {
  return position;
}

glm::vec2 Particle::getVelocity(){
  return velocity;
}

double Particle::getRadius() {
  return radius;
}

void Particle::setVelocity(double velX, double velY) {
  velocity = glm::vec2(velX, velY);
}

void Particle::setPosition(glm::vec2 newPos) {
  position = newPos;
}

void Particle::updatePosition() {
  position += velocity;
}