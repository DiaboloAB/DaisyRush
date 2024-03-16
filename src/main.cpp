#include "Core.hpp"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Draw OBJ Example");

    // Load .obj file
    Model model = LoadModel("assets/flower.obj");
    Texture2D texture = LoadTexture("assets/flower.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    Core core;

    Vector3 position = { 0.0f, 0.0f, 0.0f };
    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    SetTargetFPS(60);
    DisableCursor();
    // Main loop
    entt::registry registry;

    // Create a player object
    Player player(registry, 50.0f, 50.0f, 50.0f);
    while (!WindowShouldClose()) {
        // Update
        player.update(core);
        // Draw
        BeginDrawing();
        ClearBackground(BLUE);
        player.getCamera3D().beginMode3D();
        // Draw model
        DrawGrid(1000, 10.0f);
        DrawModel(model, position, 100.0f, WHITE);
        player.getCamera3D().endMode3D();
        DrawText("(c) Flower 3D model by Alberto Cano", screenWidth - 200, screenHeight - 20, 10, GRAY);
        EndDrawing();
    }

    UnloadTexture(texture);
    // Unload model
    UnloadModel(model);

    // Cleanup
    CloseWindow();

    return 0;
}