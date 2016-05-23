#include "BoundingBox.h"

Bounding_Box::Bounding_Box(GLfloat x, GLfloat y, GLfloat z)
{
	position = glm::vec3(x, y, z);
}

void Bounding_Box::Translate(GLfloat x_velocity, GLfloat y_velocity, GLfloat z_velocity)
{
	position = position + glm::vec3(x_velocity, y_velocity, z_velocity);
}

void Bounding_Box::Rotate(GLfloat x_velocity, GLfloat y_velocity, GLfloat z_velocity)
{
	rotation = rotation + glm::vec3(x_velocity, y_velocity, z_velocity);
}

void Bounding_Box::Scale(GLfloat x_velocity, GLfloat y_velocity, GLfloat z_velocity)
{
    scale = scale + glm::vec3(x_velocity, y_velocity, z_velocity);
}
