#include <stdio.h>
#include "candidate.h"
#include "job.h"
#include "search.h"
#include "shortlist.h"

/*
   Shortlisting is based on the same matching score used by ranking.
   A candidate with score >= 70% is displayed as shortlisted.
*/
void shortlistedCandidates(void)
{
    Candidate *current = candidateHead;
    int found = 0;

    printf("\n========== SHORTLISTED CANDIDATES ==========\n");

    if (candidateHead == NULL)
    {
        printf("\nNo candidates available.\n");
        return;
    }

    if (jobHead == NULL)
    {
        printf("\nNo job available for shortlisting.\n");
        return;
    }

    while (current != NULL)
    {
        float score = calculateScore(current, jobHead);

        if (score >= 70)
        {
            printf("\nCandidate ID : %d", current->candidateId);
            printf("\nName         : %s", current->name);
            printf("\nSkills       : %s", current->skills);
            printf("\nExperience   : %.1f years", current->experience);
            printf("\nScore        : %.2f%%\n", score);
            printf("----------------------------------------\n");

            found = 1;
        }

        current = current->next;
    }

    if (!found)
        printf("\nNo candidates qualified for shortlisting.\n");
}
