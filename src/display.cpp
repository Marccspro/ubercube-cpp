#include "display.h"

Display::Display(const char *title, int width, int height)
{
    m_width = width;
    m_height = height;

    Display::create(title, width, height);
}

void Display::create(const char *title, int width, int height)
{
    m_title = title;
    if (!glfwInit())
    {
        std::cerr << "Couldn't initialize glfw !" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    m_window = glfwCreateWindow(width, height, m_title.c_str(), NULL, NULL);

    if (!m_window)
	{
        glfwTerminate();
        std::cerr << "GLFW window creation failed !" << std::endl;
        return;
    }

    glfwSwapInterval(0);
    glfwMakeContextCurrent(m_window);
}

Display::~Display()
{
    glfwTerminate();
}

void Display::update()
{
    glfwPollEvents();
	glfwSwapBuffers(m_window);
	glfwGetWindowSize(m_window, &m_width, &m_height);

	m_resized = false;

	if (m_last_width != m_width || m_last_height != m_height)
	{
		m_last_width = m_width;
		m_last_height = m_height;

		m_resized = true;
	}

    m_closed = glfwWindowShouldClose(m_window) == 1;
}

void Display::set_title(const char* title)
{
    m_title = title;
    glfwSetWindowTitle(m_window, title);
}

const char *Display::get_title()
{
    return m_title.c_str();
}
