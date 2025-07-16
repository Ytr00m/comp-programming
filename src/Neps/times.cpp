#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MAXT = 1000;
int N;
int T;

int main() {
    vector<string> teams[MAXT];
    vector< pair<int, string> > players;
    cin >> N;
    cin >> T;

    for (int i = 0; i < N; i++)
    {
        string player;
        int hability;

        cin >> player;
        cin >> hability;

        players.push_back({hability, player});
        
    }

    sort(players.begin(), players.end());

    int players_size = (int)players.size();

    for (int i = 0; i < players_size; i++)
    {

        pair<int, string> picked_player = players[players_size - i - 1];
        players.pop_back();

        int team = i % T;
        teams[team].push_back(picked_player.second);

    }
    
    
    for (int i = 0; i < T; i++)
    {
        vector<string> actual_team = teams[i];
        cout << "Time " << i+1 << endl;
        sort(actual_team.begin(), actual_team.end());

        for (int j = 0; j < (int)actual_team.size(); j++)
        {
            cout << actual_team[j] << endl;
        }

        cout << endl;
        
    }

}