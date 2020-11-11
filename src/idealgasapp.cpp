#include <idealgasapp.h>

IdealGasApp::IdealGasApp() {
  ci::app::setWindowSize(kWindowSize, kWindowSize);
}

void IdealGasApp::draw() {
  ci::gl::clear();

  std::vector<Particle> particles = particle_simulation_.getParticles();

  ci::gl::color(ci::Color("white"));
  //creating boundary for particles to interact within
  ci::gl::drawStrokedRect(ci::Rectf(0.0f, 0.0f, (float) kRectSize + 1, (float) kRectSize + 1));

  std::vector<Particle> smallParticles;
  std::vector<Particle> regularParticles;
  std::vector<Particle> bigParticles;

  //sorting particles by mass relative to average
  for(Particle particle:particles) {
    double mass = particle.getMass();

    if(mass < kAvgParticleMass) {
      smallParticles.push_back(particle);
    }else if(mass == kAvgParticleMass) {
      regularParticles.push_back(particle);
    }else if(mass > kAvgParticleMass) {
      bigParticles.push_back(particle);
    }
  }

  //drawing particles
  drawParticles(smallParticles, "red");
  drawParticles(regularParticles, "blue");
  drawParticles(bigParticles, "green");

  //drawing histograms
  drawHistogram(glm::vec2(kWindowSize - kHistogramSize, 0), smallParticles, "red", "small particles (mass < avg)");
  drawHistogram(glm::vec2(kWindowSize - kHistogramSize, kHistogramSize), regularParticles, "blue", "regular particles (mass = avg)");
  drawHistogram(glm::vec2(kWindowSize - kHistogramSize, 2 * kHistogramSize), bigParticles, "green", "big particles (mass > avg)");

}

void IdealGasApp::update() {
  particle_simulation_.update();
}

void IdealGasApp::drawParticles(std::vector<Particle>& particles, char *const color) {
  ci::gl::color(ci::Color(color));

  for(Particle particle:particles) {
    ci::gl::drawSolidCircle(particle.getPosition() * glm::vec2(kRectBoundProp, kRectBoundProp),
                            (float) (particle.getRadius() * kRectBoundProp));
  }
}

void IdealGasApp::drawHistogram(glm::vec2 position,
                                std::vector<Particle> &particles,
                                char *const color,
                                std::string title,
                                std::string x_axis,
                                std::string y_axis,
                                double histogram_size,
                                double num_bins,
                                double max) {
  ci::gl::color(ci::Color(color));

  ci::gl::drawStrokedRect(ci::Rectf(position.x, position.y, position.x + (float) histogram_size, position.y + (float) histogram_size));

  for(auto i = 0; i < num_bins; ++i){
    int height = 0;

    for(Particle particle:particles) {
      double speed = glm::length(particle.getVelocity());

      if((speed < (max/num_bins) * (i + 1)) && (speed >= (max/num_bins) * (i))) {
        height++;
      }
    }

    ci::gl::drawSolidRect(ci::Rectf((float) (position.x + (i * histogram_size/num_bins)),
                                    (float) (position.y + histogram_size),
                                    (float) (position.x + ((i + 1) * histogram_size/num_bins)),
                                    (float) (position.y + histogram_size - (histogram_size * height)/particles.size())));
  }

  ci::gl::drawString(title, position);

  ci::gl::drawString(x_axis, glm::vec2(position.x + (8.0/10) * histogram_size, position.y + (9.0/10) * histogram_size));
  ci::gl::drawString(y_axis, glm::vec2(position.x, position.y + (1.0/10) * histogram_size));
}