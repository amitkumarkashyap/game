//#include<GLFW/glfw3.h>
//#include<iostream>
#include "window.h"
#include "maths.h"

using namespace std;

int main()
{
	using namespace game;
	using namespace maths;

	window window("GAME", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	vec3 vector(1.0f, 2.0f, 3.0f);
	vector.multiply(vec3(5, 2,1)).add(vec3(2,2,2));

	vec4 a(1.0f, 2.0f, 3.0f,4.0f);
	vec4 b(3, 4,5,6);

	a *= b;

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();

	position.elements[12] = 2.0f;

	//Union
	/*vec4 column = position.columns[3];
	vec4 column1 = position.getcolumn(3);

	cout << "Columns vec4 : " << column<<endl;
	cout << "Columns vec4 : " << column<<endl;
	
	cout << "element[12] : " << &position.elements[12] << endl;
	cout << "Column[3] : " << &position.columns[3] << endl;
	
	cout << "Column1.x : " << &column1.x << endl;*/

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

#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5F, -0.5F);
		glVertex2f(-0.5F,  0.5F);
		glVertex2f( 0.5F,  0.5F);
		glVertex2f( 0.5F, -0.5F);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
#endif
		window.update();
	}

	//system("PAUSE");
	return 0;
}