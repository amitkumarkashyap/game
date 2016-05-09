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

	while (!window.closed())
	{
		window.clear();

		cout << "Vec 4 a: "<< a << endl;
		cout << "Not equal " << (a!=b) << endl;
		cout << "Vec3 "<< vector << endl;

		if(window.isKeyPressed(GLFW_KEY_A))
			cout<<"KEY PRESSED"<< endl;

		if (window.isMousebuttonPressed(GLFW_MOUSE_BUTTON_LEFT))
			cout << "MOUSE PRESSED" << endl;

		double x, y;
		window.getMousePosition(x, y);
		cout << "X: " << x << " Y: " << y << endl;

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