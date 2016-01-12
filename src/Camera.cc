#include "Camera.h"
#include <glm/ext.hpp>

// this class will inialise the veriables for the camera/player, it will also create a view matrix based on the position of the camera.

Camera::Camera() {

  cameraPosition = glm::vec3(-5.0f, 5.0f, 5.0f);
  Direction = glm::vec3(0,0,0);
  Right = glm::vec3(0,0,0);
  Up = glm::vec3(0,0,0);

  horizontalAngle = 0;
  verticalAngle = 0;

  DeltaTimeX = 1;
  DeltaTimeY = 1;
  
  CameraSpeed = 0.5;

};

//Updates camera depending on the user input, will change the view matrix.

  glm::mat4 UpdateCameraPosition( Input input_Direction, int MouseX, int MouseY);

  DeltaTimeX = -MouseX;
  DeltaTimeY = -MouseY;

  horizontalAngle += 0.01 * DeltaTimeX;

//the following if statement will give the player x axis restriction

  if((verticalAngle + (0.01 * DeltaTimeY)) < 1 && (verticalAngle + (0.01 * DeltaTimeY)) > -1) {
    verticalAngle += 0.01 * DeltaTimeY;
  }

// calculate of directions of view

  Direction = glm::vec3(cos(verticalAngle) * sin(horizontalAngle),sin(verticalAngle),cos(verticalAngle) * cos(horizontalAngle));
  Right = glm::vec3(sin(horizontalAngle - 3.14/2.0f),0,cos(horizontalAngle - 3.14/2.0f));
  Up = glm::cross(Right, Direction);

//update current position of the camera/player depending on the users input
  
    if( input_Direction == UP ) {
        cameraPosition += glm::vec3(cos(verticalAngle) * sin(horizontalAngle),0,cos(verticalAngle) * cos(horizontalAngle))* CameraSpeed;
    } else if( input_Direction == DOWN ) {
        cameraPosition -= glm::vec3(cos(verticalAngle) * sin(horizontalAngle),0,cos(verticalAngle) * cos(horizontalAngle))* CameraSpeed;
    } else if( input_Direction == LEFT) {
        cameraPosition -= Right * CameraSpeed;
    } else if( input_Direction == RIGHT) {
        cameraPosition += Right * CameraSpeed;
  }

//return of view matrix

 return glm::lookAt(cameraPosition, cameraPosition + Direction,Up);
}
