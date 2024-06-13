#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
//You can edit or delete the codes here, it stands as an example

const GLint WIDTH = 800.0f, HEIGHT = 600.0f;


int drawSquare(float x,float y,float mx,float my){




    
    float leftX = -1.0f - (x / -WIDTH);
    float leftY = 1.0f - (y / HEIGHT);
    float rightBottomX = 0.5f;
    float rightBottomY = 0.0f;


    std::cout << -leftY << std::endl;

    glBegin(GL_QUADS);
    glVertex2f(leftX, leftY);        
    glVertex2f(rightBottomX, leftY);          
    glVertex2f(rightBottomX, rightBottomY);  
    glVertex2f(leftX, rightBottomY);      
    glEnd();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW başlatılamadı!" << std::endl;
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Opengl example task", nullptr, nullptr);
    if (!window) {
        std::cerr << "GLFW penceresi oluşturulamadı!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Glad yüklenemedi!" << std::endl;
        return -1;
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    






    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        drawSquare(50.0f,50.0f,100.0f,100.0f);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

