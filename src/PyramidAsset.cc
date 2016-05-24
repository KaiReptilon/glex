#include "PyramidAsset.h"

PyramidAsset::PyramidAsset(GLfloat x, GLfloat y, GLfloat z): GameAsset(x, y,  z) {
  ///model coordinates, origin at centre.
  ///5 different sets of coordinates in order to determine where our pyramid will be on screen
  GLfloat vertex_buffer [] {
     x,  y,  0.5f + z,
     0.5f + x,  0.5f + y, -0.5f + z,
    -0.5f + x,  0.5f + y, -0.5f + z,
    -0.5f + x, -0.5f + y, -0.5f + z,
     0.5f + x, -0.5f + y, -0.5f + z
  };
  GLfloat vertex_buffer_length =  sizeof(vertex_buffer);

  GLfloat g_colour_buffer [] = {

        0.000f, 1.000f, 1.000f,
        0.000f, 1.000f, 1.000f,
        0.000f, 1.000f, 1.000f,
        0.000f, 1.000f, 1.000f,
        0.000f, 1.000f, 1.000f
    
  }; 
    colour_buffer_length = sizeof(g_colour_buffer);


  ///the drawing for the triangles in order to make up each face of the pyramid
  GLuint element_buffer []  {

        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 1,
        1, 2, 4,
        1, 3, 4
	
  };
  element_buffer_length = sizeof(element_buffer);
  //// Transfer buffers to the GPU
  ////

  //// create buffer
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

PyramidAsset::~PyramidAsset() {
}