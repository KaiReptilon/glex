#include "CubeAsset.h"

CubeAsset::CubeAsset(GLfloat x, GLfloat y, GLfloat z) {
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
  GLfloat g_color_buffer [] = {
    
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f,
     0.824f, 0.412f, 0.118f
  }; 
    color_buffer_length = sizeof(g_color_buffer);


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
  ///

  /// create buffer
  glGenBuffers(1, &vertex_buffer_token);

  /// immediately bind the buffer and transfer the data
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, vertex_buffer_length, vertex_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &color_buffer_token);
  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
  glBufferData(GL_ARRAY_BUFFER, color_buffer_length, g_color_buffer, GL_STATIC_DRAW);

  glGenBuffers(1, &element_buffer_token);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, element_buffer_length, element_buffer, GL_STATIC_DRAW);
}

CubeAsset::~CubeAsset() {
}

#ifdef DEBUG
#define checkGLError() checkError(__FILE__, __LINE__)
#else
/// define symbol to be nothing
#define checkGLError()
#endif

void checkError(std::string file, int line) {
  GLenum gl_error = glGetError();
  if(GL_NO_ERROR != gl_error) {
    std::cerr << "GL error in " << file << " at line " << line << " error: " << gl_error << std::endl;
    exit(-1);
  }
}

void CubeAsset::Draw(GLuint program_token) {
  if(!glIsProgram(program_token)) {
    std::cerr << "Drawing Cube with invalid program" << std::endl;
    return;
  }
  GLint validation_ok;
  glValidateProgram(program_token);
  glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);
  if(!validation_ok) {
    GLint maxLength = 0;
    glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

    ///The maxLength includes the NULL character
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

    std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
    for(auto c: errorLog) {
      std::cerr << c;
    }
    exit(-1);
  }

  GLuint position_attrib = glGetAttribLocation(program_token, "position");
  checkGLError();

  glUseProgram(program_token);
  checkGLError();

  /// use the previously transferred buffer as the vertex array.  This way
  /// we transfer the buffer once -- at construction -- not on every frame.
  glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
  glVertexAttribPointer(
                        0,              /* attribute */
                        3,                             /* size */
                        GL_FLOAT,                      /* type */
                        GL_FALSE,                      /* normalized? */
                        0,                             /* stride */
                        (void*)0                       /* array buffer offset */
                        );
  glEnableVertexAttribArray(position_attrib);

  checkGLError();

  glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
  glVertexAttribPointer(
    1,        /* attribute */
    3,        /* size */
    GL_FLOAT, /* type */
    GL_FALSE, /* normalised? */
    0,        /* stride */
    (void*)0  /* array buffer offset */
  );
  checkGLError();

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
  glDrawElements(
                 GL_TRIANGLES,
                 element_buffer_length,
                 GL_UNSIGNED_INT,
                 (GLvoid*) 0
                 );

  checkGLError();

  glDisableVertexAttribArray(position_attrib);
}
