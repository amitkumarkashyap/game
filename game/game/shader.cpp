#include"shader.h"


namespace game {
	namespace graphics {
	
		Shader::Shader(const char* verPath, const char* fragPath) : m_VerPath(verPath),m_FragPath(fragPath)
		{
			m_ShaderID = load();
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileUtilits::read_file(m_VerPath);
			std::string fragSourceString = FileUtilits::read_file(m_FragPath);

			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();
						
			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout <<"Failed to compiled vertex " <<&error[0] << std::endl;
				glDeleteShader(vertex);

				return 0; //unsigned int 
			}
			// same for fragment

			glShaderSource(fragment, 1, &fragSource, NULL);
			glCompileShader(fragment);

			glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout <<"Failed to Compile fragment " <<&error[0] << std::endl;
				glDeleteShader(fragment);

				return 0; //unsigned int 
			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(fragment);

			return program;

		}

		GLint Shader::getUniformLocation(const GLchar* name)
		{
			return glGetUniformLocation(m_ShaderID,name);
		}

		void Shader::setUniform1f(const GLchar* name, float value)
		{

			glUniform1f(getUniformLocation(name), value);
		}

		void Shader::setUniform1i(const GLchar* name, int value)
		{

			glUniform1i(getUniformLocation(name), value);
		}

		void Shader::setUniform2f(const GLchar* name, const maths::vec2& vector)
		{
			glUniform2f(getUniformLocation(name), vector.x,vector.y);
		
		}

		void Shader::setUniform3f(const GLchar* name, const maths::vec3& vector)
		{
			glUniform3f(getUniformLocation(name), vector.x, vector.y,vector.z);
		}

		void Shader::setUniform4f(const GLchar* name, const maths::vec4& matrix)
		{
			glUniform4f(getUniformLocation(name), matrix.x, matrix.y, matrix.z, matrix.w);
		}

		void Shader::setUniformMat4(const GLchar* name, const maths::mat4& matrix)
		{
    		glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
		}


		void Shader::enable() const
		{
			glUseProgram(m_ShaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}

		Shader::~Shader()
		{

			glDeleteShader(m_ShaderID);
		}
	}
}