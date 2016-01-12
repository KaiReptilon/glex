#include <glm/ext.hpp>
#include "common.h"

#ifndef SRC_CAMERA_H
#define SRC_CAMERA_H

class Camera{
  public:
    Camera();
    glm::mat4 UpdateCameraPosition( Input input_Direction, int MouseX, int MouseY);
  private:
    
    glm::vec3 cameraPosition;
    glm::vec3 Direction;
    glm::vec3 Right;
    glm::vec3 Up;

    float horizontalAngle;
    float verticalAngle;

    float DeltaTimeX;
    float DeltaTimeY;

    float CameraSpeed;

};

#endif

