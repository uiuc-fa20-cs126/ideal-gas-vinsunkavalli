#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include <idealgasapp.h>

void prepareSettings(ci::app::App::Settings* settings) {
  settings->setResizable(false);
  settings->setFrameRate( 30.0f );
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(IdealGasApp, ci::app::RendererGl, prepareSettings);