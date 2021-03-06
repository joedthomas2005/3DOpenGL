#include "ShaderMan.h"

ShaderMan::ShaderMan(const char* vertShaderPath, const char* fragShaderPath, Window* window) {
	this->window = window;
	std::string vertShaderName = vertShaderPath;
	std::string fragShaderName = fragShaderPath;
	std::string completeVertPath = SHADERDIR + vertShaderName;
	std::string completeFragPath = SHADERDIR + fragShaderName;
	std::ifstream fileStream;
	std::string vertString;
	std::string fragString;
	fileStream.open(completeVertPath.c_str());
	vertString = std::string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	const char* vertShader = vertString.c_str();
	fileStream.close();
	fileStream.open(completeFragPath.c_str());
	fragString = std::string((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	const char* fragShader = fragString.c_str();
	fileStream.close();
	GLuint vShader, fShader;
	char infoLog[512];
	int success;

	vShader = glCreateShader(GL_VERTEX_SHADER);
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vShader, 1, &vertShader, NULL);
	glShaderSource(fShader, 1, &fragShader, NULL);
	glCompileShader(vShader);
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vShader, 512, NULL, infoLog);
		std::cout << "ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog << std::endl;
	}
	glCompileShader(fShader);
	glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fShader, 512, NULL, infoLog);
		std::cout << "ERROR SHADER FRAGMENT COMPILATION FAILED\n" << infoLog << std::endl;
	}

	this->ID = glCreateProgram();
	glAttachShader(ID, vShader);
	glAttachShader(ID, fShader);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR SHADING LINKING FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vShader);
	glDeleteShader(fShader);

	projection = glm::perspective(glm::radians(45.0f),  (float)window->getWidth()/(float)window->getHeight() , 0.1f, 100.0f);

}

void ShaderMan::use(glm::mat4 view) {
	glUseProgram(ID);
	glUniformMatrix4fv(glGetUniformLocation(ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
}

void ShaderMan::setVec3f(const char* name, GLfloat x, GLfloat y, GLfloat z) const {
	glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}

void ShaderMan::setMat4f(const char* name, glm::mat4 data) const{
	int err =glGetError();
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(data));
	err = glGetError();
	if(err){
		std::cout<<"SHADER MATRIX UNIFORM ERROR: " << err << std::endl;
	}
}

void ShaderMan::setBool(const char* name, bool data) const{
	glGetError();
	if(data){
		//std::cout<<"SETTING FLOAT TO 1.0f"<<std::endl;
		glUniform1f(glGetUniformLocation(ID, name), 1.0f);
	}
	else{
		//std::cout<<"SETTING FLOAT TO 0.0f"<<std::endl;
		glUniform1f(glGetUniformLocation(ID, name), 0.0f);
	}
	int err = glGetError();
	if(err){
		std::cout<<"SHADER UNIFORM ERRORS" <<err<<std::endl;
	}
}
