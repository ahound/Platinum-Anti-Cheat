# Platinum-Anti-Cheat
I'm working on an anti cheat as a project and a hobby for C++. I'm looking to potentially use this as a foundation for any future projects I do, hopefully helping my knowledge by alot.




![logo](https://user-images.githubusercontent.com/59074683/163672263-8aca5bab-94e6-42c2-88c6-68f0174cb6c1.png)

Over the past almost year, I've been coding cheats for plenty of games, some unsuccessful and some very successful. However interesting it is for me, it got to a point where its basically the same thing for every game. Read and Write memory, with some data encryption on functions and strings, even fucking drivers which is a really insane level but I did manage to make some undetected apex legends and rainbow six siege hacks using a driver. So why do I create an ant cheat? Simply because I've got nothing else to do and over the months i've cheated and coded them, It's annoying to encount cheaters and I only have just realised the real pestilence of cheaters and how badly they effect both population but also opinions about the game. Take for example CSGO. It has the shittest anti cheat i've ever known to man, even roblox anti cheats go far more advanced than shitty vac, but its not that. CSGO is one of, if not the most popular strategy fps games for free on steam. It's so successful but over the decade and more that its been out, it's repuation for security over hackers is tremendously unfortunate and has lost alot of it's players.

What you will find inside this repository is a currently functional string anti cheat. Basically, it searches the desired destination, whether it is the entire C drive or a specific folder, and scans the entire binary code of the file, pretty much just opening it up in notepad. It searches for blacklisted strings, in other words, any functions / strings that modify memory of a game and the games process name, window etc. 

I'm going to add:
  - Memory Scanning (I don't think i've ever seen this in an anti cheat) - It's functionality will basically react to a string that is found and make sure memory is how     it should be in the game (hopefully)
  - Neaten the code
  - Signature Scanning
