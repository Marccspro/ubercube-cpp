#include "display.h"

Display::Display(const char *title, int width, int height)
{
    m_Width = width;
    m_Height = height;

    Display::create(title, width, height);
}

void Display::create(const char *title, int width, int height)
{
    m_Title = title;
    if (!glfwInit())
    {
        std::cerr << "Couldn't initialize glfw !" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);

    m_Window = glfwCreateWindow(width, height, m_Title.c_str(), NULL, NULL);

    if (!m_Window) {
        glfwTerminate();
        std::cerr << "GLFW window creation failed !" << std::endl;
        return;
    }

    glfwSwapInterval(0);
    glfwMakeContextCurrent(m_Window);
}

Display::~Display()
{
    glfwTerminate();
}

void Display::update()
{
    glfwPollEvents();
	glfwSwapBuffers(m_Window);
	glfwGetWindowSize(m_Window, &m_Width, &m_Height);

	m_Resized = false;

	if (m_LastWidth != m_Width || m_LastHeight != m_Height) {
		m_LastWidth = m_Width;
		m_LastHeight = m_Height;

		m_Resized = true;
	}

    m_Closed = glfwWindowShouldClose(m_Window) == 1;
}

void Display::setTitle(const char* title)
{
    m_Title = title;
    glfwSetWindowTitle(m_Window, title);
}

const char *Display::getTitle()
{
    return m_Title.c_str();
}
