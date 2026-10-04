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

## Menu (main.c) and validation (validation.c) - owner: Student 6
First test (menu with placeholders)
| ID | Test | Result |
|----|------|--------|
| M1 | Choices 1 and 3 | PASS |
| M2 | 0, 7, -1 | PASS (error, asks again) |
| M3 | abc | PASS (error, asks again) |
| M4 | Empty input | PASS (error, asks again) |
| M5 | Exit (6) | PASS |
| M6 | Options 1-5 call real modules | FAIL: placeholders only |

Re-test (4 October, commit 581d199)
| ID | Test | Result |
|----|------|--------|
| M6b | Options 1-5 open the real modules and sub-menus | PASS |

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

## Reports (reports.c) - owner: Student 5 (commits 2240c1b, d933f30)
| ID | Test | Result |
|----|------|--------|
| R1 | Compiles with strict flags | PASS |
| R2 | Employee report: salaries 20000, 15000, 40000 | PASS: average 25000, highest 40000, lowest 15000 |
| R3 | Budget report | PASS: totals, remaining, over-budget department listed |
| R4 | Supplier and asset reports | PASS |
| R5 | All reports with no data | PASS: "No ... registered" |

## Integration (4 October 2026, commit 581d199)
| ID | Test | Result |
|----|------|--------|
| I2 | All 7 .c files built together with strict flags | PASS: no warnings |
| I3 | Menu options 1-5 open the real modules | PASS |
| I4 | Menu: 0, 9, letters, empty input | PASS: error shown, asks again |
| I5 | Employees: duplicate ID, letters, search | PASS |
| I6 | Budget: "Health Dept" 50000 allocated, 60000 spent | PASS: EXCEEDED, 10000.00 over |
| I7 | Suppliers and Assets: add, display, search | PASS |
| I8 | Employee report: 20000, 15000, 40000 | PASS: average 25000, highest 40000, lowest 15000 |
| I9 | Budget, supplier and asset reports | PASS |
| I10 | All reports with no data | PASS: "No ... registered" |
| I11 | Capacity: 10 suppliers, 100 assets, 100 employees | PASS: "full" message, no crash |
| I12 | Very long and invalid input, run with memory checks on | PASS: rejected, no crash |
| I13 | Full run on the tester's own PC | PASS |

## Issues still open
None.

