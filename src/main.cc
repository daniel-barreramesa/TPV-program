#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

#include<vector>

#include"Objects/products.h"

// GLOBAL VARIABLES
bool tpv = true;
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


//GLOBAL VARIABLES END

void drawgui(Texture2D &tpvim){
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

  ImGui::Spacing();
  ImGui::Spacing();
  if (ImGui::BeginTable("Tabla", 7, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg)){
    ImGui::TableSetupColumn("Id");
    ImGui::TableSetupColumn("Nombre");
    ImGui::TableSetupColumn("Descripción");
    ImGui::TableSetupColumn("Cantidad");
    ImGui::TableSetupColumn("PVP");
    ImGui::TableSetupColumn("Dto.");
    ImGui::TableSetupColumn("Total");
    ImGui::TableHeadersRow();

    for (int i = 0; i < numFilas; i++)
    {
      if (i < sellervec.size()){
        ImGui::TableNextRow();

        ImGui::TableNextColumn();
        ImGui::Text("%s", sellervec[i]);

        ImGui::TableNextColumn();
        ImGui::Text("%d", sellervec[i]);

        ImGui::TableNextColumn();
        ImGui::Text("%s", sellervec[i]);
      }
      else{
        // Filas vacías
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
        ImGui::TableNextColumn();
        ImGui::TextUnformatted("");
      }
    }

    ImGui::EndTable();
}

  ImGui::End();
  }
  
  // MENU
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

  Texture2D tpvim = LoadTexture("../TPV-program/images/TPV.png");
  while (!WindowShouldClose())
  {
    BeginDrawing(); //raylib
    ClearBackground(GRAY);


    rlImGuiBegin(); //imgui
    drawgui(tpvim);
    rlImGuiEnd(); // final imgui

    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
    
  return 0;
}