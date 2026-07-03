#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"

#include<vector>

#include"Objects/products.h"
#include"Objects/user.h"
#include"load_functions.h"

// GLOBAL VARIABLES
bool tpv = false;
bool userwindow = false;
char local[4] = "";
char almacen[4] = "";
std::vector<const char*> sellervec = {
    "Vendedor 1",
    "Vendedor 2",
    "Vendedor 3"
};
static int sellerselect = 0;
std::vector<const char*> invoicetype = {
    "Factura Simplificada",
    "Devolución",
    "Contado",
    "Albarán",
    "Presupuesto"
};
static int invoicetypeselect = 0;
char customer[256] = "";
const int MinFIl = 16;
int numFilas = std::max((int)sellervec.size(), MinFIl);
std::vector<Product> products_selected;
std::vector<std::vector<std::string>> productsbuffer = {};;
std::vector<const char*> paymentmethod = {
    "Efectivo",
    "Tarjeta",
    "Presupuesto",
    "Otro",
};
static int paymentmethodselect = 0;
char clientname[256] = "";
char clientdni[50] = "";
char clientemail[256] = "";
char clientphone[50] = "";
char clientnif[50] = "";
char clientadress[256] = "";
char clientnotes[256] = "";
char clientid[20] = "";

//GLOBAL VARIABLES END



void drawgui(Texture2D &tpvim, Texture2D &userim){
  ImGui::StyleColorsLight();
  bool menu = true;

  //INVOICE GENERATOR (TPV)
  if(tpv){
  ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Once);
  ImGui::SetNextWindowSize(ImVec2(1200, 700), ImGuiCond_Once);
  ImGui::Begin("TPV", &tpv);

  ImGui::SetNextItemWidth(40);
  ImGui::InputText("local", local, 4);
  ImGui::SetNextItemWidth(40);
  ImGui::SameLine();
  ImGui::InputText("almacén", almacen, 4);

  ImGui::Spacing();
  ImGui::Spacing();
  ImGui::SetNextItemWidth(200);
  ImGui::Combo("Vendedor", &sellerselect, sellervec.data(), sellervec.size());
  ImGui::SetNextItemWidth(200);
  ImGui::SameLine(0.0f, 50.0f);
  ImGui::Combo("Tipo factura", &invoicetypeselect, invoicetype.data(), invoicetype.size());
  ImGui::SetNextItemWidth(200);
  ImGui::SameLine(0.0f, 300.0f);
  ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 0, 255, 255));
  ImGui::Text(invoicetype[invoicetypeselect]);
  ImGui::PopStyleColor();

  ImGui::Spacing();
  ImGui::Spacing();
  ImGui::SetNextItemWidth(400);
  ImGui::InputText("Cliente", customer, 256);

  //TODO: The table crashes when characters are written
  ImGui::BeginChild("ZonaProductos", ImVec2(0, 500), true); //TABLA
  ImGui::Spacing();
  ImGui::Spacing();
  float total_sum = 0.0;
  while (productsbuffer.size() < MinFIl) {
    productsbuffer.push_back(std::vector<std::string>(7));
  }
  if (ImGui::BeginTable("Productos", 7,
    ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)) {
    ImGui::TableSetupColumn("Id");
    ImGui::TableSetupColumn("Nombre");
    ImGui::TableSetupColumn("Descripción");
    ImGui::TableSetupColumn("Cantidad");
    ImGui::TableSetupColumn("PVP");
    ImGui::TableSetupColumn("Dto.");
    ImGui::TableSetupColumn("Total");
    ImGui::TableHeadersRow();

    for (int fila = 0; fila < productsbuffer.size(); fila++) {
      ImGui::TableNextRow();
      for (int col = 0; col < 7; col++) {
        ImGui::TableNextColumn();

        std::string id = "##" + std::to_string(fila) + "_" + std::to_string(col);

        ImGui::SetNextItemWidth(-FLT_MIN);
        ImGui::InputText(id.c_str(), &productsbuffer[fila][col]);
        if(col == 6 && productsbuffer[fila][col] != "")
          total_sum = total_sum + std::stof(productsbuffer[fila][col]);
      }
    }
  ImGui::EndTable();
  }
  ImGui::Spacing();
  ImGui::Spacing();
  if(ImGui::Button("+"))
    productsbuffer.push_back(std::vector<std::string>(7));
  ImGui::SameLine();
  if(ImGui::Button("-"))
    productsbuffer.pop_back();
  ImGui::SameLine(0.0f, 960.0f);
  ImGui::Text("Total %.2f €",total_sum);
  ImGui::EndChild();

  ImGui::Spacing();
  ImGui::Spacing();
  ImGui::PushStyleColor(ImGuiCol_Button,        ImVec4(0.85f, 0.20f, 0.20f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.95f, 0.30f, 0.30f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive,  ImVec4(0.75f, 0.10f, 0.10f, 1.0f));
  if(ImGui::Button("Cancelar")){}
  ImGui::PopStyleColor(3);
  ImGui::SameLine();
  ImGui::PushStyleColor(ImGuiCol_Button,        IM_COL32(86, 244, 113, 255));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(76, 224, 143, 255));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive,  IM_COL32(39, 174, 96, 255));
  if (ImGui::Button("Guardar Borrador")){}
  ImGui::PopStyleColor(3);
  ImGui::SameLine(0.0f, 500.0f);
  ImGui::SetNextItemWidth(120);
  ImGui::Combo("Método de pago", &paymentmethodselect, paymentmethod.data(), paymentmethod.size());
  if(invoicetypeselect == 4)
    paymentmethodselect = 2;
  if(invoicetypeselect == 3)
    paymentmethodselect = 3;

  ImGui::SameLine(0.0f, 100.0f);
  if(ImGui::Button("TERMINADO")) {}
  ImGui::End();
  }
  
  //USER MENU
  if(userwindow){
  ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Once);
  ImGui::SetNextWindowSize(ImVec2(1000, 700), ImGuiCond_Once);
  ImGui::Begin("Clientes", &userwindow);

  ImGui::SetNextItemWidth(300);
  ImGui::InputText("Nombre", clientname, 256);
  ImGui::SameLine();
  ImGui::SetNextItemWidth(100);
  ImGui::InputText("DNI", clientdni, 50);
  ImGui::SameLine(0.0f, 300.0f);
  ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 0, 255, 255));
  ImGui::Text("Gestor Clientes");
  ImGui::PopStyleColor();

  ImGui::Spacing();
  ImGui::Spacing();
  ImGui::SetNextItemWidth(350);
  ImGui::InputText("email", clientemail, 256);
  ImGui::SameLine();
  ImGui::SetNextItemWidth(100);
  ImGui::InputText("teléfono", clientphone, 50);
  ImGui::SameLine();
  ImGui::SetNextItemWidth(100);
  ImGui::InputText("NIF", clientnif, 50);

  ImGui::Spacing();
  ImGui::Spacing();
  ImGui::SetNextItemWidth(450);
  ImGui::InputText("dirección", clientadress, 256);

  ImGui::Spacing();
  ImGui::Spacing();
  ImGui::SetNextItemWidth(450);
  ImGui::InputText("Anotaciones", clientnotes, 256);
  ImGui::SameLine();
  ImGui::SetNextItemWidth(50);
  ImGui::InputText("ID (solo búsqueda)", clientid, 20);

  ImGui::Spacing();
  ImGui::Spacing();
  if(ImGui::Button("CREAR")) { //creates a new customer with the data
    //TODO: Check if the client already exists
    clientlist.push_back({clientname, clientdni, clientphone, clientemail, clientnif, clientadress, clientnotes});
    save_client_list();
  }
  ImGui::SameLine(0.0f, 30.0f);
  if(ImGui::Button("BUSCAR")) {}
  ImGui::SameLine(0.0f, 700.0f);
  if(ImGui::Button("ELIMINAR")) {}

  ImGui::End();
  }


  // LATERAL MENU
  Vector2 size = {80.0f, 80.0f};
  ImGui::SetNextWindowPos(ImVec2(GetScreenWidth()-100, 0), ImGuiCond_Always);
  ImGui::SetNextWindowSize(ImVec2(130, 1000), ImGuiCond_Once);
  ImGui::Begin("Menu", &menu, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
  ImGui::PushStyleColor(ImGuiCol_Button,        IM_COL32(0, 0, 0, 0));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, IM_COL32(0, 0, 0, 0));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive,  IM_COL32(0, 0, 0, 0));
  ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.0f);
  if (rlImGuiImageButtonSize("tpv",&tpvim, size))
  {
    tpv = true;
  }
  if (rlImGuiImageButtonSize("people",&userim, size))
  {
    userwindow = true;
  }
  ImGui::PopStyleVar();
  ImGui::PopStyleColor(3);
  ImGui::End();
  //MENU END

}



int main()
{
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(1500, 800, "raylib + ImGui");
  SetTargetFPS(60);
  SetExitKey(KEY_NULL);
  rlImGuiSetup(true);

  ImGui::GetIO().FontGlobalScale = 1.16f;

  load_client_list();
  Texture2D tpvim = LoadTexture("../TPV-program/images/TPV.png");
  Texture2D userim = LoadTexture("../TPV-program/images/People.png");
  while (!WindowShouldClose())
  {
    BeginDrawing(); //raylib
    ClearBackground(GRAY);


    rlImGuiBegin(); //imgui
    drawgui(tpvim, userim);
    rlImGuiEnd(); // final imgui

    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
    
  return 0;
}