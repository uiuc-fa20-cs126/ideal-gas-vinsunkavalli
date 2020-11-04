#include <simulation.h>

const double radius = 0.2;
const double velPosScale = 100;//velocity should be smaller than pos, so dividing by this

Simulation::Simulation(int num_particles, double maxX, double maxY) {
  for(size_t i = 0; i < (unsigned) num_particles; ++i) {
    particles.push_back(Particle(radius, (std::rand() % 10 / 10.0) * (maxX - radius) + radius, (std::rand() % 10 / 10.0) * (maxY - radius) + radius, ((std::rand() % 10 / 10.0) * maxX)/velPosScale, ((std::rand() % 10 / 10.0) * maxY)/velPosScale));
  }

  boundX = maxX;
  boundY = maxY;
}

Simulation::Simulation(const std::vector<Particle> &particle_list, double maxX, double maxY) {
  for(Particle particle:particle_list) {
    glm::vec2 pos = particle.getPosition();

    if(!checkBounds(particle, boundX, boundY)) {
      throw std::invalid_argument("invalid particle - position exceeds bounds");
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
    particles[i].updatePosition();
    particles[i] = handleCollision(particles[i]);
  }
}

Particle& Simulation::handleCollision(Particle& particle) {
  //check for wall collision - particle's updated velocity will hit wall

  if(checkBounds(particle, boundX, boundY) &&
  ((glm::dot((particle.getVelocity() - glm::vec2(0, 0)), (particle.getPosition() - glm::vec2(0, 0))) >= 0) ||
  ((glm::dot((particle.getVelocity() - glm::vec2(0, 0)), (particle.getPosition() - glm::vec2(boundX, boundY))) >= 0)))) {
    particle = wallCollision(particle);
  }

  //check for particle collision - particle is heading towards another particle
  for(size_t i = 0; i < particles.size(); ++i) {
    Particle other = particles[i];

    if(!checkEqual(particle, other) && (particleDistance(particle, other)) <= radius * 2 &&
    glm::dot((particle.getVelocity() - other.getVelocity()), (particle.getPosition() - other.getPosition())) < 0) {
      Particle temp_particle = particleCollision(particle, other);
      particles[i] = particleCollision(other, particle);
      particle = temp_particle;
    }
  }

  return particle;
}

Particle& Simulation::wallCollision(Particle &particle) {
  glm::vec2 pos = particle.getPosition();
  glm::vec2 vel = particle.getVelocity();

  double radius = particle.getRadius();

  if(glm::dot(vel, (pos - glm::vec2(0, 0))) < radius ||
  glm::dot(vel, (pos - glm::vec2(boundX, boundY))) < radius) {
    if(pos.x - radius < 0 || pos.x + radius > boundX) {
      particle.setVelocity(-1 * vel.x, vel.y);
    }else if(pos.y - radius < 0 || pos.y + radius > boundY) {
      particle.setVelocity(vel.x, -1 * vel.y);
    }
  }

  return particle;
}

Particle& Simulation::particleCollision(Particle &particle1, Particle &particle2) {
  glm::vec2 pos1 = particle1.getPosition();
  glm::vec2 pos2 = particle2.getPosition();

  glm::vec2 vel1 = particle1.getVelocity();
  glm::vec2 vel2 = particle2.getVelocity();

  glm::vec2 newVel1;

  double length = (particleDistance(particle1, particle2));
  double posCoeff = glm::dot((vel1-vel2), (pos1-pos2))/(length * length);

  newVel1 = vel1 - (glm::vec2(posCoeff, posCoeff) * (pos1 - pos2));

  particle1.setVelocity(newVel1.x, newVel1.y);

  return particle1;
}