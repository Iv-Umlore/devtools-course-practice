// Copyright 2017 Kiselev Ivan

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "../include/Application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
    return 0;
}
