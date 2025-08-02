#include <iostream>
#include <memory>
#include <string>

/**
 * @brief Singleton Logger Example
 *
 * This example demonstrates the Singleton design pattern in C++.
 * - Only one instance of Logger can exist.
 * - We use std::unique_ptr for automatic memory management.
 * - getInstance() returns a reference to ensure a single global instance
 *   without exposing raw pointers.
 */

class Logger
{
public:
    /**
     * @brief Get the single instance of Logger
     *
     * - Uses a static std::unique_ptr to manage the instance.
     * - Returning by reference avoids ownership transfer and ensures
     *   safe, direct access to the same instance.
     */
    static Logger& getInstance()
    {
        static std::unique_ptr<Logger> s_instance = std::make_unique<Logger>();
        return *s_instance; // Dereference to return a reference
    }

    void setType(const std::string &type)
    {
        m_type = type;
    }

    void getType() const
    {
        std::cout << "Logger type: " << m_type << std::endl;
    }

    Logger()
    {
        std::cout << "Logger constructed\n";
    }

    // Public destructor is fine since std::unique_ptr manages the instance.
    ~Logger() = default;

private:
    std::string m_type;



    // Delete copy and assignment to enforce Singleton.
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

int main()
{
    auto& loggerInstance = Logger::getInstance(); // Notice the reference
    loggerInstance.setType("CSV");
    loggerInstance.getType();

    return 0;
}
