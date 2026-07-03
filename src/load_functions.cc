#include "load_functions.h"

void load_client_list(){
  std::ifstream archivo("../TPV-program/saves/client_list.save");
  std::string line;
  int count = 0;
  Client dummy;
  if (archivo.is_open()){
    std::cout << "Archivo abierto correctamente";
    while (getline(archivo, line)){
      if(count ==0)
        dummy.set_name(line);
      if(count ==1)
        dummy.set_dni(line);
      if(count ==2)
        dummy.set_telephone_number(line);
      if(count ==3)
        dummy.set_email(line);
      if(count ==4)
        dummy.set_NIF(line);
      if(count ==5)
        dummy.set_adress(line);
      if(count ==6)
        dummy.set_notes(line);
      count++;
      if(count == 7){
        clientlist.push_back(dummy);
        count = 0;
      }
    }
  }
  else
    std::cout << "Error al abrir el archivo";
}

void save_client_list(){
  std::ofstream archivo("../TPV-program/saves/client_list.save");
  for(int i=0; i<clientlist.size(); i++){
  archivo << clientlist[i].get_name() << std::endl;
  archivo << clientlist[i].get_dni() << std::endl;
  archivo << clientlist[i].get_telephone_number() << std::endl;
  archivo << clientlist[i].get_email() << std::endl;
  archivo << clientlist[i].get_NIF() << std::endl;
  archivo << clientlist[i].get_adress() << std::endl;
  archivo << clientlist[i].get_notes() << std::endl;
  }
}


//Returns the client id by finding coincidences in the atributes
int get_client_id_name(std::string name){
  for(int i=0; i<clientlist.size(); i++){
    if(clientlist[i].get_name() == name)
      return i;
  }
  return -1;
}

int get_client_id_dni(std::string dni){
  for(int i=0; i<clientlist.size(); i++){
    if(clientlist[i].get_dni() == dni)
      return i;
  }
  return -1;
}

int get_client_id_phone(std::string phone){
  for(int i=0; i<clientlist.size(); i++){
    if(clientlist[i].get_telephone_number() == phone)
      return i;
  }
  return -1;
}

int get_client_id_email(std::string email){
  for(int i=0; i<clientlist.size(); i++){
    if(clientlist[i].get_email() == email)
      return i;
  }
  return -1;
}

int get_client_id_NIF(std::string NIF){
  for(int i=0; i<clientlist.size(); i++){
    if(clientlist[i].get_NIF() == NIF)
      return i;
  }
  return -1;
}