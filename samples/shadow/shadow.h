#ifndef SHADOW_H
#define SHADOW_H

#include <tucano.hpp>
#include <camera.hpp>

using namespace Tucano;

namespace Effects
{

class Shadow : public Effect
{
private:
    Shader  shader;
    Eigen::Vector4f shadowcolor;
    float quantization_level;

public:
    Shadow();
    virtual ~Shadow();
    virtual void initialize(void);
    void setShadowColor(Eigen::Vector4f rgb);
    Eigen::Vector4f getShadowColor(void);
    void render (Tucano::Mesh& mesh, const Tucano::Camera& cameraTrackball, const Tucano::Camera& lightTrackball);
};

};
#endif // SHADOW_H
