#include <iostream>
#include <string>
#include <vector>
#include "user.h"


std::vector<Client> clientlist;


// USER CLASS

        //Constructores
        User::User() : name_(""), dni_(""), telephone_number_(""), email_(""), role_id_(0) {};
        User::User(std::string name, std::string dni, std::string telephone_number, std::string email):
                name_(name), dni_(dni), telephone_number_(telephone_number), email_(email), role_id_(0) {};

        //Getters-Setters
        std::string User::get_name() {
            return name_;
        }

        void User::set_name(std::string n) {
            name_ = n;
        }

        std::string User::get_dni() {
            return dni_;
        }

        void User::set_dni(std::string d) {
            dni_= d;
        }

        std::string User::get_telephone_number(){
            return telephone_number_;
        }

        void User::set_telephone_number(std::string t){
            telephone_number_ = t;
        }

        std::string User::get_email() {
            return email_;
        }

        void User::set_email(std::string e) {
            email_ = e;
        }

        int User::get_role_id() {
            return role_id_;
        }

        void User::set_role_id(int r) {
            role_id_ = r;
        }




// CLIENT CLASS

        // Variable Global
        unsigned Client::next_id_ = 1;

        Client::Client() : User(), client_number_(next_id_++) { set_role_id(1); };
        Client::Client(std::string name, std::string dni, std::string telephone_number, std::string email, std::string NIF,
                       std::string adress, std::string notes) :
                User(name, dni, telephone_number, email), client_number_(next_id_++), NIF_(NIF),
                adress_(adress), notes_(notes) { set_role_id(1); };

        //Getter
        unsigned Client::get_client_number() {
           return client_number_;
        }

        //Information Function
        void Client::show_info() {
            std::cout << "CLIENT\n Name: " << get_name() << "\nDNI: "<< get_dni() << "\nTelephone Number: " <<
            get_telephone_number() << "\nE-mail: " << get_email() << "\nClient Number: " << get_client_number() 
            << std::endl;
        }