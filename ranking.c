#include <stdio.h>
#include "candidate.h"
#include "job.h"
#include "search.h"
#include "ranking.h"

void candidateRanking(void)
{
    Candidate *current;
    Candidate *list[100];
    int count = 0;
    int i, j;

    printf("\n========== CANDIDATE RANKING ==========\n");

    if (candidateHead == NULL)
    {
        printf("\nNo candidates available.\n");
        return;
    }

    if (jobHead == NULL)
    {
        printf("\nNo job available for ranking.\n");
        return;
    }

    current = candidateHead;

    while (current != NULL && count < 100)
    {
        list[count] = current;
        count++;
        current = current->next;
    }

    /* Bubble Sort according to matching score */
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - i - 1; j++)
        {
            float score1 = calculateScore(list[j], jobHead);
            float score2 = calculateScore(list[j + 1], jobHead);

            if (score2 > score1)
            {
                Candidate *temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    printf("\nRanking for Job: %s\n", jobHead->jobTitle);
    printf("\n----------------------------------------\n");

    for (i = 0; i < count; i++)
    {
        printf("\nRank       : %d", i + 1);
        printf("\nCandidate  : %s", list[i]->name);
        printf("\nSkills     : %s", list[i]->skills);
        printf("\nExperience : %.1f years", list[i]->experience);
        printf("\nScore      : %.2f%%",
               calculateScore(list[i], jobHead));
        printf("\n----------------------------------------\n");
    }
}
