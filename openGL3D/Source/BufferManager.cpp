#include "BufferManager.h"

BufferManager::BufferManager(std::vector<GLfloat> Vertices, std::vector<GLuint> Indices) {
	this->vertexData = Vertices;
	this->indexData = Indices;
	glGenVertexArrays(1, &(this->VAO));
	glGenBuffers(1, &(this->EBO));

	glGenBuffers(1, &(this->VBO));

	glBindVertexArray(this->VAO);
	std::cout<<"BUFFER GEN AND VAO BIND ERRORS: "<<glGetError()<<std::endl;
	glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * Vertices.size(), Vertices.data(), GL_DYNAMIC_DRAW);
	std::cout<<"ARRAY BUFFER ERRORS: "<<glGetError()<<std::endl;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * Indices.size(), Indices.data(), GL_DYNAMIC_DRAW);
	std::cout<<"ELEMENT ARRAY BUFFER ERRORS: "<<glGetError()<<std::endl;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 3));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(sizeof(GLfloat) * 6));
	glEnableVertexAttribArray(2);

	glBindVertexArray(this->VAO);
}

void BufferManager::Bind() {
}
