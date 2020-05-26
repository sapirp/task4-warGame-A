
#include <iostream>
#include <cassert>

#include "doctest.h"
#include "Board.hpp"
#include "Soldier.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

using namespace WarGame;
using namespace std;

TEST_CASE("Foot soldiers")
{
    Board board(8, 1);

    CHECK(!board.has_soldiers(1));
    board[{0, 0}] = new FootSoldier(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7, 0}] = new FootSoldier(2);
    CHECK(board.has_soldiers(2));

    CHECK_THROWS(board.move(1, {2, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location
    CHECK_THROWS(board.move(1, {1, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location!

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down);             // move back to {0,0} and shoot; damage 10
    CHECK_THROWS(board.move(1, {1, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location!
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 10
    CHECK(!board.has_soldiers(2));
}

TEST_CASE("Foot Commander")
{
    Board board(8, 1);

    CHECK(!board.has_soldiers(1));
    board[{0, 0}] = new FootCommander(1);
    CHECK(board.has_soldiers(1));
    CHECK(!board.has_soldiers(1));
    board[{7, 0}] = new FootCommander(2);
    CHECK(board.has_soldiers(2));

    CHECK_THROWS(board.move(1, {2, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location
    CHECK_THROWS(board.move(1, {1, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location!

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20
    CHECK(board.has_soldiers(2));

    board.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20
    CHECK(!board.has_soldiers(2));

    CHECK_THROWS(board.move(1, {2, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location
    CHECK_THROWS(board.move(1, {1, 0}, Board::MoveDIR::Up)); //There is no soldier in the source location!
}

TEST_CASE("test  adding soldiers")
{
    Board TestGame(8, 8);

    CHECK(!TestGame.has_soldiers(1));
    CHECK(!TestGame.has_soldiers(2));

    // Add soldiers for player 1:
    TestGame[{0, 1}] = new FootSoldier(1);
    TestGame[{0, 3}] = new FootCommander(1);
    TestGame[{0, 5}] = new FootSoldier(1);

    CHECK(TestGame.has_soldiers(1));
    CHECK(!TestGame.has_soldiers(2));

    // Add soldiers for player 2:
    assert(!TestGame.has_soldiers(2));
    TestGame[{7, 1}] = new FootSoldier(2);
    TestGame[{7, 3}] = new FootCommander(2);
    TestGame[{7, 5}] = new FootSoldier(2);

    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));
}

TEST_CASE("Game1: test  play & move")
{
    Board TestGame(5, 5);

    CHECK(!TestGame.has_soldiers(1));
    CHECK(!TestGame.has_soldiers(2));

    // Add soldiers for player 1:
    TestGame[{0, 0}] = new FootSoldier(1);
    TestGame[{0, 3}] = new FootCommander(1);
    TestGame[{0, 4}] = new FootSoldier(1);

    // Add soldiers for player 2:
    assert(!TestGame.has_soldiers(2));
    TestGame[{4, 0}] = new FootSoldier(2);
    TestGame[{4, 3}] = new FootCommander(2);
    TestGame[{4, 4}] = new FootSoldier(2);

    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(2, {3, 3}, Board::MoveDIR::Up)); //There is no soldier in the source location
    CHECK_THROWS(TestGame.move(2, {1, 0}, Board::MoveDIR::Up)); //The soldier in the source location belongs to the other player.

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 4}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 3}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(1, {0, 3}, Board::MoveDIR::Right)); //There is already another soldier (of this or the other player) in the target location.

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 3}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 3}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 3}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move back to {0,0} and shoot; damage 20+20
    CHECK(!TestGame.has_soldiers(2));
}

TEST_CASE("Game2: test  play & move")
{
    Board TestGame(3, 3);

    CHECK(!TestGame.has_soldiers(1));
    CHECK(!TestGame.has_soldiers(2));

    // Add soldiers for player 1:
    TestGame[{0, 0}] = new FootSoldier(1);
    TestGame[{0, 1}] = new FootCommander(1);
    TestGame[{0, 2}] = new FootSoldier(1);

    // Add soldiers for player 2:
    assert(!TestGame.has_soldiers(2));
    TestGame[{2, 0}] = new FootSoldier(2);
    TestGame[{2, 1}] = new FootSoldier(2);
    TestGame[{2, 2}] = new FootCommander(2);

    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(2, {1, 2}, Board::MoveDIR::Up)); //There is no soldier in the source location
    CHECK_THROWS(TestGame.move(2, {0, 1}, Board::MoveDIR::Up)); //The soldier in the source location belongs to the other player.

    TestGame.move(2, {2, 2}, Board::MoveDIR::Up); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 1}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(2, {2, 1}, Board::MoveDIR::Up)); //There is already another soldier (of this or the other player) in the target location.

    TestGame.move(2, {1, 2}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(1, {0, 3}, Board::MoveDIR::Right)); //There is already another soldier (of this or the other player) in the target location.

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 1}, Board::MoveDIR::Right); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {2, 1}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 2}, Board::MoveDIR::Left); // move back to {0,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(2, {2, 2}, Board::MoveDIR::Left); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 2}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(2, {1, 1}, Board::MoveDIR::Right); // move back to {0,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 0}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(2, {1, 2}, Board::MoveDIR::Up)); //There is no soldier in the source location
    CHECK_THROWS(TestGame.move(2, {0, 1}, Board::MoveDIR::Up)); //The soldier in the source location belongs to the other player.

    TestGame.move(2, {2, 2}, Board::MoveDIR::Up); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {0, 1}, Board::MoveDIR::Down); // move to {1,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(2, {1, 2}, Board::MoveDIR::Left)); //There is already another soldier (of this or the other player) in the target location.

    TestGame.move(2, {1, 2}, Board::MoveDIR::Up); // move back to {0,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    CHECK_THROWS(TestGame.move(1, {0, 3}, Board::MoveDIR::Right)); //There is already another soldier (of this or the other player) in the target location.

    TestGame.move(1, {0, 3}, Board::MoveDIR::Up); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {2, 2}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(2, {2, 1}, Board::MoveDIR::Left); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 0}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(2, {2, 2}, Board::MoveDIR::Right); // move to {1,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(1, {1, 2}, Board::MoveDIR::Down); // move back to {0,0} and shoot; damage 20+20
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));

    TestGame.move(2, {2, 0}, Board::MoveDIR::Up); // move back to {0,0} and shoot; damage 10
    CHECK(TestGame.has_soldiers(1));
    CHECK(TestGame.has_soldiers(2));
}