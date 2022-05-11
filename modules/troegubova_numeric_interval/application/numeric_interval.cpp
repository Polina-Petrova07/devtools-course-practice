// Copyright 2022 Petrova Polina

#include "include/numeric_interval_app.h"

#include <string>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}