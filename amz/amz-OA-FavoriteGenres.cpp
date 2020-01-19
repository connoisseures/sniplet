#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;

/*
Thought:
We use a hash map to record the genre of each song. 
Then, we prepare another hash table to record the count of each genre for each user by checking each user's favorite songs. 
At the same time, we also record the maximum of each user's genre.  
Finally, for each user, we find the count of the genre which is equal to the maximum of each user's genre.

Time complexity : O(S), where S is the total number of all user's favorite songs.
*/

unordered_map<string, vector<string>> genGenre(unordered_map<string, vector<string>> &users, unordered_map<string, vector<string>> &genres) {
    unordered_map<string, string> song_genre;
    //T: all songs : S
    for (auto it = genres.begin(); it != genres.end(); ++it) {
        string genre = it->first;
        vector<string> sg = it->second;
        for (auto s : sg) {
            song_genre[s] = genre;
        }
    }
    //T: all songs in all users : S
    unordered_map<string, unordered_map<string, int>> usr_genre_cnt;
    unordered_map<string, int> usr_max;
    for (auto it = users.begin(); it != users.end(); ++it) {
        string usr = it->first;
        vector<string> songs = it->second;
        usr_max[usr] = 0;
        for (auto s : songs) {
            if (song_genre.find(s) != song_genre.end()) {
                usr_genre_cnt[usr][song_genre[s]]++;
                usr_max[usr] = max(usr_max[usr], usr_genre_cnt[usr][song_genre[s]]);
            }
        }
    }
    unordered_map<string, vector<string>> usr_fav;
    for (auto it = users.begin(); it != users.end(); ++it) {
        string usr = it->first;
        usr_fav[usr] = vector<string> ();
    }
    //T: all genre in all users
    for (auto it = usr_genre_cnt.begin(); it != usr_genre_cnt.end(); ++it) {
        string usr = it->first;
        unordered_map<string, int> genre_cnt = it->second;
        for (auto g : genre_cnt) {
            if (g.second == usr_max[usr]) {
                usr_fav[usr].push_back(g.first);
            }
        }
    }
    return usr_fav;
}

void print_map(unordered_map<string, vector<string>> &hmap) {
    for (auto h : hmap) {
        string usr = h.first;
        cout << usr << ":" << endl;
        vector<string> fav = h.second;
        for (auto f : fav) {
            cout << f << ","; 
        }
        cout << endl;
    }
}

int main() {
    unordered_map<string,vector<string>> users;
    users["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users["Emma"] = {"song5", "song6", "song7"};
    
    unordered_map<string,vector<string>> songs;
    songs["Rock"] = {"song1", "song3"};
    songs["Dubstep"] = {"song7"};
    songs["Techno"] = {"song2", "song4"};
    songs["Pop"] = {"song5", "song6"};
    songs["Jazz"] = {"song8", "song9"};
    songs["None"] = {};
    unordered_map<string, vector<string>> usr_fav;
    usr_fav = genGenre(users, songs);
    cout << "case1" << endl;
    print_map(usr_fav);

    cout << "case2" << endl;
    unordered_map<string,vector<string>> songs1;
    unordered_map<string, vector<string>> usr_fav1;
    usr_fav1 = genGenre(users, songs1);
    print_map(usr_fav1);

    cout << "case3" << endl;
    unordered_map<string,vector<string>> users3;
    users3["David"] = {"song1", "song2", "song3", "song4", "song8"};
    users3["Emma"] = {"song5", "song6", "song7"};
    users3["Tom"] = {};
    unordered_map<string, vector<string>> usr_fav3;
    usr_fav3 = genGenre(users3, songs);
    print_map(usr_fav3);

}
