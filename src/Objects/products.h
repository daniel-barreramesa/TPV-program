#include<iostream>
#include<string>
#include<vector>

// Each product will have tags and id, those features will belong to vectors in
// the main program so the browser can work much faster.
#pragma once
class Product{
  public:
    Product(std::string, unsigned, float, std::string);

    std::string get_name(void) const;
    unsigned get_stock(void) const;
    float get_sell_price(void) const;
    float get_purchase_price(void) const;
    std::string get_description(void) const; 
    int get_SKU(void) const;
    int get_EAN(void) const;
    int get_taxes(void) const;

    void set_name(std::string);
    void set_stock(unsigned);
    void set_sell_price(float);
    void set_purchase_price(float);
    void set_description(std::string); 
    void set_SKU(int);
    void set_EAN(int);
    void set_taxes(int);

    //features
    void add(const int number);

  private:
    std::string name_;
    unsigned stock_;
    float sell_price_;
    float purchase_price_;  
    std::string description_;
    int SKU_; //code
    int EAN_; //bar code
    int taxes_; //percentage

};