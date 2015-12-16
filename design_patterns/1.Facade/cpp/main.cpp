//
//  main.cpp
//  design_patterns
//
//  Created by liuweijie on 15/12/15.
//  Copyright © 2015年 dataliu. All rights reserved.
//

#include <iostream>
#include "Facade.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    FlashLight* flashlight = new FlashLight();
    flashlight->close();
    return 0;
}

