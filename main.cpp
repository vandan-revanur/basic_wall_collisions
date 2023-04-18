#include <iostream>
#include <raylib.h>
#include <tuple>

std::tuple<int, int> move_ball(int ball_x, int ball_y, float ball_radius, int ball_speed_x, int ball_speed_y, int screenWidth, int screenHeight);
std::tuple<int, int> update_speed(int ball_x, int ball_y, float ball_radius, int ball_speed_x, int ball_speed_y, int screenWidth, int screenHeight, float eleasticity_coeff);
using namespace std;

int main () {

    const int screenWidth = 800;
    const int screenHeight = 600;
    int ball_1_x = 100;
    int ball_1_y = 100;
    int ball_speed_x = 5;
    int ball_speed_y = 5;
    int ball_radius = 15;

    char eleasticity_type;
    float elasticity_coeff;


    cout << "Enter e for elastic and ie for inelastic collision: ";
    cin >> eleasticity_type;

    InitWindow(screenWidth, screenHeight, "Collsions!");
    SetTargetFPS(60);
    

    if (eleasticity_type == 'e')
        {
        elasticity_coeff = 1;
        }
    else
        {
        elasticity_coeff = 0.4;
        }

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);

        tie(ball_1_x, ball_1_y) = move_ball(ball_1_x, ball_1_y, ball_radius, ball_speed_x, ball_speed_y, screenWidth, screenHeight);
        tie(ball_speed_x, ball_speed_y) = update_speed(ball_1_x, ball_1_y, ball_radius, ball_speed_x, ball_speed_y, screenWidth, screenHeight, elasticity_coeff);
        DrawCircle(ball_1_x, ball_1_y, ball_radius, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

std::tuple<int, int> move_ball(int ball_x, int ball_y, float ball_radius, int ball_speed_x, int ball_speed_y, int screenWidth, int screenHeight )
{
        
        ball_x += ball_speed_x;
        ball_y += ball_speed_y;

        return {ball_x, ball_y};
}

std::tuple<int, int> update_speed(int ball_x, int ball_y, float ball_radius, int ball_speed_x, int ball_speed_y, int screenWidth, int screenHeight, float eleasticity_coeff)
{
    if(ball_x + ball_radius >= screenWidth  || ball_x - ball_radius <= 0)
        {
            ball_speed_x *= -eleasticity_coeff;
            
        }

        if(ball_y + ball_radius >= screenHeight  || ball_y - ball_radius <= 0)
        {
            ball_speed_y *= -eleasticity_coeff;
            
        }
        return {ball_speed_x, ball_speed_y};
}