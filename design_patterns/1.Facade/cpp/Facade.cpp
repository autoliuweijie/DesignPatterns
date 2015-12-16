//
//  Facade.cpp
//  design_patterns
//
//  Created by liuweijie on 15/12/16.
//  Copyright © 2015年 dataliu. All rights reserved.
//

#include <iostream>
#include "Facade.h"

void FlashLight:: close(){
    std::cout <<" this is close!";
}

void FlashLight:: open(){
    std::cout <<" this is open!";
}

