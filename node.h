// node.h
#pragma once
#include <string>

class Song {
public:
    std::string title;
    std::string singer;
    int year;
    int duration;  
    Song* next;
    Song* prev;

    // Constructor to initialize the song node
    Song(std::string t, std::string s, int y, int d)
        : title(t), singer(s), year(y), duration(d), next(nullptr), prev(nullptr) {}
};
