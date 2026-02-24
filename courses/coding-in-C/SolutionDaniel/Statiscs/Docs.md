1.Kurzbeschreibeung
Das Modul soll mit den werten aus anderen Modulen eine schöne ausgabe nach jeden timestep
 mit dem relevanten Daten machen und diese auch in ein Text dokument speichern. Ebenso soll nach dem alle timestep 
 vollendet sind eine Gesamt Statisktik ausgegeben werden. Es wird auf die in den Issue benannten in im Gemeinsamen Gespräch vom 19.2 eingagengen 
 Statsiken bearbeitet und Umgesetzt.

2. Datenstruckturen
Variable / Objekt       | Typ	   | Beschreibung & Anmerkungen
------------------------|--------|---------------------------------------------------------------------------------------------------------
timestep                |float	| Für Ausgabe in der Konsole Relevant um die Ausgaben einodrnen zu können
capacity	               |int	   | Für Berechungen des Prozentsatzes wie voll das Parkhaus ist 
ingoing_cars            |int     | Um die ingoing_cars zu jedem timestep zu erfassen und zur Berechung der Dudurchschnittlichen Wartezeit
outgoing_cars           |int     | Um die outgoing_cars zu jedem timestep zu erfassen und zur Berechung der Durchscnitllichen Parkzeit
waiting_cars            |int     | Um die Warteschlangen laenge Auszugeben
full_waitingtime        |float   | Für die durchnittliche Wartezeit berechnung
full_parkingtime        |float   | Für die durchschnittliche Wartezeit Berechung
cars_parked             |int     | Für die Ausgabe und Berechung wie voll Das Parkhaus ist in %

3.Funktionen 

3.1.1 Spezifikationen
/**
 * @brief  Berechnet und gibt die Parkhaus-Statistik für einen timestep aus.
 *
 * Prüft Eingabeparameter auf Gültigkeit, aktualisiert die Anzahl der Autos im
 * Parkhaus (int, zwischen Aufrufen beibehaltener Zustand), berechnet
 * Auslastung, durchschnittliche Park- und Wartezeiten und gibt formatiert die Statistik aus.
 *
 * @param[in]  timestep          Aktueller timestep der Simulation.
 * @param[in]  capacity          Maximale Anzahl Stellplätze (muss > 0).
 * @param[in]  ingoing_cars      Anzahl hereinfahrender Fahrzeuge (muss >= 0).
 * @param[in]  outgoing_cars     Anzahl ausfahrender Fahrzeuge (muss >= 0).
 * @param[in]  waiting_cars      Anzahl Fahrzeuge in der dynamischen waiting_cars (muss >= 0).
 * @param[in]  full_waitingtime  Summe aller Wartezeiten seit Beginn (Zeitschritte muss >= 0).
 * @param[in]  full_parkingtime  Summe aller Parkdauern seit Beginn (Zeitschritte muss >= 0).
 *
 * @note  Die Funktion verwaltet intern eine Variable `cars_parked`,
 *        die ihren Wert zwischen Aufrufen behält. Bei Berechnungen wird
 *        negatives Ergebnis auf 0 korrigiert und eine Fehlermeldung ausgegeben.
 *
 * @return void  Gibt die Statistik direkt auf der Konsole/Log aus.
 */

3.1.2 Pseudocode: Parkhaus-Statistik 

Function calculate_statiscs (timestep, capacity, ingoing_cars, outgoing_cars, waiting_cars, full_waitingtime, full_parkingtime)

INPUT cars_parked (behält ihren Wert zwischen den Aufrufen)

Fehlerprüfung (Validierung)
IF capacity kleiner als 0 THEN Fehlermeldung ausgeben und abbrechen
IF ingoing_cars oder outgoing_cars kleiner als 0 THEN Fehlermeldung ausgeben und abbrechen
IF waiting_cars oder Zeitdauern kleiner als 0 THEN Fehlermeldung ausgeben und abbrechen

cars_parked = (Alter Bestand der Autos) + (ingoing_cars) - (outgoing_cars)
IF das Ergebnis negativ ist THEN korrigiere es auf 0 und gebe Fehlermeldung aus

Auslastung
Berechne den Prozentsatz (cars_parked \ capacity)*100 (für Prozent)
Durchschnittliche Parkdauer:IF outgoing_cars > 0 THEN full_parkingtime geteilt durch outgoing_cars ELSE setze auf  0
Durchschnittliche Wartezeit:IF ingoing_cars > 0 THEN full_waitingtime geteilt durch ingoing_cars ELSE setzte auf 0 

OUTPUT timestep, capacity, ingoing_cars, outgoing_cars, waiting_cars, full_waitingtime, full_parkingtime in eine .csv Datei mit Namen Statistik.csv

Konsolen Ausgaben 
OUTPUT Trennbalken
OUTPUT timestep 
OUTPUT Trennbalken
OUTPUT ingoing_cars, outgoing_cars
OUTPUT Trennbalken
OUTPUT Autos im Parkhaus, capacity, Prozentzahl 
OUTPUT waiting_cars 
OUTPUT Trennbalken
OUTPUT Durchscnittliche Parkdauer, Durchschnittliche Wartedauer
OUTPUT Trennbalken

END OF FUNCTION

3.1.3 Ausgabe 
============================================================
   PARKHAUS RAUENEGG  |  ZEITSCHRITT: 0045
============================================================

   AKTUELLE BEWEGUNG
   -----------------
   Einfahrten:      1
   Ausfahrten:      0

   BELEGUNG UND STATUS
   -------------------
   Autos im Haus:   25 / 50  (50.0%)
   Warteschlange:   4

   DURCHSCHNITTSWERTE
   ------------------
   Parkdauer:       124 Schritte
   Wartedauer:      12 Schritte

============================================================
Anmerkung: Werte sind nur eine Annahme und entsprechen keinen Werten in der Realität 

3.2.1 Spezifikationen
/**
 * @brief  Berechnet und gibt die Parkhaus-Statistik aus einer CSV-Datei aus.
 *
 * Liest die Datei mit dem Namen @p csv_path (im Format Statistik.csv) zeilenweise
 * ein, extrahiert die Werte pro Zeile und berechnet kumulierte Kennzahlen:
 * Gesamtanzahl hereinfahrender und ausfahrender Fahrzeuge, maximale Belegung,
 * durchschnittliche Auslastung in Prozent, durchschnittliche Warte- und Parkzeiten.
 *
 * Die Funktion prüft Eingabeparameter auf Gültigkeit, korrigiert negative
 * Zwischenergebnisse auf 0 und gibt bei Fehlern eine Fehlermeldung zurück.
 *
 * @param[in]  csv_path               Pfad zur CSV-Datei (muss nicht NULL sein).
 * @param[out] out_total_ingoing      Gesamtanzahl hereinfahrender Fahrzeuge.
 * @param[out] out_total_outgoing     Gesamtanzahl ausfahrender Fahrzeuge.
 * @param[out] out_max_occupancy      Maximale beobachtete Belegung (>= 0).
 * @param[out] out_avg_occupancy_pct  Durchschnittliche Auslastung in Prozent.
 * @param[out] out_avg_waiting        Durchschnittliche Wartezeit pro hereinfahrendem Fahrzeug.
 * @param[out] out_avg_parking        Durchschnittliche Parkdauer pro ausfahrendem Fahrzeug.
 * @param[out] out_row_count          Anzahl gelesener Zeilen (Datensätze).
 *
 * @note  Die Funktion verwaltet intern eine Variable `cars_parked`, die ihren
 *        Wert zwischen Aufrufen nicht beibehält (funktionaler, nicht persistenter Zustand).
 *        Bei Berechnungen wird ein negatives Ergebnis auf 0 korrigiert und
 *        ein Fehlercode zurückgegeben, falls die Eingabedatei nicht existiert
 *        oder das Dateiformat ungültig ist.
 *
 * @return int  Rückgabewert: 0 bei Erfolg, negativer Wert bei Fehlern
 **/

3.2.2. Pseudocode FUNCTION calculate_final_statistics 


INPUT total_ingoing = 0
INPUT total_outgoing = 0
INPUT max_occupancy = 0
INPUT sum_occupancy_percent = 0
INPUT sum_waiting_time = 0
INPUT sum_parking_time = 0
INPUT row_count = 0

OPEN Statistik.csv FOR READING
IF Datei nicht vorhanden THEN Fehlermeldung ausgeben und ABBRECHEN

WHILE NOT end of file DO
    READ line FROM Statistik.csv
    row_count = row_count + 1
    
    // Werte aus der CSV-Zeile extrahieren
    (ts, cap, in_c, out_c, wait_c, f_wait, f_park) = extrahiere_werte(line)
    
    total_ingoing = total_ingoing + in_c
    total_outgoing = total_outgoing + out_c
    sum_waiting_time = sum_waiting_time + f_wait
    sum_parking_time = sum_parking_time + f_park
    
    current_occupancy = (in_c - out_c) 
    IF current_occupancy > max_occupancy THEN max_occupancy = current_occupancy
    sum_occupancy_percent = sum_occupancy_percent + (current_occupancy / cap * 100)
END WHILE

CLOSE Statistik.csv

avg_waiting_overall = IF total_ingoing > 0 THEN sum_waiting_time / total_ingoing ELSE 0
avg_parking_overall = IF total_outgoing > 0 THEN sum_parking_time / total_outgoing ELSE 0
avg_occupancy_percent = IF row_count > 0 THEN sum_occupancy_percent / row_count ELSE 0

OUTPUT  total_ingoing
OUTPUT  total_outgoing
OUTPUT  max_occupancy
OUTPUT  avg_occupancy_percent
OUTPUT  avg_waiting_overall
OUTPUT  avg_parking_overall

END FUNCTION

4.Flowcharts
Siehe Ordner aller Flowcharts.

5. Module und Abhängigkeit
Libarys:
<stdio.h>
<stdlib.h>
<string.h>

Andere Module:
main.c //um werte für die Statsik zu bekommen

Anmerkung: Andere Module nicht direkt Relevant, da diese alle infos in die main.c zurückgegeben, daher sind andere Module nicht aufgeführt. 


