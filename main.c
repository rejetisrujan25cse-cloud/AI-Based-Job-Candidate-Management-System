#include <stdio.h>
#include "candidate.h"
#include "job.h"
#include "search.h"
#include "ranking.h"
#include "shortlist.h"

int main(void)
{
    int choice;

    do
    {
        printf("\n\n==============================================");
        printf("\n       AI JOB CANDIDATE MANAGEMENT SYSTEM");
        printf("\n==============================================");

        printf("\n1. Register Candidate");
        printf("\n2. Register Job");
        printf("\n3. Display Candidates");
        printf("\n4. Display Jobs");
        printf("\n5. Search Candidate");
        printf("\n6. Search by Skill");
        printf("\n7. Rank Candidates");
        printf("\n8. Shortlist Candidates");
        printf("\n9. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                registerCandidate();
                break;

            case 2:
                registerJob();
                break;

            case 3:
                displayCandidates();
                break;

            case 4:
                displayJobs();
                break;

            case 5:
                searchCandidate();
                break;

            case 6:
                searchBySkill();
                break;

            case 7:
                candidateRanking();
                break;

            case 8:
                shortlistedCandidates();
                break;

            case 9:
                printf("\nExiting the system...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}
