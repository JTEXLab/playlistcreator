// linked.cpp
#include "linked.h"

// Add a new song to the playlist
void Playlist::addSong(std::string title, std::string singer, int year, int duration, bool toEnd) {
    Song* newSong = new Song(title, singer, year, duration);
    if (head == nullptr) {  // Playlist is empty
        head = tail = current = newSong;
    } else if (toEnd) {  //End
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    } else {  // Beginning
        newSong->next = head;
        head->prev = newSong;
        head = newSong;
    }
}

// Move to the next song
void Playlist::moveNext() {
    if (current != nullptr && current->next != nullptr) {
        current = current->next;
    } else {
        std::cout << "You're at the last song!" << std::endl;
    }
}

// Move to the previous song
void Playlist::movePrevious() {
    if (current != nullptr && current->prev != nullptr) {
        current = current->prev;
    } else {
        std::cout << "You're at the first song!" << std::endl;
    }
}

// Remove the current song
void Playlist::removeCurrentSong() {
    if (current == nullptr) return;  // No song to remove

    if (current == head && current == tail) {  // Only one song in the playlist
        delete current;
        head = tail = current = nullptr;
    } else if (current == head) {  // Removing the first song
        head = head->next;
        head->prev = nullptr;
        delete current;
        current = head;
    } else if (current == tail) {  // Removing the last song
        tail = tail->prev;
        tail->next = nullptr;
        delete current;
        current = tail;
    } else {  // Removing a middle song
        current->prev->next = current->next;
        current->next->prev = current->prev;
        Song* temp = current->next;
        delete current;
        current = temp;
    }
}

// Print the current song's details
void Playlist::printCurrentSong() {
    if (current != nullptr) {
        std::cout << "Current Song: \"" << current->title << "\", " 
                  << current->singer << ", " << current->year << std::endl;
    } else {
        std::cout << "No songs in the playlist." << std::endl;
    }
}

// Search for a song by title and set it as the current song
bool Playlist::searchSong(std::string title) {
    Song* temp = head;
    while (temp != nullptr) {
        if (temp->title == title) {
            current = temp;
            std::cout << "Song Found: \"" << current->title << "\", "
                      << current->singer << ", " << current->duration << " seconds" << std::endl;
            return true;
        }
        temp = temp->next;
    }
    std::cout << "Song not found." << std::endl;
    return false;
}

// Print the entire playlist
void Playlist::printPlaylist() {
    Song* temp = head;
    while (temp != nullptr) {
        std::cout << "\"" << temp->title << "\", " << temp->singer << ", " 
                  << temp->year << std::endl;
        temp = temp->next;
    }
}

// Destructor to clean up the playlist and free memory
Playlist::~Playlist() {
    while (head != nullptr) {
        Song* temp = head;
        head = head->next;
        delete temp;
    }
}
