#include "CubeAsset.h"

CubeAsset::CubeAsset(GLfloat x, GLfloat y, GLfloat z) : GameAsset(x, y, z) {
  ///model coordinates, origin at centre.
  ///Eight different sets of coordinates in order to determine where our cube will be on screen
  GLfloat vertex_buffer [] {
    -0.5f + x, -0.5f + y, -0.5f + z,
    -0.5f + x,  0.5f + y, -0.5f + z,
     0.5f + x, -0.5f + y, -0.5f + z,
     0.5f + x,  0.5f + y, -0.5f + z,
     0.5f + x, -0.5f + y,  0.5f + z,
     0.5f + x,  0.5f + y,  0.5f + z,
    -0.5f + x, -0.5f + y,  0.5f + z,
    -0.5f + x,  0.5f + y,  0.5f + z
  };
  GLfloat vertex_buffer_length =  sizeof(vertex_buffer);
  ///determines what colour each face of the cube will be
  GLfloat g_colour_buffer [] = {
    
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f
  }; 
    colour_buffer_length = sizeof(g_colour_buffer);


  ///the drawing for the triangles in order to make up each square face
  GLuint element_buffer []  {
    	0, 1, 2,
	1, 3, 2,
	2, 3, 4,
	3, 5, 4,
	0, 2, 4,
	6, 0, 4,
	6, 7, 0,
	1, 0, 7,
	1, 7, 3,
	7, 5, 3,
	5, 6, 4,
	5, 7, 6
  };
  element_buffer_length = sizeof(element_buffer);
  /// Transfer buffers to the GPU

  	glGenBuffers(1, &vertex_buffer_token);

	  /// immediately bind the buffer and transfer the data
	  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
	  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

	  glGenBuffers(1, &colour_buffer_token);
	  glBindBuffer(GL_ARRAY_BUFFER, colour_buffer_token);
	  glBufferData(GL_ARRAY_BUFFER, colour_buffer_length, g_colour_buffer, GL_STATIC_DRAW);

	  glGenBuffers(1, &element_buffer_token);
	  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
	  glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

CubeAsset::~CubeAsset() {
}