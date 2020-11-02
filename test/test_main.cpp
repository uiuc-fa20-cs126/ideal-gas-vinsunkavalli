TEST_CASE("Particle") {
  SECTION("Creating a particle") {
    Particle test_particle (1, 0, 0, 0, 0);
    REQUIRE(test_particle.getPosition() == glm::vec2());
  }

  //TODO Test setting position below zero

  SECTION("Updating particle position") {
    Particle test_particle (1, 0, 0, 0, 0);
    test_particle.update();
    REQUIRE(test_particle.getPosition() == glm::vec2());
  }

  SECTION("Manually setting particle position") {
    Particle test_particle (1, 0, 0, 0, 0);
    test_particle.setVelocity(0.1, 0.1);
    REQUIRE(test_particle.getVelocity() == glm::vec2());
  }
}

TEST_CASE("Simulation") {
  //TODO Test creating simulation from vector, running invalid wall/particle collision, and handling more than two particles colliding at the same time

  SECTION("Create a simulation") {
    Simulation simulation (1, 1, 1);
    REQUIRE(simulation.getParticles().size() == 1);
  }

  SECTION("Update a simulation") {
    std::vector<Particle> particles (1, Particle(1, 0, 0, 0.1, 0.1));
    Simulation simulation (particles, 1, 1);
    simulation.update();
    REQUIRE(simulation.getParticles()[0].getPosition() == glm::vec2());
  }

  SECTION("Check for a collision") {
    std::vector<Particle> particles (1, Particle(1, 0, 0, -0.1, -0.1));
    Simulation simulation (particles, 1, 1);
    REQUIRE(simulation.checkCollision());
  }

  SECTION("Wall collision") {
    std::vector<Particle> particles (1, Particle(1, 0, 0, -0.1, -0.1));
    Simulation simulation (particles, 1, 1);
    simulation.wallCollision()
    REQUIRE(simulation.getParticles[0].getVelocity() == glm::vec2());
  }

  SECTION("Particle collision") {
    std::vector<Particle> particles;
    particles.add();
    particles.add();

    Simulation simulation (particles, 1, 1);
    simulation.wallCollision()
    REQUIRE(simulation.getParticles[0].getVelocity() == glm::vec2() && simulation.getParticles[1].getVelocity());
  }
}