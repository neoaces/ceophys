#include "force.h"
#include <neolog.h>

LOGGER_CONFIG config = {DEBUG, "neolib::force"};

void apply_f(force_t* force) {
    for (int i = 0; i < force->n_affected; i++) {
        float deltaf = force->f(force->affected[i]);
        force->affected[i]->f += deltaf;
    }
} 

float force_gravity(particle_t* particle) {
    float val = particle->mass * G;
    return particle->mass * G;
}