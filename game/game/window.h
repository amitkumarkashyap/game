#pragma once

#include<GL/glew.h>	
#include<GLFW/glfw3.h>

#include<iostream>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

using namespace std;
namespace game {

	class window
	{
	private:
		const char *m_Name;
		int m_Width, m_Height;
		GLFWwindow *m_Window;
		bool m_Closed;

		bool m_Keys[MAX_KEYS];
		bool m_Buttons[MAX_BUTTONS];
		double mx, my;
	public:
		
		window(const char *name, int width, int height);
		~window();
		void update();
		bool closed() const;
		void clear() const;
		bool isKeyPressed(unsigned int keycode) const;
		bool isMousebuttonPressed(unsigned int button) const;
		void getMousePosition(double&x , double&y ) const;

	private:
		bool Init();	
		friend static void key_callback(GLFWwindow* thiswindows, int key, int scancode, int action, int mods);
		friend static void mousebutton_callback(GLFWwindow* thiswindows, int button, int action, int mods);
		friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		
	};
}