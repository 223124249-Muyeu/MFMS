# Municipal Financial Management System (MFMS)
**Project A:** Foundation System (PAP521S Programming in Practice)

## Group members and responsibilities
| Student | Full name | Student number | Responsibility | Status |
|---------|-----------|----------------|----------------|--------|
| 1 | Tatetala Kashango | 225176130 | Employee Management | Submitted |
| 2 | Sakaria Shimbonde | 220081786 | Budget Management | Submitted |
| 3 | Johannes Ndeulita | 225146509 | Supplier Management | Submitted |
| 4 | Sarty Shidolo | 224021559 | Asset Management | Submitted |
| 5 | Quincy Muetudhana | 224082442 | Reports | Submitted |
| 6 | Andreas Mbundu | 224065130 | Functions, integration and validation | Submitted |
| 7 | Redemptus Muyeu | 223124249 | Testing, documentation and Git coordination | Submitted |

## Description
A menu-driven console application for a municipality.
It manages employees, budgets, suppliers and assets, and produces reports.

## Features
- Main menu with input validation (invalid, empty and out-of-range choices are rejected)
- Employees: add, display, search, salary calculation, duplicate ID check
- Budgets: add department budget, enter expenditure, display, list over-budget departments
- Suppliers: add, display, search
- Assets: add, display, search
- Reports: employee, budget, supplier and asset reports

## Project status
- All modules are connected to the main menu and the program builds with no warnings.
- Test results are recorded in TESTING.md.
- Known limit: the supplier list holds 10 records.

## Compilation
Requires GCC.

    gcc -std=c99 -Wall -Wextra -pedantic main.c validation.c employees.c suppliers.c budget.c assets.c reports.c -o mfms

## How to run
Windows: mfms.exe
Linux/macOS: ./mfms

## Testing
See TESTING.md for the test log. test_validation.c is a small program that tests the input helpers in validation.c:

    gcc -std=c99 -Wall -Wextra -pedantic test_validation.c validation.c -o testval