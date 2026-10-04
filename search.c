#include <stdio.h>
#include <string.h>
#include "search.h"

void searchCandidate(void)
{
    int id;
    int found = 0;
    Candidate *current = candidateHead;

    printf("\n========== SEARCH CANDIDATE ==========\n");
    printf("Enter Candidate ID: ");
    scanf("%d", &id);

    while (current != NULL)
    {
        if (current->candidateId == id)
        {
            printf("\nCandidate Found!\n");
            printf("Candidate ID  : %d\n", current->candidateId);
            printf("Name          : %s\n", current->name);
            printf("Qualification : %s\n", current->qualification);
            printf("Skills        : %s\n", current->skills);
            printf("Experience    : %.1f years\n", current->experience);

            found = 1;
            break;
        }

        current = current->next;
    }

    if (!found)
        printf("\nCandidate not found!\n");
}

void searchBySkill(void)
{
    char skill[50];
    int found = 0;
    Candidate *current = candidateHead;

    printf("\n========== SEARCH BY SKILL ==========\n");
    printf("Enter Skill: ");
    scanf("%49s", skill);

    while (current != NULL)
    {
        if (strstr(current->skills, skill) != NULL)
        {
            printf("\nCandidate ID : %d", current->candidateId);
            printf("\nName         : %s", current->name);
            printf("\nSkills       : %s", current->skills);
            printf("\nExperience   : %.1f years\n", current->experience);
            printf("----------------------------------------\n");

            found = 1;
        }

        current = current->next;
    }

    if (!found)
        printf("\nNo candidates found with this skill.\n");
}

float calculateScore(Candidate *candidate, Job *job)
{
    float score = 0;

    /* Skill matching = 70 marks */
    if (strstr(candidate->skills, job->requiredSkills) != NULL)
        score = score + 70;

    /* Experience matching = 30 marks */
    if (candidate->experience >= job->requiredExperience)
        score = score + 30;

    return score;
}
