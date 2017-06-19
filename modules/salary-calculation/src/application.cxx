// Copyright 2017 Kiselev Ivan

#include <string>
#include "include/Application.h"

Application::Application() {}

std::string Application::operator()(int argv, const char** argc) {
    return "Comleted";
}
