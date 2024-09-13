// linked.h
#pragma once
#include "node.h"
#include <iostream>

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    // Constructor to initialize empty playlist
    Playlist() : head(nullptr), tail(nullptr), current(nullptr) {}

    // Add a new song to the beginning or end
    void addSong(std::string title, std::string singer, int year, int duration, bool toEnd);

    // Move to the next or previous song
    void moveNext();
    void movePrevious();

    // Remove the current song
    void removeCurrentSong();

    // Print the current song
    void printCurrentSong();

    // Search for a song by title
    bool searchSong(std::string title);

    // Print the entire playlist
    void printPlaylist();

    // Destructor to clean up the playlist
    ~Playlist();
};
