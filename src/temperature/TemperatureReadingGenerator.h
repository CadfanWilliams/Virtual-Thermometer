#include <string>
#ifndef TemperatureReadingGenerator_H
#define TemperatureReadingGenerator_H

namespace Temperature
{
    class TemperatureReadingGenerator
    {
    public:
        int interval = getenv("INTERVAL") ? std::stoi(getenv("INTERVAL")) : 5000;
        double lastTemperature = 20.0;
        void startGenerator();
        std::string generatePayload();
        double generateNewTemperature();
    };
}

#endif