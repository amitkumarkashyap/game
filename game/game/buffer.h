#pragma once
#include<GL/glew.h>


namespace game {
	namespace graphics {
		
		class Buffer
		{
		private:
			GLuint m_BufferID;
			GLuint m_ComponnetCount; //  to kown what is it vec2 3 or 4
		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componenetcount);
			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return m_ComponnetCount; }
		};
	}
}
