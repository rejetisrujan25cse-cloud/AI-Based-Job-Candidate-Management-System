# AI-Based Job Candidate Management System

## Description
A C-based mini project for managing candidate and job profiles using
linked lists, searching, sorting, and a simple matching-score mechanism.

## Modules
1. Candidate Registration
2. Job Registration
3. Candidate Display
4. Job Display
5. Candidate Search
6. Skill Search
7. Candidate Ranking
8. Candidate Shortlisting

## Data Structures
- Linked List for candidate records
- Linked List for job records
- Array + Bubble Sort for candidate ranking

## Matching Score
- Skill matching: 70 marks
- Experience matching: 30 marks
- Total: 100 marks

## Files
- `main.c`
- `candidate.h`
- `candidate.c`
- `job.h`
- `job.c`
- `search.h`
- `search.c`
- `ranking.h`
- `ranking.c`
- `shortlist.h`
- `shortlist.c`

## Compile
```bash
gcc main.c candidate.c job.c search.c ranking.c shortlist.c -o job_system
```

## Run
```bash
./job_system
```

On Windows MinGW:
```bash
job_system.exe
```
