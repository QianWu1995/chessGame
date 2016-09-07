//
//  display.cpp
//  Chess
//
//  Created by Qian Wu on 2016-07-24.
//  Copyright © 2016 Qian Wu. All rights reserved.
//

#include "display.h"

void display::notify() {
    draw();
}
display::display(std::shared_ptr<Grid> theBoard): theBoard{theBoard} {}
display::~display(){
}
