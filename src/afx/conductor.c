#include "conductor.h"
#include "../state.h"

struct Conductor {
    float bpm; // bpm of song
    float crochet; // time duration of a beat, calc from bpm
    float songposition; 
    float offset; // positive by convention, will be subtracted
    int beatnumber;
    
};