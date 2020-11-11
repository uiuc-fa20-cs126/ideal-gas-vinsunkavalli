#ifndef IDEAL_GAS_INCLUDE_IDEAL_GAS_APP_H_
#define IDEAL_GAS_INCLUDE_IDEAL_GAS_APP_H_

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <particle.h>
#include <simulation.h>

const int kWindowSize = 750;

const int kRectSize = 500;

const int kNumParticles = 9;
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


#endif //IDEAL_GAS_INCLUDE_IDEAL_GAS_APP_H_