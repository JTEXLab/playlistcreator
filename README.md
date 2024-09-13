For this assignment we will be creating a program that manages a music playlist. The program should have the following functionality:

For each song it stores the title, singer/band, and release year (you may add additional fields, rating, genre, etc. if you like).
New songs can be added at the beginning or the end of the playlist. 
Users can search for a song by title, and it will return the singer/band and song duration.
Users can 'browse' through the playlist forward or backwards.
Users interface with the playlist through a menu that:
Prints the 'current' song.
Allows the user to enter a new song. This will need to ask the user if they want to add the song to the beginning or end of the list.
Allows the user to move to the next or previous song.
Allows the user to search for a song by title, printing additional information about the song, and moving the 'current song pointer' to the searched for song. (Prints a 'song not found' error message if the search fails.
Allows the user to print all songs. 
Allows the user to delete the current song from the list.
To make this work several things will be needed to be included in the code:

A node class that stores all three pieces of data (title, singer/band, duration) and has next and previous pointers.
A linked list class that includes three pointers: head (first song), tail (last song), and current (current song).
