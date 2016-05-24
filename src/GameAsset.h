#ifndef GAMEASSET_H
#define GAMEASSET_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/glew.h>
#include <GL/gl.h>

#include <iostream>
#include <memory>
#include <vector>

#include "BoundingBox.h"

class GameAsset {
	public:
		GameAsset(GLfloat, GLfloat, GLfloat);
		void Draw(GLuint);
		
		void checkError(std::string file, int line);

	private:
        GLuint element_buffer_length, vertex_buffer_length, colour_buffer_length;
        GLuint element_buffer_token, vertex_buffer_token, colour_buffer_token;

        std::shared_ptr<Bounding_Box> box;

};

#endif