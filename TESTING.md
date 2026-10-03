# MFMS Test Log

Tester: Redemptus Muyeu (223124249), Student 7
Date: 2-4 October 2026
Strict build flags: -std=c99 -Wall -Wextra -pedantic
Only results actually observed are recorded as PASS or FAIL.

## Employees (employees.c) - owner: Student 1
First test (2 October)
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

Re-test (4 October, commit 8900bec)
| ID | Test | Result |
|----|------|--------|
| E4b | Duplicate ID | PASS: "ID 101 is already used", asks again |
| X2b | Letters typed for ID | PASS: "please enter a whole number", asks again |
| E9 | Negative or letter salary | PASS: both rejected |
| E8b | Salary total (40000+20000+15000) | PASS: 75000.00 |
| E10 | No scanf or getchar left in the module | PASS: uses readInt, readString, readDouble |
Note: the old test_employee.c still reads its own menu with scanf, so it can show "input cannot be empty" after a menu choice. This affects only that test file, not employees.c.

## Menu (main.c + validation.c) - owner: Student 6
Build: PASS, no warnings
| ID | Test | Result |
|----|------|--------|
| M1 | Choices 1 and 3 | PASS |
| M2 | 0, 7, -1 | PASS (error, asks again) |
| M3 | abc | PASS (error, asks again) |
| M4 | Empty input | PASS (error, asks again) |
| M5 | Exit (6) | PASS |
Note: options 1-5 are placeholders and are not connected to the modules.

## Validation helpers (validation.c, tested with test_validation.c) - Student 6 / Student 7
| ID | Test | Result |
|----|------|--------|
| V1 | readInt: 5 | PASS: accepted |
| V2 | readInt: 0 and 11 | PASS: "enter a number between 1 and 10" |
| V3 | readInt: abc and 3.5 | PASS: "please enter a whole number" |
| V4 | readInt: empty line | PASS: "input cannot be empty" |
| V5 | readDouble: negative number and letters | PASS: both rejected |
| V6 | readString: empty and too-long text | PASS: both rejected |

## Suppliers (suppliers.c) - owner: Student 3
First test
| ID | Test | Result |
|----|------|--------|
| S1 | Add valid | PASS |
| S2 | Empty name | PASS |
| S3 | Display | PASS |
| S4 | Search found and not found | PASS |
| S6 | Search with no suppliers | PASS |
| S7 | Duplicate ID | FAIL: second ID 1 accepted |
| S8 | Letters at menu | FAIL: previous choice reused |
| I1 | Linked with main.c | FAIL: multiple definition of main and displayMenu |

Re-test (3 October, after Student 3's update)
| ID | Test | Result |
|----|------|--------|
| S7b | Duplicate ID | PASS: "Supplier ID already exists", asks again |
| S8b | Letters typed for ID | PASS: asks again (now uses readInt) |
| I1b | Linked with main.c | PASS: main() clash removed |
Note: suppliers.c now needs validation.c to link.

## Budget (budget.c) - owner: Student 2
First test: build FAIL (missing closing brace at the end of loadBudgetsFromFile)
Logic tested on a scratch copy with that one brace added:
| ID | Test | Result |
|----|------|--------|
| B1 | Expenditure over the allocation | PASS: EXCEEDED |
| B2 | Over-budget list, totals | PASS |
| B4 | Duplicate and empty department name | PASS: rejected |
| B6 | Name typed after a menu choice | FAIL: getchar() removed the first letter ("Health" stored as "ealth") |
| B7 | Letters typed for amount | FAIL: scanf failed silently, wrong message |

Re-test (3 October, commit 9c90290)
| ID | Test | Result |
|----|------|--------|
| B0 | Compiles with strict flags | PASS |
| B6b | Name with a space ("Health Dept") | PASS: kept intact |
| B7b | Letters typed for amount | PASS: "please enter a valid number", asks again |
| B8 | 50000 allocated, 60000 spent | PASS: EXCEEDED, 10000.00 over |

## Assets (assets.c) - owner: Student 4
First test: build PASS
| ID | Test | Result |
|----|------|--------|
| A1 | Link a caller that uses searchAssets() | FAIL: header said searchAssets, code defined searchAsset |
| A2 | Add an asset | FAIL: no add function existed |

Re-test (3 October, commit ea0f0aa)
| ID | Test | Result |
|----|------|--------|
| A1b | Function names match | PASS |
| A2b | Add an asset, duplicate ID rejected | PASS |
| A3 | Display, search found and not found | PASS |
| A4 | Letters typed for an ID | PASS: asks again |

## Integration
| ID | Test | Result |
|----|------|--------|
| I2 | main, validation, employees, suppliers, budget, assets built together | PASS: no warnings |
| I3 | Menu options 1-5 call real modules | FAIL: placeholders only (Student 6) |
| I4 | Reports module present | FAIL: reports.c not yet submitted (Student 5) |

## Issues still open
1. Menu options 1-5 are not connected to the modules (Student 6).
2. reports.c has not been submitted (Student 5).
