#include <string>
#include <iostream>

class Account{
public:
    Account() = default;
    Account(std::string name):m_name(name){}
    const std::string& getName() const {
        return m_name;
    }

    void setName(const std::string& name){
        m_name = name;
    }
private:
    std::string m_name{};
};
