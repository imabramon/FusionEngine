//
//  ClickerController.hpp
//  Fusion Engine
//
//  Created by Влад Шелопугин on 10.02.2022.
//  Copyright © 2022 Влад Шелопугин. All rights reserved.
//

#ifndef ClickerController_hpp
#define ClickerController_hpp

#include <stdio.h>
#include <string>

#include "../Fusion/Headers/AbstractControler.hpp"
#include "../Fusion/Headers/GameObject.hpp"

#include "../Headers/ClickerModel.hpp"

class ClickerController: public AbstractControler{
public:
    ClickerController();
    ~ClickerController();
    
    void display() override;
    void reshape(GLint t_width, GLint t_height) override;
    void mouse(int t_button, int t_state, int t_x, int t_y) override;
    void timer(int t_time) override;
    int getWidth() const override;
    int getHeight() const override;
    std::string getCurrentWindowTitle() override;
protected:
    void __destructor() override;
private:
    GameObject * m_scene;
    ClickerModel m_model;
    int temp_score = 100;
};

#endif /* ClickerController_hpp */
