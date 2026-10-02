# MFMS Test Log

Tester: Redemptus Muyeu (223124249), Student 7
Date: 2 October 2026
Strict build flags: -std=c99 -Wall -Wextra -pedantic
Only results actually observed are recorded as PASS or FAIL.

## Employees (employees.c + test_employee.c) - owner: Student 1
| ID | Test | Result |
|----|------|--------|
| E1 | Add valid employee | PASS |
| E5 | Display | PASS |
| E6 | Search found | PASS |
| E7 | Search not found | PASS |
| E8 | Salary total (40000+20000+15000 = 75000) | PASS |
| -  | Search with no employees | PASS |
| E4 | Duplicate ID | FAIL: second ID 1 accepted |
| X2 | Text typed for ID | FAIL: name and department prompts skipped |

## Menu (main.c + validation.c) - owner: Student 6
Build: PASS, no warnings
| ID | Test | Result |
|----|------|--------|
| M1 | Choices 1 and 3 | PASS |
| M2 | 0, 7, -1 | PASS (error, asks again) |
| M3 | abc | PASS (error, asks again) |
| M4 | Empty input | PASS (error, asks again) |
| M5 | Exit (6) | PASS |
Note: options 1-5 are placeholders and not connected to the modules.

## Suppliers (suppliers.c, built alone) - owner: Student 3
Build: PASS, no warnings
| ID | Test | Result |
|----|------|--------|
| S1 | Add valid | PASS |
| S2 | Empty name | PASS |
| S3 | Display | PASS |
| S4 | Search found and not found | PASS |
| S6 | Search with no suppliers | PASS |
| S7 | Duplicate ID | FAIL: second ID 1 accepted |
| S8 | Letters at menu | FAIL: previous choice reused |

## Integration
| ID | Test | Result |
|----|------|--------|
| I1 | main.c + validation.c + suppliers.c | FAIL: multiple definition of main and displayMenu (suppliers.c defines both) |
| I2 | main.c + validation.c + employees.c | [FILL IN after re-running the build] |
| I3 | Menu options 1-5 call real modules | FAIL: placeholders only |

## Issues to fix
1. suppliers.c has its own main() and displayMenu() (Student 3)
2. Menu not connected to modules (Student 6)
3. Duplicate IDs accepted in employees and suppliers (Students 1, 3)
4. Input not checked for letters in employees and suppliers; validation.c readInt/readDouble can be used (Students 1, 3)

## Not yet in the repo
budget.c, assets.c, reports.c (Students 2, 4, 5)

## Not yet tested
Employee: empty department, ID of 0 or below.
Supplier: 
Budget, assets and reports once they exist 