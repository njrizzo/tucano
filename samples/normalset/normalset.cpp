#include "normalset.h"
#include <tucano.hpp>
#include <camera.hpp>

using namespace Tucano;


Effects::NormalSet::NormalSet(){
    quantization_level=8;
    setColor2Normal(Eigen::Vector4f(0,0,0,0));

}

Effects::NormalSet::~NormalSet(){

}

void Effects::NormalSet::initialize(void){
    loadShader(shader, "normalset");
    setColor2Normal(Eigen::Vector4f(0,1,0,0));
    eyesnormal = false;
    lightnormal = false;
    cossenoenable =false;
    gooshenable = false;
    hatchedenable = false;
}

void Effects::NormalSet::setColor2Normal(Eigen::Vector4f rgb){
    normalcolor = rgb;
}

Eigen::Vector4f Effects::NormalSet::getColorNormal(void){
    return normalcolor;
}

void Effects::NormalSet::render (Tucano::Mesh& mesh, const Tucano::Camera& cameraTrackball, const Tucano::Camera& lightTrackball){
    Eigen::Vector4f viewport = cameraTrackball.getViewport();
     glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);

     shader.bind();

     shader.setUniform("projectionMatrix", cameraTrackball.getProjectionMatrix());
     shader.setUniform("modelMatrix", mesh.getModelMatrix());
     shader.setUniform("viewMatrix", cameraTrackball.getViewMatrix());
     shader.setUniform("lightViewMatrix", lightTrackball.getViewMatrix());
     shader.setUniform("has_color", mesh.hasAttribute("in_Color"));
     shader.setUniform("normalcolor", getColorNormal());
     shader.setUniform("quantizationLevel",quantization_level);
     shader.setUniform("eyesnormal",eyesnormal);
     shader.setUniform("lightnormal",lightnormal);
     shader.setUniform("cossenoenable",cossenoenable);
     shader.setUniform("gooshenable",gooshenable);
     shader.setUniform("hatchedenable",hatchedenable);

     mesh.setAttributeLocation(shader);
     mesh.render();

     shader.unbind();

}

void Effects::NormalSet::setEyesNormal(bool checked){
    eyesnormal = checked;
}

void Effects::NormalSet::setLightNormal(bool checked){
    lightnormal = checked;
}

void Effects::NormalSet::setCossenoEnable(bool checked){
    cossenoenable = checked;
}

void Effects::NormalSet::setGooshEffect(bool checked){
    gooshenable = checked;
}

void Effects::NormalSet::setHatchedEffect(bool checked){
    hatchedenable = checked;
}
