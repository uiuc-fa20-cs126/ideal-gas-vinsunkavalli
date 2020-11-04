#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <simulation.h>

const int windowSize = 750;

const int numParticles = 5;
const double maxBound = 10;

const double windowBoundProp = windowSize/maxBound;

 class IdealGasApp: public ci::app::App{
 public:
    IdealGasApp();

    void draw() override;
    void update() override;
 private:
   Simulation particle_simulation_ = Simulation(numParticles, maxBound, maxBound);
};

IdealGasApp::IdealGasApp() {
  ci::app::setWindowSize(windowSize, windowSize);
}

void IdealGasApp::draw() {
  ci::gl::clear();

  std::vector<Particle> particles = particle_simulation_.getParticles();

  ci::gl::color(ci::Color("white"));


  for(Particle particle:particles) {
    ci::gl::drawSolidCircle(particle.getPosition() * glm::vec2(windowBoundProp, windowBoundProp),
                            (float) (particle.getRadius() * windowBoundProp));
  }
}

void IdealGasApp::update() {
  particle_simulation_.update();
}


void prepareSettings(ci::app::App::Settings* settings) {
  settings->setResizable(false);
  settings->setFrameRate( 30.0f );
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(IdealGasApp, ci::app::RendererGl, prepareSettings);