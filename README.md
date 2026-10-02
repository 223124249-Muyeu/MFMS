Municipal Financial Management System (MFMS)
**Project A:** Foundation System

## Group members and responsibilities
| Student | Student number | Responsibility                              | Status                                |
|---------|----------------|---------------------------------------------|---------------------------------------|
| 1       | 225176130      | Employee Management                         | Submitted                             |
| 2       | 220081786      | Budget Management                           | Not yet submitted                     |
| 3       | 225146509      | Supplier Management                         | Submitted                             |
| 4       | 224021559      | Asset Management                            | Not yet submitted                     |
| 5       | 224082442      | Reports                                     | Not yet submitted                     |
| 6       | 224065130      | Functions, integration and validation       | Partly submitted (menu and validation)|
| 7       | 223124249      | Testing, documentation and Git coordination | Submitted (README, TESTING.md)        |

## Description
A menu-driven console application for a municipality.
It manages employees, budgets, suppliers and assets, and produces reports.

## Features
- Main menu with input validation
- Employees: add, display, search, salary calculation
- Suppliers: add, display, search
- Budgets, assets and reports: not yet submitted

## Project status
- Menu options 1-5 are not yet connected to their modules.
- suppliers.c currently defines its own main() and cannot be linked with main.c.
- Known issues are recorded in TESTING.md.

## Compilation
Requires GCC.

    gcc -std=c99 -Wall -Wextra -pedantic main.c validation.c employees.c -o mfms

Other modules will be added to this command once they are integrated.

## How to run
Windows: mfms.exe
Linux/macOS: ./mfms

## Testing
See TESTING.md for the test log.