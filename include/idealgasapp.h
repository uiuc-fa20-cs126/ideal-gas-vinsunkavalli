#ifndef IDEAL_GAS_INCLUDE_IDEALGASAPP_H_
#define IDEAL_GAS_INCLUDE_IDEALGASAPP_H_

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <particle.h>
#include <simulation.h>

const int kWindowSize = 750;

const int kHistogramSize = 250;
const double kNumBins = 10;
const double kMax = 0.3;

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

  //draws the individual components represented in the window through the main draw method
  void drawParticles(std::vector<Particle> &particles, char *const color);
  void drawHistogram(glm::vec2 position,
                     std::vector<Particle> &particles,
                     char *const color,
                     std::string title,
                     std::string x_axis = "speed",
                     std::string y_axis = "# particles",
                     double histogram_size = kHistogramSize,
                     double num_bins = kNumBins,
                     double max = kMax);
};


#endif //IDEAL_GAS_INCLUDE_IDEALGASAPP_H_