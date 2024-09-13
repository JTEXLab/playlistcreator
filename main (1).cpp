// playlist.cpp
#include "linked.h"
#include <iostream>

int main() {
    Playlist playlist;
    int choice;
    std::string title, singer;
    int year, duration;

    do {
        playlist.printCurrentSong();
        std::cout << "  Next Song (1)\n"
                  << "  Previous Song (2)\n"
                  << "  Search (3)\n"
                  << "  Add song (4)\n"
                  << "  Remove song (5)\n"
                  << "  Print playlist (6)\n"
                  << "  Exit (7)\n";
        std::cin >> choice;

        switch (choice) {
            case 1:
                playlist.moveNext();
                break;
            case 2:
                playlist.movePrevious();
                break;
            case 3:
                std::cout << "Enter song title to search: ";
                std::cin.ignore();  // To clear the newline character from the input buffer
                std::getline(std::cin, title);
                playlist.searchSong(title);
                break;
            case 4:
                std::cout << "Enter song title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter singer/band: ";
                std::getline(std::cin, singer);
                std::cout << "Enter release year: ";
                std::cin >> year;
                std::cout << "Enter duration (in seconds): ";
                std::cin >> duration;
                std::cout << "Add to end? (1 for yes, 0 for no): ";
                int toEnd;
                std::cin >> toEnd;
                playlist.addSong(title, singer, year, duration, toEnd);
                break;
            case 5:
                playlist.removeCurrentSong();
                break;
            case 6:
                playlist.printPlaylist();
                break;
            case 7:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 7);

    return 0;
}
