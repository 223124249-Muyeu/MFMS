# MFMS Test Log

Tester: Redemptus Muyeu (223124249), Student 7
Date: 2-3 October 2026
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

### Suppliers re-test (3 October 2026, after Student 3's update)
| ID | Test | Result |
|----|------|--------|
| S7b | Duplicate ID | PASS: "Supplier ID already exists" shown, asks again |
| S8b | Letters typed for ID | PASS: "please enter a whole number", asks again (now uses readInt) |
Note: suppliers.c now needs validation.c to link.

## Budget (budget.c) - owner: Student 2 
Build: FAIL: missing closing brace at end of loadBudgetsFromFile ("expected declaration or statement at end of input")
Tests below were run on a scratch copy with only that one brace added; the repo file was not changed.
| ID | Test | Result |
|----|------|--------|
| B1 | Add department, then expenditure over the allocation | PASS: remaining -59000.00, status EXCEEDED |
| B2 | Over-budget list | PASS: "Health exceeded by 59000.00" |
| B3 | Totals (allocated, expenditure, count) | PASS |
| B4 | Duplicate department name | PASS: rejected |
| B5 | Empty department name | PASS: rejected |
| B6 | Name typed after a menu choice | FAIL: getchar() before fgets removes the first letter ("Health" stored as "ealth") |
| B7 | Letters typed for amount | FAIL: scanf fails silently, wrong message "No negative salary/budget!" |

## Assets (assets.c) - owner: Student 4 
Build: PASS, no warnings
| ID | Test | Result |
|----|------|--------|
| A1 | Link a caller that uses searchAssets() | FAIL: undefined reference (assets.h declares searchAssets, assets.c defines searchAsset) |
| A2 | Add an asset | FAIL: no add function exists |
| A3 | Search input uses raw scanf | Not yet tested; same risk as employees |

## Integration
| ID | Test | Result |
|----|------|--------|
| I1 | main.c + validation.c + suppliers.c | PASS (re-test 3 Oct): main() clash removed, links with no warnings |
| I2 | main.c + validation.c + employees.c | PASS: links with no warnings (employees not yet called from the menu) |
| I3 | Menu options 1-5 call real modules | FAIL: placeholders only |
| I4 | All modules together (main, validation, employees, suppliers, assets, budget) | PASS only with the budget.c brace added on a scratch copy; the repo version does not compile |

## Issues to fix
1. budget.c: add the missing closing brace (Student 2)
2. budget.c: remove getchar() before fgets in enterBudget and enterExpenditure; use readDouble for amounts (Student 2)
3. assets.c / assets.h: make searchAsset and searchAssets the same name; add an addAsset function (Student 4)
4. Menu not connected to modules (Student 6)
5. Duplicate IDs accepted in employees (Student 1); fixed in suppliers
6. Input not checked for letters in employees (Student 1); fixed in suppliers

## Not yet in the repo
reports.c (Student 5)

## Not yet tested
Employee and supplier input after the menu is connected.
Reports once it exists.
