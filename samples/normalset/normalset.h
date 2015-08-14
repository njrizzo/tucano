#ifndef NORMALSET_H
#define NORMALSET_H

#include <tucano.hpp>
#include <camera.hpp>

using namespace Tucano;

namespace Effects
{

class NormalSet : public Effect
{
private:
    Shader  shader;
    Eigen::Vector4f normalcolor;
    float quantization_level;

public:
    NormalSet();
    virtual ~NormalSet();
    virtual void initialize(void);
    void setColor2Normal(Eigen::Vector4f rgb);
    Eigen::Vector4f getColorNormal(void);
    void render (Tucano::Mesh& mesh, const Tucano::Camera& cameraTrackball, const Tucano::Camera& lightTrackball);
};

};
#endif // NORMALSET_H
