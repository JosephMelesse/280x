#pragma once 
#include <string> 

// Base class for compensation models
class CompensationModel {
public:
   // virtual dtor
   virtual ~CompensationModel() = default; 
   // compute earnings
   virtual double earnings() const = 0; 
   // return text
   virtual std::string toString() const = 0; 
};