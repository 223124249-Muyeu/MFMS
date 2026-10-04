Municipal Financial Management System (MFMS)
**Project A:** Foundation System

## Group members and responsibilities
| Student | Student number | Responsibility                              | Status                                |
|---------|----------------|---------------------------------------------|---------------------------------------|
| 1       | 225176130      | Employee Management                         | Submitted (input fixes included)      |
| 2       | 220081786      | Budget Management                           | Submitted (build fixed)               |
| 3       | 225146509      | Supplier Management                         | Submitted (updated)                   |
| 4       | 224021559      | Asset Management                            | Submitted (updated)                   |
| 5       | 224082442      | Reports                                     | Not yet submitted                     |
| 6       | 224065130      | Functions, integration and validation       | Partly submitted (menu and validation)|
| 7       | 223124249      | Testing, documentation and Git coordination | README, TESTING.md, test_validation.c |

## Description
A menu-driven console application for a municipality.
It manages employees, budgets, suppliers and assets, and produces reports.

## Features
- Main menu with input validation (invalid, empty and out-of-range choices are rejected)
- Employees: add, display, search, salary calculation, duplicate ID check
- Budgets: add department budget, enter expenditure, display, list over-budget departments
- Suppliers: add, display, search
- Assets: add, display, search
- Reports: not yet submitted

## Project status
- All submitted modules compile together with no warnings.
- Menu options 1-5 are not yet connected to their modules.
- reports.c has not been submitted.
- Test results and known limits are recorded in TESTING.md.

## Compilation
Requires GCC.

    gcc -std=c99 -Wall -Wextra -pedantic main.c validation.c employees.c suppliers.c budget.c assets.c -o mfms

reports.c will be added to this command once it is submitted.

## How to run
Windows: mfms.exe
Linux/macOS: ./mfms

## Testing
See TESTING.md for the test log. test_validation.c is a small program that tests the input helpers in validation.c:

    gcc -std=c99 -Wall -Wextra -pedantic test_validation.c validation.c -o testval