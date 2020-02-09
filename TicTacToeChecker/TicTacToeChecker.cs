// Link on task -> https://www.codewars.com/kata/525caa5c1bf619d28c000335
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TicTacToeChecker
{
    class TicTacToeChecker
    {
        public static bool IsWinSituation(int boardSquare1, int boardSquare2, int boardSquare3)
        {
            bool equalityOfElements = boardSquare1 == boardSquare2 && boardSquare2 == boardSquare3;
            return equalityOfElements && (boardSquare1 != 0);
        }

        public static int IsSolved(int[,] board)
        {
            for (int i = 0; i < 3; i++)
            {
                if (IsWinSituation(board[i, 0], board[i, 1], board[i, 2]))
                    return board[i, 0];

                if (IsWinSituation(board[0, i], board[1, i], board[2, i]))
                    return board[0, i];
            }

            if (IsWinSituation(board[0, 0], board[1, 1], board[2, 2]))
                return board[0, 0];

            if (IsWinSituation(board[0, 2], board[1, 1], board[2, 0]))
                return board[0, 2];

            for (int i = 0; i < 3; i++)
            {
                if (board[i, 0] == 0 || board[i, 1] == 0 || board[i, 2] == 0)
                {
                    return -1;
                }
            }

            return 0;
        }

        public static int Main()
        {
            // Test case from Codewars
            int[,] board = new int[,] { { 1, 1, 1 }, { 0, 2, 2 }, { 0, 0, 0 } };
            Console.WriteLine($"First test -> {IsSolved(board) == 1}");
            return 0;
        }
    }
}
