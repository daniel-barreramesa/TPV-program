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
        ImGui::InputText("##", );

        ImGui::TableNextColumn();
        
        ImGui::TableNextColumn();
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
      if (i < productsbuffer.size()){
        ImGui::TableNextRow();

        ImGui::TableNextColumn();
        if((productsbuffer.size()-1) < i)
          productsbuffer.push_back(dummy);
        ImGui::InputText(("##id" + std::to_string(i)).c_str(), &productsbuffer[i][0]);

        ImGui::TableNextColumn();
        ImGui::InputText(("##nombre" + std::to_string(i)).c_str(), &productsbuffer[i][1]);

        ImGui::TableNextColumn();
        ImGui::InputText(("##desc" + std::to_string(i)).c_str(), &productsbuffer[i][2]);
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