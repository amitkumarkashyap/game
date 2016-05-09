#include "window.h"

namespace game {

	void windowresize(GLFWwindow *window, int width, int height);
  
	window::window(const char *name, int width, int height)
	{
		m_Name = name;
		m_Height = height;
		m_Width = width;
		if (!Init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_Buttons[i] = false;
		}
	}

	window::~window()
	{
		glfwTerminate();
	}

	bool window::Init()
	{
		if (!glfwInit())
		{
			cout << "Error in GLFW";
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if (!m_Window)
		{
			glfwTerminate();
			cout << "Windows creation is falied" << endl;
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window,this);
		glfwSetWindowSizeCallback(m_Window, windowresize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mousebutton_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);

		//Glew should always be initalize after the context otherwise it will give error
		
		if (glewInit() != GLEW_OK)
		{
			cout << "Could not Initalize GLEW" << endl;
			return false;
		}
		cout << "GL Version" << glGetString(GL_VERSION) << endl;
		return true;
	}

	bool window::isKeyPressed(unsigned int keycode) const
	{
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}

	bool window::isMousebuttonPressed(unsigned int button) const
	{
		if (button >= MAX_BUTTONS)
			return false;

		return m_Buttons[button];
	}

	void window::getMousePosition(double&x, double&y) const
	{
		x = mx;
		y = my;
	}

	void window::clear() const 
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}

	bool window::closed() const
	{
	    return glfwWindowShouldClose(m_Window) == 1;
	}

	void window::update() 
	{
		glfwPollEvents();
		//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		
		glfwSwapBuffers(m_Window);
	}

	void windowresize(GLFWwindow *window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* thiswindows, int key, int scancode, int action, int mods)
	{
		window* win = (window*)glfwGetWindowUserPointer(thiswindows);
		win->m_Keys[key] = action != GLFW_RELEASE;

	}

	void mousebutton_callback(GLFWwindow* thiswindows, int button, int action, int mods)
	{
		window* win = (window*)glfwGetWindowUserPointer(thiswindows);
		win->m_Buttons[button] = action != GLFW_RELEASE;
	}
	
	void cursor_position_callback(GLFWwindow* thiswindows, double xpos, double ypos)
	{
		window* win = (window*)glfwGetWindowUserPointer(thiswindows);
		win->mx = xpos;
		win->my = ypos;
	}
}