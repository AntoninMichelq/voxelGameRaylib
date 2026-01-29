#include "raylib.h"

Camera camera = { 0 };
Vector3 cubePosition = { 0 };

static void UpdateDrawFrame(void);          // Update and draw one frame

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    float cx = 3.0f;
    float cy = 3.0f;
    float cz = 3.0f;
    InitWindow(screenWidth, screenHeight, "voxelGame");

    camera.position = (Vector3){ cx, cy, cz };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }

    CloseWindow();
    return 0;
}

// Update and draw game frame
static void UpdateDrawFrame(void)
{
    UpdateCamera(&camera, CAMERA_FIRST_PERSON);
    BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        for(int x = 0; x<16; x++) {
            for(int z = 0; z<16; z++) {
                cubePosition = { (float)x, 0, (float)z };
                DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, LIME);
                DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, DARKGREEN);
            }
        }

        EndMode3D();
        DrawFPS(10, 10);
    EndDrawing();
}
