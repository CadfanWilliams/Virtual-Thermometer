#include <iostream>
#include "TemperatureReadingGenerator.cpp"

int main() {
    TemperatureReadingGenerator generator;
    generator.startGenerator();
    //TODO send payload to kafka stream
}