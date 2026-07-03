#ifndef USER_H
#define USER_H

#include <string>
#include <vector>


class User {
    public:
        User();
        User(std::string name, std::string dni, std::string telephone_number, std::string email);

        //Getters - Setters
        std::string get_name();
        void set_name(std::string n);
        std::string get_dni();
        void set_dni(std::string d);
        std::string get_telephone_number();
        void set_telephone_number(std::string t);
        std::string get_email();
        void set_email(std::string e);
        int get_role_id();
        void set_role_id(int r);

    private:
        //Characteristics
        std::string name_;
        std::string dni_;
        std::string telephone_number_;
        std::string email_;
        int role_id_;
};




class Client : public User {
    public:
        //Constructores
        Client();
        Client(std::string name, std::string dni, std::string telephone_number, std::string email, 
            std::string NIF, std::string adress, std::string notes);

        //Getters - Setters
        unsigned get_client_number();
        std::string get_NIF() const {return NIF_;}
        std::string get_adress() const {return adress_;}
        std::string get_notes() const {return notes_;}
        void set_NIF(std::string n) {NIF_ = n;}
        void set_adress(std::string n) {adress_ = n;}
        void set_notes(std::string n) {notes_ = n;}

        //Other functions
        void show_info();
        std::string get_type();

    private:
        //Characteristics
        static unsigned next_id_;
        unsigned client_number_;
        std::string NIF_;
        std::string adress_;
        std::string notes_;
};




class Seller : public User {
    public:
        //Constructores
        Seller();
        Seller(std::string name, std::string dni, std::string telephone_number, std::string email, float salary);

        //Getters_Setters
        float get_salary();
        void set_salary(float s);
        
        //Other functions
        void show_info();
        std::string get_type();


    private:
        //Characteristics
        float salary_;
};

// Every time the program opens, the vector must be charged again.

extern std::vector<Client> clientlist;

#endif