#ifndef SEARCH_H
#define SEARCH_H

#include "candidate.h"
#include "job.h"

void searchCandidate(void);
void searchBySkill(void);
float calculateScore(Candidate *candidate, Job *job);

#endif
