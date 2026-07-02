#include<iostream>
#include<string>

class Product{
  public:


    //functionalities
    void add(const int number);

  private:
    std::string name_;
    unsigned stock_;
    float price_;
    std::string description_;

};