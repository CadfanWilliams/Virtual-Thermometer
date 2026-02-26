#include <iostream>
#include "temperature/TemperatureReadingGenerator.h"

using namespace Temperature;

int main()
{
    TemperatureReadingGenerator generator;
    generator.startGenerator();
    // TODO send payload to kafka stream
}
