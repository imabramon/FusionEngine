#define GL_SILENCE_DEPRECATION

#include "ClickerController.hpp"

ClickerController::ClickerController(){
    
}

ClickerController::~ClickerController(){
    
}

void ClickerController::display(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void ClickerController::reshape(GLint t_width, GLint t_height){
    glViewport(0, 0, t_width, t_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, t_width, t_height, 0, -1.0, 1.0);
}

void ClickerController::mouse(int t_button, int t_state, int t_x, int t_y){
    
}

void ClickerController::timer(int t_time){
    
}

int ClickerController::getWidth() const{
    return 300;
}

int ClickerController::getHeight() const{
    return 300;
}

void ClickerController::__destructor(){
    
}

std::string ClickerController::getCurrentWindowTitle(){
    return "Clicker";
}
