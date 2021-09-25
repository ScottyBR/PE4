#include <string>
#include <iostream>

struct pos {
	int row;
	int col;
};

enum class SquareType {Empty, Player1, Player2};

class TTT {
	public:
		TTT() {
			turn_count = 0;

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					arr_[i][j] = SquareType::Empty;
				}
			}
		}

		SquareType getPosition(pos z) {
			return arr_[z.row][z.col];
		}

		void setPosition(pos z, SquareType p) {
			arr_[z.row][z.col] = p;
		}

		bool isValidMove(pos z) {
			if (arr_[z.row][z.col] == SquareType::Empty && z.row > -1 && z.row < 3 && z.col > -1 && z.col < 3) {
				return true;
			}
			else {
				return false;
			}
		}

		bool isGameOver() {
			int count = 0;

			//check columns
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (arr_[i][j] == SquareType::Player1) {
						count++;
					}
					else if (arr_[i][j] == SquareType::Player2) {
						count--;
					}
				}
				if (count == -3 || count == 3) {
					return true;
				}
				count = 0;
			}

			//check rows
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (arr_[j][i] == SquareType::Player1) {
						count++;
					}
					else if (arr_[j][i] == SquareType::Player2) {
						count--;
					}
				}
				if (count == -3 || count == 3) {
					return true;
				}
				count = 0;
			}

			//check diagonals
			for (int i = 0; i < 3; i++) {
				if (arr_[i][i] == SquareType::Player1) {
					count++;
				}
				else if (arr_[i][i] == SquareType::Player2) {
					count--;
				}
			}
			if (count == -3 || count == 3) {
				return true;
			}
			count = 0;

			for (int i = 0; i < 3; i++) {
				if (arr_[i][2-i] == SquareType::Player1) {
					count++;
				}
				else if (arr_[i][2-i] == SquareType::Player2) {
					count--;
				}
			}
			if (count == -3 || count == 3) {
				return true;
			}

			return false;
		}

		void printBoard() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++){
					switch (arr_[i][j]) {
						case SquareType::Empty:
							std::cout << "\U00002B1B";
							break;
						case SquareType::Player1:
							std::cout << "\U00002B55";
							break;
						case SquareType::Player2:
							std::cout << "\U0000274C";
							break;
					}
				}
				std::cout << std::endl;
			}
		}

		void takeTurn() {
			pos player_move;

			printBoard();

			while (!isValidMove(player_move)) {
				if (turn_count % 2 == 0) {
					std::cout << "Player1:" << std::endl;
				}
				else {
					std::cout << "Player2:" << std::endl;
				}
				std::cout << "Enter the row of your move: ";
				std::cin >> player_move.row;
				std::cout << "Enter the col of your move: ";
				std::cin >> player_move.col;
			}
			std::cout << std::endl;

			if (turn_count % 2 == 0) {
				setPosition(player_move, SquareType::Player1);
			}
			else {
				setPosition(player_move, SquareType::Player2);
			}

			turn_count++;
		}

	private:
		SquareType arr_[3][3];
		int turn_count;
};

int main () {
	TTT t;

	while(!t.isGameOver()) {
		t.takeTurn();
	}

	t.printBoard();

	return 0;
}