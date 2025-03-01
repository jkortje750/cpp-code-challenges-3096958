// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

// Summary: This function returns the number of live neighbors to a given cell.
// Arguments:
//           game[N][M]: The state of the game.
//                    i: The cell's row.
//                    j: The cell's column.
// Returns: An integer with the live neighbor count.
int live_neighbors(char game[][M],int i, int j){
    int neighbors = 0; // counter
    i += N; // yes, we increase it by the max dimension
            // because we are going to take modulus later
            // so this is a trick to handle wrapping over
            // the edge of the grid
    j += M;
    // We use the modulous to check wrapping
    // which then could be adjacent neighbors
    if(game[(i-1)%N][(j-1)%M]=='X')
        neighbors++;
    if(game[(i-1)%N][(j)%M]=='X')
        neighbors++;
    if(game[(i-1)%N][(j+1)%M]=='X')
        neighbors++;

    if(game[(i)%N][(j-1)%M]=='X')
        neighbors++;
    if(game[(i)%N][(j+1)%M]=='X')
        neighbors++;

    if(game[(i+1)%N][(j-1)%M]=='X')
        neighbors++;
    if(game[(i+1)%N][(j)%M]=='X')
        neighbors++;
    if(game[(i+1)%N][(j+1)%M]=='X')
        neighbors++;
    return neighbors;
}

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    char cloned_game[N][M];

    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        // Write your code here
        std::memcpy(cloned_game,game,N*M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int n = live_neighbors(game, i,  j);
                // Any live cell with fewer than two live neighbors dies
                // as if by underpopulation
                if ((game[i][j] == 'X') && (n < 2)) {
                    cloned_game[i][j] = '-';
                }
                // Any live cell with two or three live neighbors lives
                // on to the next generation
                if ((game[i][j] == 'X') && ((n == 2) || (n == 3))) {
                   cloned_game[i][j] = 'X';
                }
                // Any live cell with more than three live neighbors dies
                // as if by overpopulation
                if ((game[i][j] == 'X') && (n > 3)) {
                    cloned_game[i][j] = '-';
                }
                // Any dead cell with exactly three live neighbors becomes a live cell,
                // as if by reproduction.
                if ((game[i][j]=='-') && (n==3)) {
                    cloned_game[i][j]='X';
                }
            }
        }
        std::memcpy(game, cloned_game, N*M);
        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    } while(go_on.compare("EXIT")!=0);
    
    return 0;
}
