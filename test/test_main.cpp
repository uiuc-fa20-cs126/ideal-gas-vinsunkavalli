#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "../../../include/glm/glm.hpp"

#include <particle.h>
#include <simulation.h>

TEST_CASE("Particle") {
  SECTION("Creating a particle") {
    Particle test_particle = Particle(1.0, 0.0, 0.0, 0.0, 0.0);
    REQUIRE(test_particle.getPosition() == glm::vec2(0, 0));
  }

  SECTION("Updating particle position") {
    Particle test_particle = Particle(1.0, 0.0, 0.0, 0.0, 0.0);
    test_particle.updatePosition();
    REQUIRE(test_particle.getPosition() == glm::vec2(0,0));
  }

  SECTION("Manually setting particle velocity") {
    Particle test_particle = Particle(1.0, 0.0, 0.0, 0.0, 0.0);
    test_particle.setVelocity(0.1, 0.1);
    REQUIRE(test_particle.getVelocity() == glm::vec2(0.1, 0.1));
  }

}

TEST_CASE("Simulation") {
  //TODO Test creating simulation from vector (including invalid particles), running invalid wall/particle collision, and handling more than two particles colliding at the same time

  SECTION("Create a simulation") {
    Simulation simulation (1, 1, 1);
    REQUIRE(simulation.getParticles().size() == 1);
  }

  SECTION("Update a simulation") {
    std::vector<Particle> particles (1, Particle(1, 0, 0, 0.1, 0.1));
    Simulation simulation (particles, 1, 1);
    simulation.update();
    //REQUIRE(simulation.getParticles()[0].getPosition() == glm::vec2(0, 0));
  }

  SECTION("Check for a collision") {
    std::vector<Particle> particles (1, Particle(1, 0, 0, -0.1, -0.1));
    Simulation simulation (particles, 1, 1);
    //REQUIRE(simulation.checkCollision());
  }

  SECTION("Wall collision") {
    std::vector<Particle> particles (1, Particle(1, 0, 0, -0.1, -0.1));
    Simulation simulation (particles, 1, 1);
    simulation.wallCollision(particles[0]);
    REQUIRE(simulation.getParticles()[0].getVelocity() == glm::vec2(-0.1, -0.1));
  }

  SECTION("Particle collision") {
    std::vector<Particle> particles;
    particles.push_back(Particle(1, 0.1, 0.1, 0.1, 0.1));
    particles.push_back(Particle(1, 0.2, 0.2, -0.1, -0.1));

    Simulation simulation (particles, 1, 1);
    simulation.particleCollision(particles[0], particles[1]);
    REQUIRE(simulation.getParticles()[0].getVelocity() == glm::vec2(0.1, 0.1));
    REQUIRE(simulation.getParticles()[1].getVelocity() == glm::vec2(-0.1, -0.1));
  }
}