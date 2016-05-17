//#include<GLFW/glfw3.h>
//#include<iostream>
#include "window.h"
#include "maths.h"
#include "fileutil.h"
#include "shader.h"
#include "buffer.h"
#include "indexbuffer.h"
#include "vertexarray.h"

using namespace std;

int main()
{
	using namespace game;
	using namespace maths;
	using namespace graphics;

	//filereading for shades"
	/*string file = read_file("main.cpp");
	cout << file << endl;

	system("PAUSE");
	return 0;*/

	window window("GAME", 960, 540);
//bluecolor	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

/*light_pos*/ 	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
	//GLuint vao;
	/*glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);*/
	
	//vec3 vector(1.0f, 2.0f, 3.0f);
	//vector.multiply(vec3(5, 2,1)).add(vec3(2,2,2));

	//vec4 a(1.0f, 2.0f, 3.0f,4.0f);
	//vec4 b(3, 4,5,6);

	//a *= b;

	//mat4 position = mat4::translation(vec3(2, 3, 4));
	//position *= mat4::identity();

	//position.elements[12] = 2.0f;

	//Union
	/*vec4 column = position.columns[3];
	vec4 column1 = position.getcolumn(3);

	cout << "Columns vec4 : " << column<<endl;
	cout << "Columns vec4 : " << column<<endl;
	
	cout << "element[12] : " << &position.elements[12] << endl;
	cout << "Column[3] : " << &position.columns[3] << endl;
	
	cout << "Column1.x : " << &column1.x << endl;*/

	/*-------------------shaders--------------------------------*/
#if 0  //---------vertex abd buffers...........
GLuint vao;
	//GLfloat vertices[] = {
	//   -0.5F,  -0.5F, 0.0f,
	//   -0.5F,   0.5F, 0.0f,
	//	0.5F,   0.5F, 0.0f,
	//	0.5F,   0.5F, 0.0f,
	//	0.5F,  -0.5F, 0.0f,
	//	-0.5F,  -0.5F, 0.0f
	//};


	GLfloat vertices[] = {
		0, 0, 0,
		8, 0, 0,
		0, 3, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	glGenBuffers(1, &vao);
	glBindBuffer(GL_ARRAY_BUFFER, vao);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

#else
	
	GLfloat vertices[] = {
			0, 0, 0,
			0, 3, 0,
			8, 3, 0,
			8, 0, 0
		};

	GLushort indices[] = {
			0, 1, 2,
			2, 3, 0 
	};

	GLfloat colorsA[] = {

		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};

	GLfloat colorsB[] = {

		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1 
	};

	/*VertexArray vao;
	Buffer* vbo = new Buffer(vertices, 4 * 3, 3);
	IndexBuffer ibo(indices, 6);*/

	VertexArray sprite1, sprite2;
	IndexBuffer ibo(indices, 6);

	sprite1.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1.addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2.addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2.addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);
	//vao.addBuffer(vbo, 0);

#endif
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	
	Shader shader("basic.vert", "basic.frag");
	shader.enable();
	
	//glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
	//shader.setUniformMat4("ml_matrix", mat4::rotation(45.0f,vec3(0, 0, 1)));

	//shader.setUniform2f("light_pos", vec2(8.0f, 4.5f));
	//shader.setUniform2f("light_pos", vec2(0.0f, 0.0f));   //for corner left bottom light
	shader.setUniform2f("light_pos", vec2(45.0f, 1.f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	/*------------------shaders-------------------------------*/
	
	while (!window.closed())
	{
		window.clear();

		/*cout << "Vec 4 a: "<< a << endl;
		cout << "Not equal " << (a!=b) << endl;
		cout << "Vec3 "<< vector << endl;*/

		/*if(window.isKeyPressed(GLFW_KEY_A))
			cout<<"KEY PRESSED"<< endl;

		if (window.isMousebuttonPressed(GLFW_MOUSE_BUTTON_LEFT))
			cout << "MOUSE PRESSED" << endl;*/

		/*double x, y;
		window.getMousePosition(x, y);
		cout << "X: " << x << " Y: " << y << endl;*/
		
		//-------------Buffer and Vertex----------------------
			
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));


		//-----------------------------------
//#if 1
//		glBegin(GL_QUADS);
//		glVertex2f(-0.5F, -0.5F);
//		glVertex2f(-0.5F,  0.5F);
//		glVertex2f( 0.5F,  0.5F);
//		glVertex2f( 0.5F, -0.5F);
//		glEnd();
//#else
#if 0
		glDrawArrays(GL_TRIANGLES, 0, 6);
#else
		sprite1.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite1.unbind();

		sprite2.bind();
		ibo.bind();
		shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0, 0, 0)));
		glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
		ibo.unbind();
		sprite2.unbind();
		
#endif
		window.update();
	}

	return 0;
}