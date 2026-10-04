#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

Job *jobHead = NULL;

void registerJob(void)
{
    Job *newJob;
    Job *temp;

    newJob = (Job *)malloc(sizeof(Job));

    if (newJob == NULL)
    {
        printf("\nMemory allocation failed!\n");
        return;
    }

    printf("\n========== JOB REGISTRATION ==========\n");

    printf("Enter Job ID: ");
    scanf("%d", &newJob->jobId);
    getchar();

    printf("Enter Job Title: ");
    fgets(newJob->jobTitle, sizeof(newJob->jobTitle), stdin);
    newJob->jobTitle[strcspn(newJob->jobTitle, "\n")] = '\0';

    printf("Enter Required Skills: ");
    fgets(newJob->requiredSkills,
          sizeof(newJob->requiredSkills), stdin);
    newJob->requiredSkills[strcspn(newJob->requiredSkills, "\n")] = '\0';

    printf("Enter Required Experience in years: ");
    scanf("%f", &newJob->requiredExperience);

    newJob->next = NULL;

    if (jobHead == NULL)
    {
        jobHead = newJob;
    }
    else
    {
        temp = jobHead;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newJob;
    }

    printf("\nJob registered successfully!\n");
}

void displayJobs(void)
{
    Job *current = jobHead;

    if (current == NULL)
    {
        printf("\nNo job records available.\n");
        return;
    }

    printf("\n========== JOB DETAILS ==========\n");

    while (current != NULL)
    {
        printf("\nJob ID              : %d", current->jobId);
        printf("\nJob Title           : %s", current->jobTitle);
        printf("\nRequired Skills     : %s", current->requiredSkills);
        printf("\nRequired Experience : %.1f years\n",
               current->requiredExperience);
        printf("----------------------------------\n");

        current = current->next;
    }
}
