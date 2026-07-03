#include<iostream>
#include<string>
#include<vector>
#include<fstream>

#include"Objects/products.h"
#include"Objects/user.h"

void load_client_list(void);
void save_client_list(void);

int get_client_id_name(std::string name);
int get_client_id_dni(std::string dni);
int get_client_id_phone(std::string phone);
int get_client_id_email(std::string email);
int get_client_id_NIF(std::string NIF);