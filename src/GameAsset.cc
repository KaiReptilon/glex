#include "GameAsset.h"

GameAsset::GameAsset(GLfloat x, GLfloat y, GLfloat z)
{
    box = std::make_shared<Bounding_Box>(x, y, z);
}

void GameAsset::Draw(GLuint program_token)
{
	if(!glIsProgram(program_token)) {
		std::cerr << "Drawing asset with invalid program" << std::endl;
		return;
	}

	GLint validation_ok;
	glValidateProgram(program_token);
	glGetProgramiv(program_token, GL_VALIDATE_STATUS, &validation_ok);

	if(!validation_ok) {
		GLint maxLength = 0;
		glGetProgramiv(program_token, GL_INFO_LOG_LENGTH, &maxLength);

		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(program_token, maxLength, &maxLength, &errorLog[0]);

		std::cerr << "Invalid program " << program_token << " with error code " << validation_ok << std::endl;
		for(auto c: errorLog) {
			std::cerr << c;
		}
		exit(-1);
	}

	GLuint position_attrib = glGetAttribLocation(program_token, "position");
	
    GLuint color_attrib = glGetAttribLocation(program_token, "color");
	

	glUseProgram(program_token);
	

	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_token);
	glVertexAttribPointer(
			position_attrib,               /* attribute */
			3,                             /* size */
			GL_FLOAT,                      /* type */
			GL_FALSE,                      /* normalized? */
			0,                             /* stride */
			(void*)0                       /* array buffer offset */
	);
	glEnableVertexAttribArray(position_attrib);
	

	glBindBuffer(GL_ARRAY_BUFFER, color_buffer_token);
	glVertexAttribPointer(
		color_attrib,				/* attribute */
		3,				/* size */
		GL_FLOAT,		/* type */
		GL_FALSE,		/* normalized? */
		0,				/* stride */
		(void*)0		/* array buffer offset */
	);
    glEnableVertexAttribArray(color_attrib);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer_token);
	glDrawElements(
			GL_TRIANGLES,
			element_buffer_length,
			GL_UNSIGNED_INT,
			(GLvoid*) 0
	);
	
	glDisableVertexAttribArray(position_attrib);
}
