#include <simulation.h>

const int radius = 1;
const double velPosScale = 100;//velocity should be smaller than pos, so dividing by this

Simulation::Simulation(int num_particles, double maxX, double maxY) {
  for(size_t i = 0; i < (unsigned) num_particles; ++i) {
    particles.push_back(Particle(1, (std::rand() % 10 / 10.0) * maxX, (std::rand() % 10 / 10.0) * maxY, ((std::rand() % 10 / 10.0) * maxX)/velPosScale, ((std::rand() % 10 / 10.0) * maxY)/velPosScale));
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
    //handleCollision(particle);
  }
}

void Simulation::handleCollision(Particle& particle) {
  //check for wall collision - particle's updated velocity will hit wall

  //TODO Check that particles are moving towards wall

  if(!checkBounds(particle, boundX, boundY)) {
    wallCollision(particle);
  }

  //check for particle collision - particle is heading towards another particle
  for(size_t i = 0; i < particles.size(); ++i) {
    Particle other = particles[i];

    //TODO Check that particles aren't same and that particles are moving towards one another

    if((particleDistance(particle, other)) <= 0) {
      particleCollision(particle, other);
    }
  }
}

void Simulation::wallCollision(Particle &particle) {
  glm::vec2 pos = particle.getPosition();
  glm::vec2 vel = particle.getVelocity();

  if(pos.x <= 0 || pos.x >= boundX) {
    particle.setVelocity(-1 * vel.x, 0);
  }else if(pos.x <= 0 || pos.x >= boundX) {
    particle.setVelocity(0, -1 * vel.y);
  }
}

void Simulation::particleCollision(Particle &particle1, Particle &particle2) {
  particle1.setVelocity(0.0, 0.0);
  particle2.setVelocity(0.0, 0.0);
}


/*
std::vector<int> particles_collided;

  for(size_t i = 0; i < particles.size() - 1; ++i) {
    Particle particle1 = particles[i];
    for(size_t j = i + 1; j < particles.size(); ++j) {
      Particle particle2 = particles[j];

      if((std::find(particles_collided.begin(), particles_collided.end(), i) != particles_collided.end()) &&
      (std::find(particles_collided.begin(), particles_collided.end(), j) != particles_collided.end()) &&
          ((particle1.getPosition() + particle1.getVelocity() - particle2.getPosition() - particle2.getVelocity()).length() <
          particle1.getRadius() + particle2.getRadius()) &&
          (glm::dot((particle1.getPosition() - particle1.getVelocity()), (particle2.getPosition() - particle2.getVelocity())) < 0)) {
        particleCollision(particle1, particle2);
        particles_collided.push_back(i);
        particles_collided.push_back(j);
      }
    }
  }

    for(size_t i = 0; i < particles.size(); ++i) {
    Particle particle = particles[i];
    glm::vec2 particle_path = (particle.getPosition() + particle.getVelocity());

    if((std::find(particles_collided.begin(), particles_collided.end(), i) == particles_collided.end()) &&
        ((particle_path.x + radius >= boundX || particle_path.y + radius >= boundY) || (particle_path.x - radius <= 0 || particle_path.y - radius <= 0))) {
      wallCollision(particle);
    }
  }
 */