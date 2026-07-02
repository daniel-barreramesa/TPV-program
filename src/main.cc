#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

int main()
{
  InitWindow(1280, 720, "raylib + ImGui");

  SetTargetFPS(60);

  rlImGuiSetup(true);

  bool mostrar = true;
  float valor = 0.5f;

  while (!WindowShouldClose())
  {
    BeginDrawing(); //raylib
    ClearBackground(DARKGRAY);

    DrawCircle(300, 300, 80, RED);

    rlImGuiBegin(); //imgui

    ImGui::Begin("Panel");

    ImGui::Text("Hola Mundo");
    ImGui::Checkbox("Mostrar", &mostrar);
    ImGui::SliderFloat("Valor", &valor, 0.0f, 1.0f);

    ImGui::End();

    rlImGuiEnd(); // final imgui

    EndDrawing();
  }

  rlImGuiShutdown();

  CloseWindow();
    
  return 0;
}