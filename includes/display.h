#ifndef DISPLAY_H
# define DISPLAY_H

# include <iostream>
# include <GLFW/glfw3.h>

class Display
{
private:
    GLFWwindow *m_Window;

    std::string m_Title;

    int m_Width;
    int m_Height;

    int m_LastWidth;
    int m_LastHeight;

    bool m_Resized;
    bool m_Closed;

    void create(const char *title, int width, int height);

public:
    Display(const char *title, int width, int height);
    ~Display();

    void update();

    void setTitle(const char* title);
    const char *getTitle();

    inline GLFWwindow *getWindow() { return m_Window; };

    inline int getWidth() { return m_Width; };
    inline int getHeight() { return m_Height; };

    inline bool wasResized() { return m_Resized; };
    inline bool isClosed() { return m_Closed; };

};

#endif
