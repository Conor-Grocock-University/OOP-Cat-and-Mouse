#include "raylib.h"
#include "Game.h"
#include <iostream>

bool want_to_play_again_again()
{
    std::string input;

    std::cout << "Do you want to play again (y/n) ";
    std::cin >> input;

    return (input == "y" || input == "Y");
}

int main()
{
    std::string playerName;

    std::cout << "Please enter a name: ";
    std::cin >> playerName;

    Player player(playerName);

    do
    {
        InitWindow(900, 600, "OOP Assignment 1");
        SetTargetFPS(60);
	    Game game(&player);
        
	    game.set_up();

	    while (!WindowShouldClose())
	    {
		    BeginDrawing();
		    ClearBackground(DARKGRAY);

		    if (game.is_running())
		    {
			    if (IsKeyPressed(KEY_RIGHT))  game.process_input(KEY_RIGHT);
			    if (IsKeyPressed(KEY_LEFT))   game.process_input(KEY_LEFT);
			    if (IsKeyPressed(KEY_UP))     game.process_input(KEY_UP);
			    if (IsKeyPressed(KEY_DOWN))   game.process_input(KEY_DOWN);


                DrawText(game.player->get_name().c_str(), 610, 30, 20, LIGHTGRAY);
                DrawText(std::to_string(game.player->get_score()).c_str(), 610, 50, 20, LIGHTGRAY);
		    }
		    else
		    {
			    DrawText(game.get_end_reason().c_str(), 610, 20, 20, LIGHTGRAY);
                DrawText("Press escape to play again", 610, 40, 20, LIGHTGRAY);
		    }

		    const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));

		    const auto grid = game.prepare_grid();

		    for (int x = 0; x < SIZE; x++)
		    {
			    for (int y = 0; y < SIZE; y++)
			    {
                    const int xPosition = x * cellSize;
                    const int yPosition = y * cellSize;

				    switch (grid[y][x])
				    {
					    case HOLE:       DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
					    case SNAKEHEAD:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
					    case MOUSE:      DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
					    case FREECELL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
					    case NUT:        DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);	 break;
					    default:         assert(false); // if this assert triggers there's an unrecognised tile on the grid!
				    }

				    // draw lines around each tile, remove this if you don't like it!
				    DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
			    }
		    }

		    EndDrawing();
	    }
	    CloseWindow();

    } while (want_to_play_again_again());
	return 0;
}
