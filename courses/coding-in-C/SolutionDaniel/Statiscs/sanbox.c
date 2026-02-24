#include <stdio.h>
#include <stdlib.h>

void writeCSV() {
    FILE *fp = fopen("daten.csv", "w");

    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei!\n");
        return;
    }

    // Sauber ausgerichtete Spalten
    fprintf(fp, "%-5s %-15s %-15s %-5s\n", "ID", "Vorname", "Nachname", "Alter");
    fprintf(fp, "%-5d %-15s %-15s %-5d\n", 1, "Max", "Mustermann", 30);
    fprintf(fp, "%-5d %-15s %-15s %-5d\n", 2, "Erika", "Musterfrau", 25);

    fclose(fp);
    printf("CSV-Datei erfolgreich erstellt.\n");
}

void readCSV() {
    FILE *fp = fopen("daten.csv", "r");

    if (fp == NULL) {
        printf("Fehler beim Lesen der Datei!\n");
        return;
    }

    char line[200];

    printf("\n--- Inhalt der CSV-Datei ---\n");

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }

    fclose(fp);
}

int main() {
    writeCSV();   // CSV schreiben
    readCSV();    // CSV wieder auslesen und anzeigen

    return 0;
}