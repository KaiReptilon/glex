#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/glew.h>
#include <GL/gl.h>

class Bounding_Box{
	public:
		Bounding_Box(GLfloat, GLfloat, GLfloat);

		void Translate(GLfloat, GLfloat, GLfloat);
		void Rotate(GLfloat, GLfloat, GLfloat);
		void Scale(GLfloat, GLfloat, GLfloat);

	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

};
