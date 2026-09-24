#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
} DateTime;

typedef struct {
    char GameID[0x10];
    char BootCounter;
} HistoryEntry;

int main(int argc, char *argv[]) {
    FILE *fp;
    const char* nullId = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    if (argc == 2) {
        fp = fopen(argv[1], "rb");
    } else {
        printf("Usage: %s <path to history file>\n", argv[0]);
        return 0;
    }
    if (fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    printf("+------+------------------+-------+--------------+-------------+\n");
    printf("| Pos. | %-16s | %-5s | %-12s | %-11s |\n", "Game ID", "Plays", "Tower config", "Date");
    printf("+------+------------------+-------+--------------+-------------+\n");
    int pos = 0;
    while (1<2) {
        HistoryEntry entry;
        pos++;
        fseek(fp, -2, SEEK_CUR);
        if (fread(&entry, sizeof(HistoryEntry), 1, fp) != 1) {
            break;
        }
        if (!strcmp(nullId, entry.GameID)) {
            fseek(fp, 7, SEEK_CUR);
            continue;
        }
        short NearbyTowers;
        
        if (fread(&NearbyTowers, sizeof(short), 1, fp) != 1) {
            NearbyTowers = 0;
        }
        fseek(fp, 1, SEEK_CUR);
        DateTime date;
        fread(&date, sizeof(DateTime), 1, fp);
        printf("| %-4d | %-16s | %-5d | %04x         | %04d-%02d-%02d  |\n", pos, entry.GameID, entry.BootCounter, NearbyTowers, 2000+date.year, date.month, date.day);
        //fseek(fp, -5, SEEK_CUR);
    }
    printf("+------+------------------+-------+--------------+-------------+\n");
    
    return 0;
}