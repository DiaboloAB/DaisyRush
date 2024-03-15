#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Draw OBJ Example");

    // Load .obj file
    Model model = LoadModel("assets/flower.obj");
    Texture2D texture = LoadTexture("assets/flower.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    Camera camera = {0};
    camera.position = { 50.0f, 50.0f, 50.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 90.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Vector3 position = { 0.0f, 0.0f, 0.0f };
    BoundingBox bounds = GetMeshBoundingBox(model.meshes[0]);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    // Main loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        // Draw model
        DrawModel(model, position, 100.0f, WHITE);
        EndMode3D();
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