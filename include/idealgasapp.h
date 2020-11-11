#ifndef IDEAL_GAS_INCLUDE_IDEALGASAPP_H_
#define IDEAL_GAS_INCLUDE_IDEALGASAPP_H_

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <particle.h>
#include <simulation.h>

const int kWindowSize = 750;
const int kHistogramSize = 250;

const int kRectSize = 500;

const int kNumParticles = 30;
const double kAvgParticleMass = 1.0;

const double kMaxBound = 10;

const double kRectBoundProp = kRectSize/kMaxBound;

class IdealGasApp: public ci::app::App{
 public:
  IdealGasApp();

  void draw() override;
  void update() override;
 private:
  Simulation particle_simulation_ = Simulation(kNumParticles, kMaxBound, kMaxBound);

  void drawParticles(std::vector<Particle> &particles, char *const color);
  void drawHistogram(glm::vec2 position,
                     std::vector<Particle> &particles,
                     char *const color,
                     double histogram_size,
                     double num_bins = 10,
                     double max = 0.3);
};


#endif //IDEAL_GAS_INCLUDE_IDEALGASAPP_H_