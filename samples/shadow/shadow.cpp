#include "shadow.h"
#include <tucano.hpp>
#include <camera.hpp>

using namespace Tucano;


Effects::Shadow::Shadow(){
    quantization_level=8;
    setShadowColor(Eigen::Vector4f(0,0,0,0));

}

Effects::Shadow::~Shadow(){

}

void Effects::Shadow::initialize(void){
    loadShader(shader, "Shadow");
    setShadowColor(Eigen::Vector4f(0,1,0,0));
}

void Effects::Shadow::setShadowColor(Eigen::Vector4f rgb){
    shadowcolor = rgb;
}

Eigen::Vector4f Effects::Shadow::getShadowColor(void){
    return shadowcolor;
}

void Effects::Shadow::render (Tucano::Mesh& mesh, const Tucano::Camera& cameraTrackball, const Tucano::Camera& lightTrackball){
    Eigen::Vector4f viewport = cameraTrackball.getViewport();
     glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);

     shader.bind();

     shader.setUniform("projectionMatrix", cameraTrackball.getProjectionMatrix());
     shader.setUniform("modelMatrix", mesh.getModelMatrix());
     shader.setUniform("viewMatrix", cameraTrackball.getViewMatrix());
     shader.setUniform("lightViewMatrix", lightTrackball.getViewMatrix());
     shader.setUniform("has_color", mesh.hasAttribute("in_Color"));
     shader.setUniform("shadowcolor", getShadowColor());
     shader.setUniform("quantizationLevel",quantization_level);

     mesh.setAttributeLocation(shader);
     mesh.render();

     shader.unbind();

}
