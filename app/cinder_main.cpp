#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <simulation.h>

const int kWindowSize = 750;

const int kRectSize = 500;

const int kNumParticles = 99;
const double kMaxBound = 10;

const double kRectBoundProp = kRectSize/kMaxBound;

 class IdealGasApp: public ci::app::App{
 public:
    IdealGasApp();

    void draw() override;
    void update() override;
 private:
   Simulation particle_simulation_ = Simulation(kNumParticles, kMaxBound, kMaxBound);
};

IdealGasApp::IdealGasApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void IdealGasApp::draw() {
  ci::gl::clear();

  std::vector<Particle> particles = particle_simulation_.getParticles();

  ci::gl::color(ci::Color("white"));

  ci::gl::drawStrokedRect(ci::Rectf(0.0f, 0.0f, (float) kRectSize + 1, (float) kRectSize + 1));

  for(Particle particle:particles) {
    double mass = particle.getMass();
    if(mass == 0.5) {
      ci::gl::color(ci::Color("red"));
    }else if(mass == 1) {
      ci::gl::color(ci::Color("blue"));
    } else if(mass == 1.5) {
      ci::gl::color(ci::Color("green"));
    }

    ci::gl::drawSolidCircle(particle.getPosition() * glm::vec2(kRectBoundProp, kRectBoundProp),
                            (float) (particle.getRadius() * kRectBoundProp));
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