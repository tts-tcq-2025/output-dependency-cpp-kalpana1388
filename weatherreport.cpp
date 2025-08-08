#include <string>
#include <iostream>
#include <assert.h>

using namespace std;

namespace WeatherSpace
{    
    class IWeatherSensor {
        public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };
    /// <summary>
    /// This is a stub for a weather sensor. For the sake of testing 
    /// we create a stub that generates weather data and allows us to
    /// test the other parts of this application in isolation
    /// without needing the actual Sensor during development
    /// </summary>
    class SensorStub : public IWeatherSensor {
        int Humidity() const override {
            return 72;
        }

        int Precipitation() const override {
            return 70;
        }

        double TemperatureInC() const override {
            return 26;
        }

        int WindSpeedKMPH() const override {
            return 52;
        }
    };
    string Report(const IWeatherSensor& sensor)
    {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny Day";

        if (sensor.TemperatureInC() > 25)
        {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly Cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }
    
    void TestRainy()
    {
        SensorStub sensor;
        string report = Report(sensor);
        cout << report << endl;
        assert(report.find("rain") != string::npos);
    }

    void TestHighPrecipitation()
    {
void TestHighPrecipitationFails()
{
    // Create a sensor stub with high precipitation but low wind speed
    SensorStub sensor(26, 80, 70, 20); // Precipitation=80, Wind=20 (low)
    string report = Report(sensor);
    cout << "TestHighPrecipitationFails Report: " << report << endl;

    // We expect rain-related message but if the function is buggy,
    // it might return "Sunny Day" causing this assert to fail
    assert(report.find("rain") != string::npos && "Expected rain-related report but got none!");
}
    }
}


void testWeatherReport() {
    cout << "\nWeather report test\n";
    WeatherSpace::TestRainy();
    WeatherSpace::TestHighPrecipitation();
    WeatherSpace::TestHighPrecipitationFails();  // New test that may expose an error
    cout << "All is well (maybe)\n";
}
}
