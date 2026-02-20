#include <stdio.h>

struct Sensordata {
    float time;
    double probability;
};

struct Sensor {
    int id;
    double threshold;
    struct Sensordata data[3000];
    int object_detection[3000];
};

int read_sensors(struct Sensor* s, const char* filename) {

    FILE *f = fopen(filename, "r");
    if (!f) {
        printf("Fehler beim Öffnen der Datei\n");
        return 1;
    }

    for (int i = 0; i < 3000; i++) {
        fscanf(f, "%f %lf", &s->data[i].time, &s->data[i].probability);
    }

    fclose(f);
    return 0;
}

void binary_detection_signal(struct Sensor* s) {
    int detection = 0;
    float start_time = 0;
    float end_time = 0;
    float threshold = s->threshold;

    printf("Sensor detection %d:\n", s->id);

    for (int i = 0; i < 3000; i++) {

        s->object_detection[i] = (s->data[i].probability >= threshold) ? 1 : 0;

        if (s->object_detection[i] == 1 && detection == 0) {
            detection = 1;
            start_time = s->data[i].time;
        }

        if (s->object_detection[i] == 0 && detection == 1) {
            detection = 0;
            end_time = (i > 0) ? s->data[i-1].time : s->data[i].time;
            printf("Start: %.2f s End: %.2f s\n", start_time, end_time);
        }
    }

    if (detection == 1) {
        end_time = s->data[2999].time;
        printf("Start: %.2f s End: %.2f s\n", start_time, end_time);
    }
}

void fused_sensor_detection(struct Sensor* s1, struct Sensor* s2) {
    int detection = 0;
    float start_time = 0;
    float end_time = 0;

    printf("Fused detection:\n");

    for (int i = 0; i < 3000; i++) {

        int fused = (s1->object_detection[i] == 1) && (s2->object_detection[i] == 1);

        if (fused == 1 && detection == 0) {
            detection = 1;
            start_time = s1->data[i].time;
        }

        if (fused == 0 && detection == 1) {
            detection = 0;
            end_time = (i > 0) ? s1->data[i-1].time : s1->data[i].time;
            printf("Start: %.2f s End: %.2f s\n", start_time, end_time);
        }
    }

    if (detection == 1) {
        end_time = s1->data[2999].time;
        printf("Start: %.2f s End: %.2f s\n", start_time, end_time);
    }
}

int main() {

    struct Sensor sensor1;
    sensor1.id = 1;
    sensor1.threshold = 0.8;

    read_sensors(&sensor1, "sensor1.txt");
    binary_detection_signal(&sensor1);

    struct Sensor sensor2;
    sensor2.id = 2;
    sensor2.threshold = 0.7;

    read_sensors(&sensor2, "sensor2.txt");
    binary_detection_signal(&sensor2);

    fused_sensor_detection(&sensor1, &sensor2);

    return 0;
}