#include <cassert>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "NimMove.h"
#include "NimGame.h"

using namespace std;

int main() {
   cout << "*** Game of Nim ***" << endl;

   // read parameters of the game
   unsigned int number_of_heaps;
   cout << "Number of heaps: ";
   if (!(cin >> number_of_heaps) || number_of_heaps == 0) {
      cout << "Bye!" << endl; return 1;
   }
   unsigned int maxtake;
   cout << "Maximal number of sticks that can be taken in one move: ";
   if (!(cin >> maxtake)) {
      cout << "Bye!" << endl; return 1;
   }

   // seed pseudo random generator
   srand(getpid() ^ time(0));
   // setup game
   NimGame game(number_of_heaps, maxtake);
   unsigned int minsize; unsigned int maxsize;
   if (maxtake) {
      minsize = maxtake * 2; maxsize = maxtake * 4;
   } else {
      minsize = 1; maxsize = 7;
   }
   unsigned int range = maxsize - minsize + 1;
   for (unsigned int i = 0; i < number_of_heaps; ++i) {
      game.set_heap_size(i, rand() % range + minsize);
   }

   while (!game.finished()) {
      // print current state
      cout << "Heaps:";
      for (unsigned int i = 0; i < number_of_heaps; ++i) {
         cout << " " << game.get_heap_size(i);
      }
      cout << endl;
      NimMove move;
      if (game.get_next_player() == NimGame::PLAYER1) {
         // human player
         do {
            unsigned int heap_index; unsigned int count;
            cout << "Your move: ";
            if (!(cin >> heap_index >> count)) {
               cout << "Bye!" << endl; return 1;
            }
            move = NimMove(heap_index, count);
         } while (!game.valid_move(move));
      } else {
         // computer
         if (game.nim_value() == 0) {
            // bad luck
            for (unsigned int i = 0; i < number_of_heaps; ++i) {
               if (game.get_heap_size(i) > 0) {
                  move = NimMove(i, 1); break;
               }
            }
         } else {
            // find a winning move
            bool not_done = true;
            for (unsigned int heap_index=0; not_done && heap_index<game.get_number_of_heaps(); ++heap_index) {
                for (unsigned int count=1;
                     not_done
                     && count <= game.get_heap_size(heap_index)
                     && (maxtake==0 || count<=maxtake);
                     ++count) {
                   NimGame test = game; // make a copy of the current game
                   NimMove testmove(heap_index, count); // create a move
                   test.execute_move(testmove); // execute it
                   if (test.nim_value() == 0) {
                      move = testmove;
                      not_done = false;
                   }
                }
            }
            assert(!not_done);
         }
         cout << "Taking " << move.get_count() << " from heap "
            << move.get_heap() << endl;
      }
      game.execute_move(move);
   }
   switch (game.winner()) {
      case NimGame::PLAYER1: cout << "Congratulations!" << endl; break;
      case NimGame::PLAYER2: cout << "You lose!" << endl; break;
   }
}



