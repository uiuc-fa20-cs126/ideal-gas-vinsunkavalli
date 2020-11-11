#include <ideal_gas_app.h>

IdealGasApp::IdealGasApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void IdealGasApp::draw() {
  ci::gl::clear();

  std::vector<Particle> particles = particle_simulation_.getParticles();

  ci::gl::color(ci::Color("white"));

  ci::gl::drawStrokedRect(ci::Rectf(0.0f, 0.0f, (float) kRectSize + 1, (float) kRectSize + 1));

  //TODO create better way to color particles if possible

  for(Particle particle:particles) {
    double mass = particle.getMass();

    if(mass < 1) {
      ci::gl::color(ci::Color("red"));
    }else if(mass == 1) {
      ci::gl::color(ci::Color("blue"));
    } else if(mass > 1) {
      ci::gl::color(ci::Color("green"));
    }

    ci::gl::drawSolidCircle(particle.getPosition() * glm::vec2(kRectBoundProp, kRectBoundProp),
                            (float) (particle.getRadius() * kRectBoundProp));
  }

  //draw histogram
  double num_bins = 100;
  double histogram_size = 250;

  double min = 0;
  double max = 1;

  std::vector<Particle> smallParticles;
  std::vector<Particle> regularParticles;
  std::vector<Particle> bigParticles;

  for(Particle particle:particles) {
    double mass = particle.getMass();

    if(mass < 1) {
      smallParticles.push_back(particle);
    }else if(mass == 1) {
      regularParticles.push_back(particle);
    }else if(mass > 1) {
      bigParticles.push_back(particle);
    }
  }

  ci::gl::color(ci::Color("red"));

  ci::gl::drawString("small particles (mass < 1)", glm::vec2(kWindowSize - histogram_size, 0));

  ci::gl::drawStrokedRect(ci::Rectf((float) (kWindowSize - histogram_size), 0.0f, (float) kWindowSize, (float) histogram_size));

  for(auto i = 0; i < num_bins; ++i){
    int height = 0;

    for(Particle particle:smallParticles) {
      double length = glm::length(particle.getVelocity());
      if((length < (max/num_bins) * (i + 1)) && (length >= (max/num_bins) * (i))) {
        height++;
      }
    }
    ci::gl::drawSolidRect(ci::Rectf((float) ((kWindowSize - histogram_size) + (i * histogram_size/num_bins)),
                                    (float) histogram_size,
                                    (float) ((kWindowSize - histogram_size) + ((i + 1) * histogram_size/num_bins)),
                                    (float) (histogram_size - (histogram_size * height)/smallParticles.size())));
  }

}

void IdealGasApp::update() {
  particle_simulation_.update();
}

