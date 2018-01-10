
bool compare(Player a, Player b) {
    if (a.score != b.score)
        return a.score > b.score;
    else 
        return a.name < b.name;
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), compare);
    return players;
}