// Fig. 10.19: CompensationModel.h
// CompensationModel "interface" is a pure abstract base class.
#pragma once // prevent multiple inclusions of header
#include <string>

class CompensationModel {
  public:
    virtual ~CompensationModel() = default; // generated destructor
    virtual double earnings() const = 0; // pure virtual
    virtual std::string toString() const = 0; // pure virtual
};
