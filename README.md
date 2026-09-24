# PlayStation 2 history file viewer

On (almost) every PlayStation 2 memory card, there is a save file called "Your System Configuration". Despite the name, it doesn't actually display any of the system settings, but what it instead stores is the history of games you have played for setting up the towers you see at the very beginning of the console startup process.

This tool allows you to list the games that your console has been logging, including the Game IDs, play counts, tower configuration data and the date the game was last booted, which get displayed as a neat table.

## Compilation

This program was designed to be compiled with GCC compiler. Other compilers are untested.

Command: `gcc main.c -o main`

## Usage

The history file is located inside the B?DATA-SYSTEM save directory (the ? is a character that depends on the console region).

On physical console, you can copy this file to a USB drive using homebrew, such as wLaunchELF.

On PCSX2 emulator, you need to have a memory card setup as a folder or convert the .ps2 file into a folder in memory card settings. The memory cards are accessible from the PCSX2 data directory (Tools -> Open Data Directory -> memcards).

Once you have the file, you can pass it as the first argument to this program. For example, if you compiled the program with the command above, you should run `./main <path to history file>` with the actual path.

If done correctly, you should see a table that looks similar to this:

```
+------+------------------+-------+--------------+-------------+
| Pos. | Game ID          | Plays | Tower config | Date        |
+------+------------------+-------+--------------+-------------+
| 1    | SLES_545.84      | 1     | 0001         | 2019-06-23  |
| 4    | SLES_520.65      | 6     | 0001         | 2026-07-16  |
| 5    | SLES_541.79      | 1     | 0001         | 2019-07-01  |
| 6    | SLES_550.25      | 6     | 0001         | 2019-06-30  |
| 8    | SLES_532.36      | 1     | 0001         | 2019-07-01  |
| 9    | SCES_507.81      | 1     | 0001         | 2019-06-20  |
| 11   | SCES_517.19      | 1     | 0001         | 2019-06-20  |
| 12   | SLES_552.18      | 2     | 0001         | 2024-06-19  |
| 13   | SLES_525.59      | 1     | 0001         | 2019-06-23  |
| 14   | SCES_508.78      | 2     | 0001         | 2019-06-23  |
| 15   | SLES_535.51      | 1     | 0001         | 2019-06-23  |
| 17   | SLES_534.61      | 4     | 0001         | 2019-06-26  |
| 18   | SLES_517.41      | 2     | 0001         | 2019-06-20  |
| 19   | SLES_535.57      | 1     | 0001         | 2019-06-27  |
| 21   | SLUS_208.55      | 3     | 0001         | 2019-06-13  |
+------+------------------+-------+--------------+-------------+
```