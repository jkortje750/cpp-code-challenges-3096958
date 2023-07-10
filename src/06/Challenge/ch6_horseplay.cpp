// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
const int numsq = 8;
struct Delta
{
    int xdiff;
    int ydiff;
};    

const Delta delta[] = { {-2, 1}, {-1, 2}, {2, 1}, {1, 2},
                        {-2, -1}, {-1, -2}, {2, -1}, {1, -2} };

std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    // Write your code here
    char first = knight[0]; 
    char second = knight[1]; 

    // First convert knight to x an y coordinates
    if ((first >= 'a') && (first <= 'h') &&
        (second >= '1') && (second <= ('0' + numsq))) {

        int x = first - 'a';
        int y = second - '1';

        for (int i = 0; i < numsq; i++) {
            int x1 = x + delta[i].xdiff;
            int y1 = y + delta[i].ydiff;
            if ((x1 >= 0) && (x1 < numsq) && 
                (y1 >= 0) && (y1 < numsq)) {
                std::string s1 = "  ";
                s1[0] = x1 + 'a';
                s1[1] = y1 + '1';
                moves.push_back(s1);
            }
        }
    }

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}