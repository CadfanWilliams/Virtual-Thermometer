#include <string>
#include <thread>
#include <ctime>
#include <iostream>
#include <chrono>
#include "TemperatureReadingGenerator.h"

namespace Temperature
{
    void TemperatureReadingGenerator::startGenerator(std::string sensorname)
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
            std::string payload = generatePayload(sensorname);
            std::cout << payload << std::endl;
        }
    }

    std::string TemperatureReadingGenerator::generatePayload(std::string sensorname)
    {
        double newTemperature = generateNewTemperature();
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);

        char buffer[25];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", std::gmtime(&time));

        std::string payload =
            "{\"sensorid\": \"" + sensorname + "\", \"temperature\": " +
            std::to_string(newTemperature) +
            ", \"unit\": \"C\", \"timestamp\": \"" +
            std::string(buffer) +
            "\"}";

        lastTemperature = newTemperature;
        return payload;
    }

    double TemperatureReadingGenerator::generateNewTemperature()
    {
        double change = (rand() % 20 - 10) / 100.0;
        return lastTemperature + change;
    }
}