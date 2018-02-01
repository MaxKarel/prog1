#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct player {
  /* struct describing one player, with position of all his pieces and
  methods:
    * constructor player(int F, int position):
      * Initialize player > set position of all pieces to -1(home)
    * print_state():
      * self explanatory
    * move()
    * remove_fig();
      * Change position of piece standing on pos_of_removed to home
    * finish():
      * Change position of piece i to finish(-2)
    * deploy():
      * put new piece onto starting position
  */
  int h_pos, F, player_start_pos, player_end_pos;
  vector<int> f_pos;
  void print_state() {
    cout << " hrac " << h_pos << ":";
    for (int i = 0; i < F; i++) {
      cout << " figurka " << i;
      if (f_pos[i] == -1) {
        cout << " mimo";
      } else if (f_pos[i] == -2) {
        cout << " skoncila";
      } else {
        cout << " na policku " << f_pos[i];
      }
      if (i != F - 1)
        cout << ",";
    }
    cout << endl;
  }
  player(int F, int position) {
    this->F = F;
    this->h_pos = position;
    for (int i = 0; i < F; i++) {
      f_pos.push_back(-1);
    }
  }
  void move(int end, int i) {
    cout << " posun figurky " << i << " hraca " << h_pos << " na policko "
         << end << endl;
    f_pos[i] = end;
  }
  void remove_fig(int pos_of_removed) {
    for (int i = 0; i < F; i++) {
      if (pos_of_removed == f_pos[i]) {
        cout << " vyhodena figurka " << i << " hraca " << h_pos << endl;
        f_pos[i] = -1;
        break;
      }
    }
  }
  void deploy(int *end, int i, vector<int> &game_plan,
              vector<player> &players) {
    *end = player_start_pos;
    cout << " start figurky " << i << " hraca " << h_pos << " na policku "
         << player_start_pos << endl;
    if (game_plan[*end] != -1)
      players[game_plan[*end]].remove_fig(*end);
    f_pos[i] = player_start_pos;
  }
  void finish(int i) {
    f_pos[i] = -2;
    cout << " figurka " << i << " hraca " << h_pos << " dosiahla ciel" << endl;
  }
};

struct game {
  int H, N, F;
  int active_player;
  size_t size = 0;
  vector<player> players;
  vector<int> game_plan;
  bool init_game(int H, int N, int F) {
    /* Init game
      crete vectors
    */
    this->H = H;
    this->N = N;
    this->F = F;
    this->active_player = 0;
    this->game_plan.assign(N, -1);
    for (int i = 0; i < H; i++) {
      players.push_back(player(F, i));
      scanf("%*s %*d %*s %d %*s %d", &players[i].player_start_pos,
            &players[i].player_end_pos);
    }
    return true;
  }
  void turn(int dice, int i) {
    int current, end; // starting and finishing position of pieces
    bool move = true;
    cout << "hrac " << active_player << " hodil " << dice << endl;
    current = (i == -1) ? -1 : players[active_player].f_pos[i];
    end = (current + dice) % N;
    if ((current == -1) && (dice == 6)) {
      players[active_player].deploy(&end, i, game_plan, players);
      game_plan[end] = active_player;
      move = false;
    }
    if (move && i != -1) {
      game_plan[current] = -1;
      players[active_player].move(end, i);
      if (game_plan[end] != -1)
        players[game_plan[end]].remove_fig(end);
      game_plan[end] = active_player;
    }
    if (end == players[active_player].player_end_pos && i != -1) {
      game_plan[current] = -1;
      players[active_player].finish(i);
      game_plan[end] = -1;
      move = false;
    }
  }
  void start() {
    /*
    This is core function of the game:
      * Manages input, who is active player and interprets commands
    */
    int figure, dice;
    string command;
    // canf("%s %d %d", &command, &a, &b);
    cin >> command;
    while (command != "koniec") {
      if (command.compare("vypis") == 0) {
        cout << "stav hry:" << endl;
        for (int i = 0; i < H; i++) {
          players[i].print_state();
        }
      } else if (command.compare("tah") == 0) {
        cin >> dice >> figure;
        turn(dice, figure);
        active_player++;
        if (active_player == H)
          active_player = 0;
      }
      cin >> command;
    }
  }
};

int main() {
  int H, N, F;
  game Game; // crete object Game
  scanf("%*s %d %*s %d %*s %d", &H, &N, &F);
  if (Game.init_game(H, N, F)) {
    Game.start();
  }

  return 0;
}
