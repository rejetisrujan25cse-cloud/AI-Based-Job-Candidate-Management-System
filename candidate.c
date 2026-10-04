#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "candidate.h"

Candidate *candidateHead = NULL;

void registerCandidate(void)
{
    Candidate *newCandidate;
    Candidate *temp;

    newCandidate = (Candidate *)malloc(sizeof(Candidate));

    if (newCandidate == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\n========== CANDIDATE REGISTRATION ==========\n");

    printf("Enter Candidate ID: ");
    scanf("%d", &newCandidate->candidateId);
    getchar();

    printf("Enter Candidate Name: ");
    fgets(newCandidate->name, sizeof(newCandidate->name), stdin);
    newCandidate->name[strcspn(newCandidate->name, "\n")] = '\0';

    printf("Enter Qualification: ");
    fgets(newCandidate->qualification,
          sizeof(newCandidate->qualification), stdin);
    newCandidate->qualification[strcspn(newCandidate->qualification, "\n")] = '\0';

    printf("Enter Skills: ");
    fgets(newCandidate->skills,
          sizeof(newCandidate->skills), stdin);
    newCandidate->skills[strcspn(newCandidate->skills, "\n")] = '\0';

    printf("Enter Experience in years: ");
    scanf("%f", &newCandidate->experience);

    newCandidate->next = NULL;

    if (candidateHead == NULL)
    {
        candidateHead = newCandidate;
    }
    else
    {
        temp = candidateHead;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newCandidate;
    }

    printf("\nCandidate registered successfully!\n");
}

void displayCandidates(void)
{
    Candidate *current = candidateHead;

    if (current == NULL)
    {
        printf("\nNo candidate records available.\n");
        return;
    }

    printf("\n========== CANDIDATE DETAILS ==========\n");

    while (current != NULL)
    {
        printf("\nCandidate ID  : %d", current->candidateId);
        printf("\nName          : %s", current->name);
        printf("\nQualification : %s", current->qualification);
        printf("\nSkills        : %s", current->skills);
        printf("\nExperience    : %.1f years\n", current->experience);
        printf("----------------------------------------\n");

        current = current->next;
    }
}
