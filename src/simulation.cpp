#include <simulation.h>

const double kRadius = 0.2;
static const double kMasses[] {0.5, 1, 1.5};
const double kVelPosScale = 100;//velocity_ should be smaller than pos, so dividing by this

Simulation::Simulation(int num_particles, double maxX, double maxY) {
  for(size_t i = 0; i < (unsigned) num_particles; ++i) {
    double mass = kMasses[i % std::size(kMasses)];
    particles.push_back(Particle(kRadius, mass,(std::rand() % 10 / 10.0) * (maxX - 2 * kRadius) + kRadius, (std::rand() % 10 / 10.0) * (maxY - 2 * kRadius) + kRadius, ((std::rand() % 10 / 10.0) * maxX)/kVelPosScale, ((std::rand() % 10 / 10.0) * maxY)/kVelPosScale));
  }

  boundX = maxX;
  boundY = maxY;
}

Simulation::Simulation(const std::vector<Particle> &particle_list, double maxX, double maxY) {
  for(Particle particle:particle_list) {
    glm::vec2 pos = particle.getPosition();

    if(!checkBounds(particle, boundX, boundY)) {
      throw std::invalid_argument("invalid particle - position_ exceeds bounds");
    }

    particles.push_back(particle);
  }

  boundX = maxX;
  boundY = maxY;
}

std::vector<Particle> & Simulation::getParticles() {
  return particles;
}

void Simulation::update() {
  for(size_t i = 0; i < particles.size(); ++i) {
    Particle particle = particles[i];

    handleCollision(particle);

    particles[i] = particle;
    particles[i].updatePosition();
    //particles[i].setPosition(posCheck(particles[i], boundX, boundY));
  }
}

void Simulation::handleCollision(Particle& particle) {
  //check for particle collision - particle is heading towards another particle
  for(size_t i = 0; i < particles.size(); ++i) {
    Particle other = particles[i];

    if(!checkEqual(particle, other) && (particleDistance(particle, other)) <= kRadius * 2 && moveTowards(particle, other)){
      particleCollision(particle, other);
      particles[i] = other;
    }
  }

  //check for wall collision - particle's updated velocity_ will hit wall
  if(checkBounds(particle, boundX, boundY)){
    wallCollision(particle);
  }
}

void Simulation::wallCollision(Particle &particle) {
  glm::vec2 pos = particle.getPosition();
  glm::vec2 vel = particle.getVelocity();

  double radius = particle.getRadius();

  if(pos.x - radius < 0 || pos.x + radius > boundX) {
      particle.setVelocity(-1 * vel.x, vel.y);
  }else if(pos.y - radius < 0 || pos.y + radius > boundY) {
      particle.setVelocity(vel.x, -1 * vel.y);
  }
}

void Simulation::particleCollision(Particle &particle1, Particle &particle2) {
  glm::vec2 pos1 = particle1.getPosition();
  glm::vec2 pos2 = particle2.getPosition();

  glm::vec2 vel1 = particle1.getVelocity();
  glm::vec2 vel2 = particle2.getVelocity();

  glm::vec2 newVel1;
  glm::vec2 newVel2;

  double length = (particleDistance(particle1, particle2));
  double posCoeff = glm::dot((vel1-vel2), (pos1-pos2))/(length * length);

  newVel1 = vel1 - (glm::vec2(posCoeff, posCoeff) * (pos1 - pos2));

  posCoeff = glm::dot((vel2-vel1), (pos2-pos1))/(length * length);

  newVel2 = vel2 - (glm::vec2(posCoeff, posCoeff) * (pos2 - pos1));

  particle1.setVelocity(newVel1.x, newVel1.y);
  particle2.setVelocity(newVel2.x, newVel2.y);
}

//HELPER functions

bool checkBounds(Particle& particle, double maxX, double maxY) {
  glm::vec2 pos = particle.getPosition();
  float radius = (float) particle.getRadius();

  return (pos.x + radius >= maxX || pos.y + radius >= maxY) || (pos.x - radius <= 0 || pos.y - radius <= 0);
}

double particleDistance(Particle& particle1, Particle& particle2) {
  double length =  abs(glm::length(particle1.getPosition() - particle2.getPosition()));

  return length;
}

bool checkEqual(Particle& particle1, Particle& particle2) {
  return (particle1.getPosition() == particle2.getPosition() &&
      particle1.getVelocity() == particle2.getVelocity() &&
      particle1.getRadius() == particle2.getRadius());
}

bool moveTowards(Particle& particle1, Particle& particle2) {
  return glm::dot((particle1.getVelocity() - particle2.getVelocity()),
                  (particle1.getPosition() - particle2.getPosition())) < 0;
}